/*
  ==============================================================================
    OctopushAudioEngine.cpp
    Created: 25 Oct 2019 4:14:04pm
    Author:  Frederic Font Corbera
  ==============================================================================
*/

#include "OctopushAudioEngine.h"
#include "Utilities.h"  // Tracktion engine utilities

OctopushAudioEngine::OctopushAudioEngine()
{
}
   
OctopushAudioEngine::~OctopushAudioEngine()
{
    std::cout << "OctopushAudioEngine destructor called..." << std::endl;
    
    // Stop timer
    //stopTimer();
    
    // Shot down tracktion engine stuf
    engine->getTemporaryFileManager().getTempDirectory().deleteRecursively();
    
    // Remove action listeners of OctopushAudioEngine
    std::cout << "Removing OctopushAudioEngine action listeners..." << std::endl;
    removeAllActionListeners();
    
    // Release pointers
    std::cout << "Releasing OctopushAudioEngine pointers..." << std::endl;
    transport.release();
    edit.release();
    engine.release();
}

void OctopushAudioEngine::setupInputs (te::Edit& edit)
{
    auto& dm = edit.engine.getDeviceManager();
    
    
    // Configure midi inputs
    for (int i = 0; i < dm.getNumMidiInDevices(); i++)
    {
        auto dev = dm.getMidiInDevice (i);
        dev->setEnabled (true);
        dev->setEndToEndEnabled (true);
    }
    
    edit.playInStopEnabled = true;
    edit.getTransport().ensureContextAllocated (true);

    /*
    // Add the midi input to track 1
    if (auto t = EngineHelpers::getOrInsertAudioTrackAt (edit, 0))
        if (auto dev = dm.getMidiInDevice (0))
            for (auto instance : edit.getAllInputDevices())
                if (&instance->getInputDevice() == dev)
                    instance->setTargetTrack (*t, 0, true);

    // Also add the same midi input to track 2
    if (auto t = EngineHelpers::getOrInsertAudioTrackAt (edit, 1))
        if (auto dev = dm.getMidiInDevice (0))
            for (auto instance : edit.getAllInputDevices())
                if (&instance->getInputDevice() == dev)
                    instance->setTargetTrack (*t, 0, false);
     */
    
    
    // Configure audio inputs
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

    edit.restartPlayback();
}

void OctopushAudioEngine::setupOutputs (te::Edit& edit)
{
    auto& dm = edit.engine.getDeviceManager();

    // Configure midi outputs
    for (int i = 0; i < dm.getNumMidiOutDevices(); i++)
    {
        auto dev = dm.getMidiOutDevice (i);
        dev->setEnabled (true);
    }

    edit.playInStopEnabled = true;
    edit.getTransport().ensureContextAllocated (true);

    /*
    // Set track 2 to send to midi output
    if (auto t = EngineHelpers::getOrInsertAudioTrackAt (edit, 1))
    {
        auto& output = t->getOutput();
        output.setOutputToDefaultDevice (true);
    }
     */

    edit.restartPlayback();
}

void OctopushAudioEngine::initialize(te::Engine* _engine, te::Edit* _edit, bool playOnStart, int stateUpdateRate, bool minimal)
{
    std::cout << "* Initializing OctopushAudioEngine" << std::endl;
    
    // Init tracktion engine variables
    engine.reset(_engine);
    edit.reset(_edit);
    transport.reset(&edit->getTransport());
    
    // Not sure why I'm doing this stuff here...
    //edit->playInStopEnabled = true;
    //transport->ensureContextAllocated (true);
    //edit->restartPlayback();
    setupInputs(*edit.get());
    setupOutputs(*edit.get());
    
    // Create all audio tracks and link level meters
    
    int currentTrackNum = 0;
    int nAudioTracks = N_AUDIO_TRACKS;
    if (minimal){
        nAudioTracks = 1;
    }
    
    /*for (int index=0; index<nAudioTracks; index++){
        auto track = EngineHelpers::getOrInsertAudioTrackAt (*edit.get(), index);
        trackLevelClients[index] = new te::LevelMeasurer::Client();
        track->getLevelMeterPlugin()->measurer.setMode(te::LevelMeasurer::Mode::RMSMode);
        track->getLevelMeterPlugin()->measurer.addClient(*trackLevelClients[index]);
    }*/
    
    // Now add content to every track
    
    // Track 0 (loop)
    if (auto track = EngineHelpers::getOrInsertAudioTrackAt (*edit.get(), currentTrackNum)){
        auto f = File::createTempFile ("tambourine.wav");
        f.replaceWithData (BinaryData::tambourine_wav, BinaryData::tambourine_wavSize);
        te::AudioFile audioFile (*engine.get(), f);
        auto clip = track->insertWaveClip (f.getFileNameWithoutExtension(), f, { { 0.0, audioFile.getLength() }, 0.0 }, false);
        
        
        // Add reverb plugin to track
        if (auto reverb = dynamic_cast<te::ReverbPlugin*> (edit->getPluginCache().createNewPlugin (te::ReverbPlugin::xmlTypeName, {}).get()))
        {
            track->pluginList.insertPlugin (*reverb, 0, nullptr);
            reverb->setRoomSize(state.reverberationRoomSize);
        }
    
        
        currentTrackNum++;
    }
    
    // Track 1 (loop)
    if (auto track = EngineHelpers::getOrInsertAudioTrackAt (*edit.get(), currentTrackNum)){
        auto f = File::createTempFile ("loop1.wav");
        f.replaceWithData (BinaryData::_262218__jputman__simpleloop_wav, BinaryData::_262218__jputman__simpleloop_wavSize);
        te::AudioFile audioFile (*engine.get(), f);
        auto clip = track->insertWaveClip (f.getFileNameWithoutExtension(), f, { { 0.0, audioFile.getLength() }, 0.0 }, false);
        
        // Add plugins
        if (auto reverb = dynamic_cast<te::ReverbPlugin*> (edit->getPluginCache().createNewPlugin (te::ReverbPlugin::xmlTypeName, {}).get()))
        {
            track->pluginList.insertPlugin (*reverb, 0, nullptr);
            reverb->setRoomSize(state.reverberationRoomSize);
        }
        
        currentTrackNum++;
    }
    
    // Track 2 (loop)
    if (auto track = EngineHelpers::getOrInsertAudioTrackAt (*edit.get(), currentTrackNum)){
        auto f = File::createTempFile ("loop2.wav");
        f.replaceWithData (BinaryData::_418621__realdavidfloat__basslinec120bpm_wav, BinaryData::_418621__realdavidfloat__basslinec120bpm_wavSize);
        te::AudioFile audioFile (*engine.get(), f);
        auto clip = track->insertWaveClip (f.getFileNameWithoutExtension(), f, { { 0.0, audioFile.getLength() }, 0.0 }, false);
        
        // Add plugins
        if (auto reverb = dynamic_cast<te::ReverbPlugin*> (edit->getPluginCache().createNewPlugin (te::ReverbPlugin::xmlTypeName, {}).get()))
        {
            track->pluginList.insertPlugin (*reverb, 0, nullptr);
            reverb->setRoomSize(state.reverberationRoomSize);
        }
        
        currentTrackNum++;
    }
    
    // Track 3 (loop)
    if (auto track = EngineHelpers::getOrInsertAudioTrackAt (*edit.get(), currentTrackNum)){
        auto f = File::createTempFile ("loop3.wav");
        f.replaceWithData (BinaryData::_418743__realdavidfloat__hihatloop120bpm0102_wav, BinaryData::_418743__realdavidfloat__hihatloop120bpm0102_wavSize);
        te::AudioFile audioFile (*engine.get(), f);
        auto clip = track->insertWaveClip (f.getFileNameWithoutExtension(), f, { { 0.0, audioFile.getLength() }, 0.0 }, false);
        
        // Add plugins
        if (auto reverb = dynamic_cast<te::ReverbPlugin*> (edit->getPluginCache().createNewPlugin (te::ReverbPlugin::xmlTypeName, {}).get()))
        {
            track->pluginList.insertPlugin (*reverb, 0, nullptr);
            reverb->setRoomSize(state.reverberationRoomSize);
        }
        
        currentTrackNum++;
    }
    
   
    if (!minimal){
        
        // Track 4 (step sequencer)
        if (auto track = EngineHelpers::getOrInsertAudioTrackAt (*edit.get(), currentTrackNum))
        {
           // Find length of 1 bar
           const te::EditTimeRange editTimeRange (0, edit->tempoSequence.barsBeatsToTime ({ 0, 4.0 }));
           track->insertNewClip (te::TrackItem::Type::step, "Step Clip", editTimeRange, nullptr);
           auto stepClip = dynamic_cast<te::StepClip*> (track->getClips()[0]);
           // Remove channels from step sequencer to reduce it to 4 instead of the default 8
           stepClip->removeChannel(4);
           stepClip->removeChannel(4);
           stepClip->removeChannel(4);
           stepClip->removeChannel(4);
           
           setTrackVolume(4, -8.0); // Set volume to -8 db
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
        if (auto sampler = dynamic_cast<te::SamplerPlugin*> (edit->getPluginCache().createNewPlugin (te::SamplerPlugin::xmlTypeName, {}).get()))
        {
           auto track = EngineHelpers::getOrInsertAudioTrackAt (*edit.get(), currentTrackNum);
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
       
    
        // Tracks 5-6 (route audio input)
        int nInputTracks = 0;
        int maxInputTracks = 2;
        for (auto instance : edit->getAllInputDevices())
        {
            std::cout << instance->getInputDevice().getName() << std::endl;
            
            if (nInputTracks == maxInputTracks){
                break;
            }
            
            if (instance->getInputDevice().getDeviceType() == te::InputDevice::waveDevice)
            {
                if (auto t = EngineHelpers::getOrInsertAudioTrackAt (*edit.get(), currentTrackNum))
                {
                    instance->setTargetTrack (*t, 0, false);
                    instance->setRecordingEnabled (*t, true);
                    currentTrackNum++;
                    nInputTracks++;
                }
            }
        }
        edit->restartPlayback();
        
        // Mute tracks 5-6 to avoid feedback loop if input is microphone and output are speakers
        toggleMuteTrack(5);
        toggleMuteTrack(6);
    }
    
    // Print info about created tracks
    std::cout << te::getAudioTracks(*edit.get()).size() << " Tracks created" << std::endl;
    for (auto track : te::getAudioTracks(*edit.get())){
        std::cout << "- " << track->getName() << std::endl;
    }
    
    // Initialize other transport and related properties
    edit->tempoSequence.getTempos()[0]->setBpm (state.tempo);
    transport->setLoopRange (te::EditTimeRange(0.0, 4.0)); // Will this be 1 bar (?)
    transport->looping = true;
    transport->position = 0.0;
    transport->addChangeListener (this);
    
    // If play, start playing
    std::cout << "PLAY on start? " << playOnStart <<std::endl;
    if (playOnStart){
        transportPlay();
    }

    // Start the timer to update state
    if (stateUpdateRate > 0){
        //startTimerHz(stateUpdateRate);
    } else {
        std::cout << "WARNING: state update timer is disabled" << std::endl;
    }
}

void OctopushAudioEngine::changeListenerCallback (ChangeBroadcaster*)
{
    // Do nothing, this is here to comply with ChangeListener protocol
}

void OctopushAudioEngine::transportPlay(){
    transport->play(false);
    state.isPlaying = true;
}

void OctopushAudioEngine::transportStop(){
    transport->stop(false, false);
    state.isPlaying = false;
}

void OctopushAudioEngine::transportTogglePlayStop(){
    if (transport->isPlaying()){
        transportStop();
    } else {
        transportPlay();
    }
}

void OctopushAudioEngine::setTrackVolume(int trackNum, float volume){
    const MessageManagerLock mmLock;  // Not sure why this is needed here but otherwise it would throw exceptions when called from rating an encoder from real Push (not from simulator)
    state.audioTrackSettings[trackNum].volume = volume;
    auto track = te::getAudioTracks(*edit.get())[trackNum];
    track->getVolumePlugin()->setVolumeDb(volume);
}

void OctopushAudioEngine::toggleMuteTrack(int trackNum){
    auto track = te::getAudioTracks(*edit.get())[trackNum];
    if (track->isMuted(false)){
        track->setMute(false);
    } else {
        track->setMute(true);
    }
    state.audioTrackSettings[trackNum].mute = track->isMuted(false);
}

void OctopushAudioEngine::updateStepSequencerPattern(int samplerChannel, int stepN){
    // Toggle on/off for the selected channel/step
    state.stepSequencerPattern[samplerChannel][stepN] = !state.stepSequencerPattern[samplerChannel][stepN];
    
    // Reload pattern to step sequencer clip
    auto track = EngineHelpers::getOrInsertAudioTrackAt (*edit.get(), 1);  // 1 = step sequencer track
    
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

void OctopushAudioEngine::setReverberationRoomSize(float roomSize)
{
    // Get track 0 which has a reverberation plugin and update it's room size parameter
    // NOTE: in the future there should be a more generic way to set plugin parameters,
    // specify tracks and also save their values in the state
    auto track = EngineHelpers::getOrInsertAudioTrackAt (*edit.get(), 0);  // 0 = sample + plugin
    auto reverb = dynamic_cast<te::ReverbPlugin*> (track->pluginList.getPluginsOfType<te::ReverbPlugin>().getLast());
    reverb->setRoomSize(roomSize);
}

/*void OctopushAudioEngine::timerCallback()
{
    // Update state variables that change over time like transport position
    
    // Set current step position and proportion
    auto loopRange = transport->getLoopRange();
    if (loopRange.isEmpty()) {
        state.currentStepPosition = 0.0;
        state.currentStepProportion = 0.0;
    } else {
        const double position = transport->position;
        const auto proportion = position / loopRange.getEnd();
        state.currentStepPosition = position;
        state.currentStepProportion = proportion;
    }
    
    // Save measured track levels to state
    for (int index = 0; index<te::getAudioTracks(*edit.get()).size(); index++){
        state.audioTrackSettings[index].measuredLevel = trackLevelClients[index]->getAndClearAudioLevel(0).dB;
    }
    
    // Measure state update rate and save it to state
    stateUpdateRateCounter += 1;
    if (stateUpdateRateCurrentSecond == 0){
        // Init variables
        stateUpdateRateCurrentSecond = Time::getCurrentTime().toMilliseconds();
    } else {
        int64 currentTime = Time::getCurrentTime().toMilliseconds();
        if (currentTime - stateUpdateRateCurrentSecond > 1000.0){
            stateUpdateRateCurrentSecond = currentTime;
            state.stateUpdateFrameRate = stateUpdateRateCounter;
            stateUpdateRateCounter = 0;
            std::cout << "State updates per second: " << state.stateUpdateFrameRate << std::endl;
        }
    }
}*/
