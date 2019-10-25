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

private:
    // Methods
    void changeListenerCallback (ChangeBroadcaster*) override;
    
    // Properties
    te::Engine engine { ProjectInfo::projectName };
    std::unique_ptr<te::Edit> edit;  
    
    State state;
};
