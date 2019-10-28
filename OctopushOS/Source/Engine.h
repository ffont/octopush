/*
  ==============================================================================

    Engine.h
    Created: 25 Oct 2019 4:14:04pm
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "State.h"

namespace te = tracktion_engine;


class Engine: private ChangeListener,
              public ActionBroadcaster
{
public:
    Engine();
    ~Engine();
    
    void initialize();
    
    void transportPlay();
    void transportStop();
    void transportTogglePlayStop();

private:
    // Methods
    void changeListenerCallback (ChangeBroadcaster*) override;
   
    // Properties
    te::Engine engine { ProjectInfo::projectName };
    te::Edit edit { engine, te::createEmptyEdit(), te::Edit::forEditing, nullptr, 0 };
    te::TransportControl& transport { edit.getTransport() };
    
    State state;
};
