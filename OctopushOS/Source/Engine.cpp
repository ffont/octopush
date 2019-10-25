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
    // Initialize Tracktion engine demo and start playing audio
    auto f = File::createTempFile (".ogg");
    f.replaceWithData (BinaryData::demo_audio_ogg, BinaryData::demo_audio_oggSize);
    edit = std::make_unique<te::Edit> (engine, te::createEmptyEdit(), te::Edit::forEditing, nullptr, 0);
    auto clip = EngineHelpers::loadAudioFileAsClip (*edit, f);
    auto& transport = edit->getTransport();
    transport.setLoopRange (clip->getEditTimeRange());
    transport.looping = true;
    transport.position = 0.0;
    transport.play (false);
}
    
Engine::~Engine()
{
    // Shot down tracktion engine stuff
    engine.getTemporaryFileManager().getTempDirectory().deleteRecursively();
    
    // Remove action listeners of Engine
    removeAllActionListeners();
}

void Engine::changeListenerCallback (ChangeBroadcaster*)
{
    // Do nothing, this is here to comply with ChangeListener protocol
}
    
