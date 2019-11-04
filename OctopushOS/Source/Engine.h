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
#include "definitions.h"

namespace te = tracktion_engine;


class Engine: private ChangeListener,
              public Timer,
              public ActionBroadcaster
{
public:
    Engine();
    ~Engine();
    
    void initialize();
    
    void transportPlay();
    void transportStop();
    void transportTogglePlayStop();
    
    void setTrackVolume(int tracknum, float gain);
    void toggleMuteTrack(int tracknum);
    
    void updateStepSequencerPattern(int samplerChannel, int stepN);
    
    State state;  // Make state public so it can be accessed and modified by others

private:
    // Methods
    void changeListenerCallback (ChangeBroadcaster*) override;
    void timerCallback() override;
   
    // Properties
    te::Engine engine { ProjectInfo::projectName };
    te::Edit edit { engine, te::createEmptyEdit(), te::Edit::forEditing, nullptr, 0 };
    te::TransportControl& transport { edit.getTransport() };
    
    std::array<te::LevelMeasurer::Client, N_AUDIO_TRACKS> trackLevelClients;
};
