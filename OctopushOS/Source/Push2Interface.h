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
#include "State.h"
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
    bool pushInitializedSuccessfully;
    
    void actionListenerCallback (const String &message) override;
    
    Image computeFrame();
    Image lastFrame;
    
    // Encoder action handlers
    void e1Rotated(int increment) override;
    void e5Rotated(int increment) override;
    void e6Rotated(int increment) override;
    void e7Rotated(int increment) override;
    void e8Rotated(int increment) override;
    
    // Button action handlers
    void ba1Pressed() override;
    void ba5Pressed() override;
    void ba6Pressed() override;
    void ba7Pressed() override;
    void ba8Pressed() override;
    void playPressed() override;
    
private:
    
    // Methods
    void drawFrame();

    NBase::Result openMidiDevice();
    void handleIncomingMidiMessage (MidiInput *source, const MidiMessage &message) override;

    void timerCallback() override;
    
    // Properties
    ableton::Push2DisplayBridge bridge;
    ableton::Push2Display push2Display;
    std::unique_ptr<MidiInput> midiInput;
    Engine* engine;
    State* state;

};
