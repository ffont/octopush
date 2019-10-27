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
#include "helpers/push2.h"
#include "Engine.h"
#include "definitions.h"


class Push2Interface: public Timer,
                      public MidiInputCallback,
                      public ActionListener,
                      public ActionBroadcaster,
                      public Push2ButtonsListener,
                      public Push2EncodersListener
{
public:
    
    Push2Interface();
    ~Push2Interface();

    void initialize(Engine* engine_);
    NBase::Result connectToPush();
    
    void actionListenerCallback (const String &message) override;
    
    Image computeFrame();
    Image lastFrame;
    
    // Encoder action handlers
    void e1Rotated(int increment);
    
    // Button action handlers
    void ba1Pressed();
    
    
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
    Engine* engine;
    
    float elapsedTimeAnimation;
    float frameWaveHeightMultiplier;
    Colour waveformColor;
};
