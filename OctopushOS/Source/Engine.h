/*
  ==============================================================================
    Engine.h
    Created: 25 Oct 2019 4:14:04pm
    Author:  Frederic Font Corbera
  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
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
    
    void initialize(bool playOnStart, int stateUpdateRate, bool minimal);
    
    void transportPlay();
    void transportStop();
    void transportTogglePlayStop();
    
    void setTrackVolume(int tracknum, float gain);
    void toggleMuteTrack(int tracknum);
    
    void updateStepSequencerPattern(int samplerChannel, int stepN);
    
    void setReverberationRoomSize(float roomSize);
    
    State state;  // Make state public so it can be accessed and modified by others
    
    te::Engine engine { ProjectInfo::projectName };

private:
    // Methods
    void changeListenerCallback (ChangeBroadcaster*) override;
    void timerCallback() override;
    
    int stateUpdateRateCounter = 0;
    int64 stateUpdateRateCurrentSecond = 0;
   
    // Properties
    te::Edit edit { engine, te::createEmptyEdit(engine), te::Edit::forEditing, nullptr, 0 };
    te::TransportControl& transport { edit.getTransport() };
    
    std::array<te::LevelMeasurer::Client*, N_AUDIO_TRACKS> trackLevelClients;
};
