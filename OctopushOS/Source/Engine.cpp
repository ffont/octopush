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
    auto clip = EngineHelpers::loadAudioFileAsClip (edit, f); // Will add the audio file as a clip in track #0 of edit
    transport.setLoopRange (clip->getEditTimeRange());
    transport.looping = true;
    transport.position = 0.0;
    transport.play (false);
    
    // Get audio input channels and create tracks routed to output
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
}

void Engine::changeListenerCallback (ChangeBroadcaster*)
{
    // Do nothing, this is here to comply with ChangeListener protocol
}
