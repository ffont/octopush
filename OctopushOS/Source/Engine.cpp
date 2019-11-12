/*
  ==============================================================================

    Engine.cpp
    Created: 25 Oct 2019 4:14:04pm
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#include "Engine.h"
#include "../JuceLibraryCode/BinaryData.h"
#include "helpers/tracktion_engine.h"

Engine::Engine()
{
}
   
Engine::~Engine()
{
    // Shot down tracktion engine stuf
    engine.getTemporaryFileManager().getTempDirectory().deleteRecursively();    
    
    // Remove action listeners of Engine
    removeAllActionListeners();

}

void Engine::initialize()
{
    //------------- Configure input devices
    auto& dm = engine.getDeviceManager();
    
    for (int i = 0; i < dm.getNumWaveInDevices(); i++)
        if (auto wip = dm.getWaveInDevice (i))
            wip->setStereoPair (false);  // Don't make input devices stereo
    
    for (int i = 0; i < dm.getNumWaveInDevices(); i++)
    {
        if (auto wip = dm.getWaveInDevice (i))  // Enable all iputs
        {
            wip->setEndToEnd (true);  // Enable input monitoring
            wip->setEnabled (true);
        }
    }
    edit.playInStopEnabled = true; // Needed to make input devices reachable even if not playing
    edit.restartPlayback();
    
    //------------- Create all audio tracks and link level meters
    int currentTrackNum = 0;
    for (int index=0; index<N_AUDIO_TRACKS; index++){
        auto track = EngineHelpers::getOrInsertAudioTrackAt (edit, index);
        trackLevelClients[index] = te::LevelMeasurer::Client();
        track->getLevelMeterPlugin()->measurer.setMode(te::LevelMeasurer::Mode::RMSMode);
        track->getLevelMeterPlugin()->measurer.addClient(trackLevelClients[index]);
    }
    
    //------------- Now add content to every track
    
    //------------- Track 0 (add file)
    if (auto track = EngineHelpers::getOrInsertAudioTrackAt (edit, currentTrackNum)){
        auto f = File::createTempFile ("tambourine.wav");
        f.replaceWithData (BinaryData::tambourine_wav, BinaryData::tambourine_wavSize);
        te::AudioFile audioFile (f);
        auto clip = track->insertWaveClip (f.getFileNameWithoutExtension(), f, { { 0.0, audioFile.getLength() }, 0.0 }, false);
        
        // Add reverb plugin to track
        if (auto reverb = dynamic_cast<te::ReverbPlugin*> (edit.getPluginCache().createNewPlugin (te::ReverbPlugin::xmlTypeName, {}).get()))
        {
            track->pluginList.insertPlugin (*reverb, 0, nullptr);
            reverb->setRoomSize(state.reverberationRoomSize);
        }
        
        currentTrackNum++;
    }
    
    //------------- Track 1 (step sequencer)
    
    // Create track for step sequencer
    if (auto track = EngineHelpers::getOrInsertAudioTrackAt (edit, currentTrackNum))
    {
        // Find length of 1 bar
        const te::EditTimeRange editTimeRange (0, edit.tempoSequence.barsBeatsToTime ({ 0, 4.0 }));
        track->insertNewClip (te::TrackItem::Type::step, "Step Clip", editTimeRange, nullptr);
        auto stepClip = dynamic_cast<te::StepClip*> (track->getClips()[0]);
        // Remove channels from step sequencer to reduce it to 4 instead of the default 8
        stepClip->removeChannel(4);
        stepClip->removeChannel(4);
        stepClip->removeChannel(4);
        stepClip->removeChannel(4);
    }
    
    // Load audio files that will be used by a sampler plugin receiving notes from the step sequencer
    Array<File> files;
    auto kickFile = File::createTempFile ("kick.wav");
    kickFile.replaceWithData (BinaryData::kick_wav, BinaryData::kick_wavSize);
    files.add (kickFile);
    auto snareFile = File::createTempFile ("snare.aiff");
    snareFile.replaceWithData (BinaryData::snare_aiff, BinaryData::snare_aiffSize);
    files.add (snareFile);
    auto hihatFile = File::createTempFile ("hihat.wav");
    hihatFile.replaceWithData (BinaryData::hihat_wav, BinaryData::hihat_wavSize);
    files.add (hihatFile);
    auto clapFile = File::createTempFile ("clap.wav");
    clapFile.replaceWithData (BinaryData::clap_wav, BinaryData::clap_wavSize);
    files.add (clapFile);
    
    // Create sampler plugin with the above clips and create patterns for sampler channels
    if (auto sampler = dynamic_cast<te::SamplerPlugin*> (edit.getPluginCache().createNewPlugin (te::SamplerPlugin::xmlTypeName, {}).get()))
    {
        auto track = EngineHelpers::getOrInsertAudioTrackAt (edit, currentTrackNum);
        auto stepClip = dynamic_cast<te::StepClip*> (track->getClips()[0]);
        stepClip->getTrack()->pluginList.insertPlugin (*sampler, 0, nullptr);
        
        int channelCount = 0;
        for (auto channel : stepClip->getChannels())
        {
            const auto error = sampler->addSound (files[channelCount].getFullPathName(), channel->name.get(), 0.0, 0.0, 1.0f);
            sampler->setSoundParams (sampler->getNumSounds() - 1, channel->noteNumber, channel->noteNumber, channel->noteNumber);
            jassert (error.isEmpty());
            
            for (auto& pattern : stepClip->getPatterns()){
                for (int step=0; step<pattern.getNumNotes(); step++){
                    pattern.setNote (channelCount, step, state.stepSequencerPattern[channelCount][step]);
                }
            }
            channelCount++;
        }
        currentTrackNum++;
    }
    
    //------------- Tracks 2-3 (route audio input)
    int nInputTracks = 0;
    int maxInputTracks = 2;
    for (auto instance : edit.getAllInputDevices())
    {
        std::cout << instance->getInputDevice().getName() << std::endl;
        
        if (nInputTracks == maxInputTracks){
            break;
        }
        
        if (instance->getInputDevice().getDeviceType() == te::InputDevice::waveDevice)
        {
            if (auto t = EngineHelpers::getOrInsertAudioTrackAt (edit, currentTrackNum))
            {
                instance->setTargetTrack (t, 0);
                instance->setRecordingEnabled (true);
                currentTrackNum++;
                nInputTracks++;
            }
        }
    }
    edit.restartPlayback();
    
    // Mute tracks 2-3 to avoid feedback loop if input is microphone and output are speakers
    toggleMuteTrack(2);
    toggleMuteTrack(3);
    
    //------------- Print info about created tracks
    std::cout << te::getAudioTracks(edit).size() << " Tracks created" << std::endl;
    for (auto track : te::getAudioTracks(edit)){
        std::cout << "- " << track->getName() << std::endl;
    }
    
    //------------- Other init stuff
    
    // Initialize other transport and related properties
    edit.tempoSequence.getTempos()[0]->setBpm (state.tempo);
    transport.setLoopRange (te::EditTimeRange(0.0, 4.0)); // Will this be 1 bar (?)
    transport.looping = true;
    transport.position = 0.0;
    transport.addChangeListener (this);

    // Start the timer to update state
    startTimerHz(STATE_UPDATE_RATE);
}

void Engine::changeListenerCallback (ChangeBroadcaster*)
{
    // Do nothing, this is here to comply with ChangeListener protocol
}

void Engine::transportPlay(){
    transport.play(false);
    state.isPlaying = true;
}

void Engine::transportStop(){
    transport.stop(false, false);
    state.isPlaying = false;
}

void Engine::transportTogglePlayStop(){
    if (transport.isPlaying()){
        transportStop();
    } else {
        transportPlay();
    }
}

void Engine::setTrackVolume(int trackNum, float volume){
    const MessageManagerLock mmLock;  // Not sure why this is needed here but otherwise it would throw exceptions when called from rating an encoder from real Push (not from simulator)
    state.audioTrackSettings[trackNum].volume = volume;
    auto track = te::getAudioTracks(edit)[trackNum];
    track->getVolumePlugin()->setVolumeDb(volume);
}

void Engine::toggleMuteTrack(int trackNum){
    auto track = te::getAudioTracks(edit)[trackNum];
    if (track->isMuted(false)){
        track->setMute(false);
    } else {
        track->setMute(true);
    }
    state.audioTrackSettings[trackNum].mute = track->isMuted(false);
}

void Engine::updateStepSequencerPattern(int samplerChannel, int stepN){
    // Toggle on/off for the selected channel/step
    state.stepSequencerPattern[samplerChannel][stepN] = !state.stepSequencerPattern[samplerChannel][stepN];
    
    // Reload pattern to step sequencer clip
    auto track = EngineHelpers::getOrInsertAudioTrackAt (edit, 1);  // 1 = step sequencer track
    
    auto stepClip = dynamic_cast<te::StepClip*> (track->getClips()[0]);
    int channelCount = 0;
    for (auto channel : stepClip->getChannels())
    {
        for (auto& pattern : stepClip->getPatterns()){
            for (int step=0; step<pattern.getNumNotes(); step++){
                pattern.setNote (channelCount, step, state.stepSequencerPattern[channelCount][step]);
            }
        }
        channelCount++;
    }
}

void Engine::setReverberationRoomSize(float roomSize)
{
    // Get track 0 which has a reverberation plugin and update it's room size parameter
    // NOTE: in the future there should be a more generic way to set plugin parameters,
    // specify tracks and also save their values in the state
    auto track = EngineHelpers::getOrInsertAudioTrackAt (edit, 0);  // 0 = sample + plugin
    auto reverb = dynamic_cast<te::ReverbPlugin*> (track->pluginList.getPluginsOfType<te::ReverbPlugin>().getLast());
    std::cout << roomSize << std::endl;
    reverb->setRoomSize(roomSize);
}

void Engine::timerCallback()
{
    // Update state variables that change over time like transport position
    
    // Set current step position and proportion
    auto loopRange = transport.getLoopRange();
    if (loopRange.isEmpty()) {
        state.currentStepPosition = 0.0;
        state.currentStepProportion = 0.0;
    } else {
        const double position = transport.position;
        const auto proportion = position / loopRange.getEnd();
        state.currentStepPosition = position;
        state.currentStepProportion = proportion;
    }
    
    // Save measured track levels to state
    for (int index = 0; index<te::getAudioTracks(edit).size(); index++){
        state.audioTrackSettings[index].measuredLevel = trackLevelClients[index].getAndClearAudioLevel(0).dB;
    }
}
