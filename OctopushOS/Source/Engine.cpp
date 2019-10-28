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
    //------------- Load audio file and start playing it in loop
    auto f = File::createTempFile ("tambourine.wav");
    f.replaceWithData (BinaryData::tambourine_wav, BinaryData::tambourine_wavSize);
    auto clip = EngineHelpers::loadAudioFileAsClip (edit, f); // Will add the audio file as a clip in track #0 of edit
    
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
    edit.tempoSequence.getTempos()[0]->setBpm (60.0);
    int stepSequencerTrackNum = trackNum + 1;
    if (auto track = EngineHelpers::getOrInsertAudioTrackAt (edit, stepSequencerTrackNum))
    {
        // Find length of 1 bar
        const te::EditTimeRange editTimeRange (0, edit.tempoSequence.barsBeatsToTime ({ 1, 0.0 }));
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
                if (channelCount == 0){ // Kick
                    pattern.setNote (channelCount, 0, true);
                    pattern.setNote (channelCount, 4, true);
                    pattern.setNote (channelCount, 8, true);
                    pattern.setNote (channelCount, 12, true);
                } else if (channelCount == 1){ // Hihat
                    pattern.setNote (channelCount, 1, true);
                    pattern.setNote (channelCount, 3, true);
                    pattern.setNote (channelCount, 5, true);
                    pattern.setNote (channelCount, 7, true);
                    pattern.setNote (channelCount, 9, true);
                    pattern.setNote (channelCount, 11, true);
                    pattern.setNote (channelCount, 13, true);
                    pattern.setNote (channelCount, 15, true);
                } else if (channelCount == 2){ // Snare
                    pattern.setNote (channelCount, 2, true);
                    pattern.setNote (channelCount, 6, true);
                    pattern.setNote (channelCount, 10, true);
                    pattern.setNote (channelCount, 14, true);
                } else if (channelCount == 3){ // Clap
                    pattern.setNote (channelCount, 2, true);
                    pattern.setNote (channelCount, 6, true);
                    pattern.setNote (channelCount, 10, true);
                    pattern.setNote (channelCount, 14, true);
                }
            }
            
            channelCount++;
        }
    }
    
    // NOTE: this will not play anything. To start play the transport needs to be started
    // transport.play(false);
    // transport.stop(true, true);
}

void Engine::changeListenerCallback (ChangeBroadcaster*)
{
    // Do nothing, this is here to comply with ChangeListener protocol
}

void Engine::transportPlay(){
    transport.play(false);
}

void Engine::transportStop(){
    transport.stop(false, true);
}

void Engine::transportTogglePlayStop(){
    if (transport.isPlaying()){
        transportStop();
    } else {
        transportPlay();
    }
}
