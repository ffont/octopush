/*
  ==============================================================================
    OctopushAudioEngine.h
    Created: 25 Oct 2019 4:14:04pm
    Author:  Frederic Font Corbera
  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "State.h"
#include "definitions.h"

namespace te = tracktion_engine;


class OctopushAudioEngine: private ChangeListener,
                           public Timer,
                           public ActionBroadcaster
{
public:
    OctopushAudioEngine();
    ~OctopushAudioEngine();
    
    static void setupInputs (te::Edit& edit);
    static void setupOutputs (te::Edit& edit);
    
    void initialize(te::Engine* _engine, te::Edit* _edit, bool playOnStart, int stateUpdateRate, bool minimal);
    
    void transportPlay();
    void transportStop();
    void transportTogglePlayStop();
    
    void setTrackVolume(int tracknum, float gain);
    void toggleMuteTrack(int tracknum);
    
    void updateStepSequencerPattern(int samplerChannel, int stepN);
    
    void setReverberationRoomSize(float roomSize);
    
    State state;  // Make state public so it can be accessed and modified by others
    
    std::unique_ptr<te::Engine> engine;

private:
    // Methods
    void changeListenerCallback (ChangeBroadcaster*) override;
    void timerCallback() override;
    
    int stateUpdateRateCounter = 0;
    int64 stateUpdateRateCurrentSecond = 0;
    bool actionInitPushTriggered = false;
   
    // Properties
    std::unique_ptr<te::Edit> edit;
    std::unique_ptr<te::TransportControl> transport;
    std::array<te::LevelMeasurer::Client*, N_AUDIO_TRACKS> trackLevelClients;
};
