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
    // Load audio file and start playing it in loop
    auto f = File::createTempFile (".ogg");
    f.replaceWithData (BinaryData::demo_audio_ogg, BinaryData::demo_audio_oggSize);
    demoPlaybackFileEdit = std::make_unique<te::Edit> (engine, te::createEmptyEdit(), te::Edit::forEditing, nullptr, 0);
    auto clip = EngineHelpers::loadAudioFileAsClip (*demoPlaybackFileEdit, f);
    auto& transport = demoPlaybackFileEdit->getTransport();
    transport.setLoopRange (clip->getEditTimeRange());
    transport.looping = true;
    transport.position = 0.0;
    transport.play (false);
    
    // Get audio input channels and create tracks routed to output
    routingInputsEdit = std::make_unique<te::Edit> (engine, te::createEmptyEdit(), te::Edit::forEditing, nullptr, 0);
    int trackNum = 0;
    for (auto instance : routingInputsEdit->getAllInputDevices())
    {
        if (instance->getInputDevice().getDeviceType() == te::InputDevice::waveDevice)
        {
            if (auto t = EngineHelpers::getOrInsertAudioTrackAt (*routingInputsEdit, trackNum))
            {
                instance->setTargetTrack (t, 0);
                instance->setRecordingEnabled (true);
                trackNum++;
            }
        }
    }
    routingInputsEdit->restartPlayback();
}

void Engine::changeListenerCallback (ChangeBroadcaster*)
{
    // Do nothing, this is here to comply with ChangeListener protocol
}
