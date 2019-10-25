/*
  ==============================================================================

    Push2Interface.h
    Created: 24 Oct 2019 6:26:33pm
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "push2/JuceToPush2DisplayBridge.h"


class Push2Interface: public Timer,
                      public MidiInputCallback,
                      public ActionBroadcaster
{
public:
    
    NBase::Result Init();
    Image computeFrame();
    Image lastFrame;
    
private:
    
    // Methods
    void drawFrame();

    NBase::Result openMidiDevice();
    void handleIncomingMidiMessage (MidiInput *source, const MidiMessage &message) override;

    void timerCallback() override;
    
    // Properties
    bool pushInitializedSuccessfully;
    ableton::Push2DisplayBridge bridge;
    ableton::Push2Display push2Display;
    std::unique_ptr<MidiInput> midiInput;
    
    float elapsedTimeAnimation;
    float frameWaveHeightMultiplier;
};
