/*
  ==============================================================================
    Push2Interface.h
    Created: 24 Oct 2019 6:26:33pm
    Author:  Frederic Font Corbera
  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "push2/JuceToPush2DisplayBridge.h"
#include "helpers/push2.h"
#include "OctopushAudioEngine.h"
#include "State.h"
#include "definitions.h"


class Push2Interface: public Timer,
                      public MidiInputCallback,
                      public ActionListener,
                      public ActionBroadcaster,
                      public Push2ButtonsController,
                      public Push2EncodersController,
                      public Push2PadsController,
                      private OSCReceiver,
                      private OSCReceiver::ListenerWithOSCAddress<OSCReceiver::MessageLoopCallback>
{
public:
    
    Push2Interface();
    ~Push2Interface();

    void initialize(OctopushAudioEngine* oae_, int displayFrameRate_, int maxEncoderUpdateRate_, bool useMIDIBridge_);
    NBase::Result connectToPushDisplay();
    NBase::Result connectToPushMIDI();
    bool pushInitializedSuccessfully;
    bool pushDisplayInitializedSuccessfully;
    bool pushMIDIInitializedSuccessfully;
    bool initializeOSCSender();
    bool initializeOSCReceiver();
    void oscMessageReceived (const OSCMessage& message) override;
    bool oscSenderConnectedToMIDIBridge;
    bool oscReceivedInitialized;
    
    void actionListenerCallback (const String &message) override;
    
    Image lastFrame;
    
    // Encoder action handlers
    void e1Rotated(int increment) override;
    void e2Rotated(int increment) override;
    void e3Rotated(int increment) override;
    void e4Rotated(int increment) override;
    void e5Rotated(int increment) override;
    void e6Rotated(int increment) override;
    void e7Rotated(int increment) override;
    void e8Rotated(int increment) override;
    
    // Button action handlers
    void ba1Pressed() override;
    void ba2Pressed() override;
    void ba3Pressed() override;
    void ba4Pressed() override;
    void ba5Pressed() override;
    void ba6Pressed() override;
    void ba7Pressed() override;
    void ba8Pressed() override;
    void playPressed() override;
    
    // Pad action handlers
    void padPressed(PadIJ padIJ, int velocity) override;
    
private:
    
    // Methods
    Image computeDisplayFrameFromState();
    void updateDisplayFromState();
    void updatePush2ButtonsFromState();
    void updatePush2PadsFromState();
    void updateUI();
    void setInitialUI();

    NBase::Result openMidiInDevice();
    void handleIncomingMidiMessage (MidiInput *source, const MidiMessage &message) override;
    void routeIncomingMidiMessage (const MidiMessage &message);
    
    NBase::Result openMidiOutDevice();
    void sendMidiMessage(MidiMessage msg) override;

    void timerCallback() override;
    int displayFrameRateCounter = 0;
    int64 displayFrameCurrentSecond = 0;
    
    // Properties
    int displayFrameRate;
    ableton::Push2DisplayBridge bridge;
    ableton::Push2Display push2Display;
    
    bool useMIDIBridge;
    std::unique_ptr<MidiInput> midiInput;
    std::unique_ptr<MidiOutput> midiOutput;
    std::unique_ptr<OctopushAudioEngine> oae;
    std::unique_ptr<State> state;
    OSCSender oscSender;
};
