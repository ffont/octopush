/*
  ==============================================================================

    Engine.cpp
    Created: 25 Oct 2019 4:14:04pm
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#include "Engine.h"
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
    //------------- Load audio file and start playing it in loop. configure level meter.
    auto f = File::createTempFile ("tambourine.wav");
    f.replaceWithData (BinaryData::tambourine_wav, BinaryData::tambourine_wavSize);
    auto clip = EngineHelpers::loadAudioFileAsClip (edit, f); // Will add the audio file as a clip in track #0 of edit
    
    auto track = EngineHelpers::getOrInsertAudioTrackAt (edit, 0);
    track->getLevelMeterPlugin()->measurer.addClient(track0LevelClient);  // TODO: should this be removed?
    
    
    //------------- Get audio input channels and create tracks routed to output
    int trackNum = 1;  // Start at channel 1 as channel 0 is used by the loaded demo audio file
    for (auto instance : edit.getAllInputDevices())
    {
        if (instance->getInputDevice().getDeviceType() == te::InputDevice::waveDevice)
        {
            if (auto t = EngineHelpers::getOrInsertAudioTrackAt (edit, trackNum))
            {
                instance->setTargetTrack (t, 0);
                instance->setRecordingEnabled (true);
                trackNum++;
            }
        }
    }
    edit.restartPlayback();
    
    //------------- Setup the step sequencer
    
    // Create track for step sequencer and make it loop
    edit.tempoSequence.getTempos()[0]->setBpm (state.tempo);
    stepSequencerTrackNum = trackNum + 1;
    if (auto track = EngineHelpers::getOrInsertAudioTrackAt (edit, stepSequencerTrackNum))
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
        
        // Prepare transport to loop around step sequencer clip area
        transport.setLoopRange (stepClip->getEditTimeRange());
        transport.looping = true;
        transport.position = 0.0;
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
        auto track = EngineHelpers::getOrInsertAudioTrackAt (edit, stepSequencerTrackNum);
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
    }
    
    // Start paying arrangement
    // transportPlay();
    
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
    transport.stop(false, true);
    state.isPlaying = false;
}

void Engine::transportTogglePlayStop(){
    if (transport.isPlaying()){
        transportStop();
    } else {
        transportPlay();
    }
}

void Engine::timerCallback()
{
    // Update state variables that change over time like transport position
    
    // Set current step position and proportion
    auto track = EngineHelpers::getOrInsertAudioTrackAt (edit, stepSequencerTrackNum);
    auto stepClip = dynamic_cast<te::StepClip*> (track->getClips()[0]);
    auto clipRange = stepClip->getEditTimeRange();
    if (clipRange.isEmpty()) {
        state.currentStepPosition = 0.0;
        state.currentStepProportion = 0.0;
    } else {
        const double position = transport.position;
        const auto proportion = position / clipRange.getEnd();
        state.currentStepPosition = position;
        state.currentStepProportion = proportion;
    }
    
    // Get track 1 level
    state.track0Level = track0LevelClient.getAndClearAudioLevel(0).dB;
}
