/*
  ==============================================================================

    push2.h
    Created: 27 Oct 2019 10:50:50am
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class Push2Common
{
public:
    
    virtual ~Push2Common(){}
    
    
    static const int RGB_COLOUR_BLACK = 0;
    static const int RGB_COLOUR_WHITE = 122;
    static const int RGB_COLOUR_LIGHT_GRAY = 123;
    static const int RGB_COLOUR_DARK_GRAY = 124;
    static const int RGB_COLOUR_BLUE = 125;
    static const int RGB_COLOUR_GREEN = 126;
    static const int RGB_COLOUR_RED = 127;
    static const int RGB_COLOUR_ORANGE = 3;
    static const int RGB_COLOUR_YELLOW = 8;
    static const int RGB_COLOUR_TURQUOISE = 15;
    static const int RGB_COLOUR_PURPLE = 22;
    static const int RGB_COLOUR_PINK = 25;
    
    static const int BW_COLOUR_BLACK = 0;
    static const int BW_COLOUR_DARK_GRAY = 16;
    static const int BW_COLOUR_LIGHT_GRAY = 48;
    static const int BW_COLOUR_WHITE = 127;
    
    virtual void sendMidiMessage(MidiMessage msg){
        // To be implemented in a subclass which has access to the MidiOutput connected to Push2
    }
};


class Push2ButtonsController: public Push2Common
{
public:
    
    virtual ~Push2ButtonsController(){}
    
    // Button CC number definitions
    static const int BUTTON_A1_CC_NUMBER = 102;
    static const int BUTTON_A2_CC_NUMBER = 103;
    static const int BUTTON_A3_CC_NUMBER = 104;
    static const int BUTTON_A4_CC_NUMBER = 105;
    static const int BUTTON_A5_CC_NUMBER = 106;
    static const int BUTTON_A6_CC_NUMBER = 107;
    static const int BUTTON_A7_CC_NUMBER = 108;
    static const int BUTTON_A8_CC_NUMBER = 109;
    static const int BUTTON_B1_CC_NUMBER = 20;
    static const int BUTTON_B2_CC_NUMBER = 21;
    static const int BUTTON_B3_CC_NUMBER = 22;
    static const int BUTTON_B4_CC_NUMBER = 23;
    static const int BUTTON_B5_CC_NUMBER = 24;
    static const int BUTTON_B6_CC_NUMBER = 25;
    static const int BUTTON_B7_CC_NUMBER = 26;
    static const int BUTTON_B8_CC_NUMBER = 27;
    static const int BUTTON_PLAY_CC_NUMBER = 85;
    
    bool triggerButtonActionsFromIncommingMidi(const MidiMessage &message){
        // Check if MIDI message is of type CC and matches one of the CC
        // numbers of the buttons. If there's a match call corresponding
        // button action and return True. If there's no match False.
        
        if (message.isController())
        {
            int ccValue = message.getControllerValue();
            int ccNumber = message.getControllerNumber();
            
            if (ccNumber == BUTTON_A1_CC_NUMBER){
                if (ccValue == 127){ ba1Pressed(); } else { ba1Released(); }
                return true;
            } else if (ccNumber == BUTTON_A2_CC_NUMBER){
                if (ccValue == 127){ ba2Pressed(); } else { ba2Released(); }
                return true;
            } else if (ccNumber == BUTTON_A3_CC_NUMBER){
                if (ccValue == 127){ ba3Pressed(); } else { ba3Released(); }
                return true;
            } else if (ccNumber == BUTTON_A4_CC_NUMBER){
                if (ccValue == 127){ ba4Pressed(); } else { ba4Released(); }
                return true;
            } else if (ccNumber == BUTTON_A5_CC_NUMBER){
                if (ccValue == 127){ ba5Pressed(); } else { ba5Released(); }
                return true;
            } else if (ccNumber == BUTTON_A6_CC_NUMBER){
                if (ccValue == 127){ ba6Pressed(); } else { ba6Released(); }
                return true;
            } else if (ccNumber == BUTTON_A7_CC_NUMBER){
                if (ccValue == 127){ ba7Pressed(); } else { ba7Released(); }
                return true;
            } else if (ccNumber == BUTTON_A8_CC_NUMBER){
                if (ccValue == 127){ ba8Pressed(); } else { ba8Released(); }
                return true;
            } else if (ccNumber == BUTTON_B1_CC_NUMBER){
                if (ccValue == 127){ bb1Pressed(); } else { bb1Released(); }
                return true;
            } else if (ccNumber == BUTTON_B2_CC_NUMBER){
                if (ccValue == 127){ bb2Pressed(); } else { bb2Released(); }
                return true;
            } else if (ccNumber == BUTTON_B3_CC_NUMBER){
                if (ccValue == 127){ bb3Pressed(); } else { bb3Released(); }
                return true;
            } else if (ccNumber == BUTTON_B4_CC_NUMBER){
                if (ccValue == 127){ bb4Pressed(); } else { bb4Released(); }
                return true;
            } else if (ccNumber == BUTTON_B5_CC_NUMBER){
                if (ccValue == 127){ bb5Pressed(); } else { bb5Released(); }
                return true;
            } else if (ccNumber == BUTTON_B6_CC_NUMBER){
                if (ccValue == 127){ bb6Pressed(); } else { bb6Released(); }
                return true;
            } else if (ccNumber == BUTTON_B7_CC_NUMBER){
                if (ccValue == 127){ bb7Pressed(); } else { bb7Released(); }
                return true;
            } else if (ccNumber == BUTTON_B8_CC_NUMBER){
                if (ccValue == 127){ bb8Pressed(); } else { bb8Released(); }
                return true;
            } else if (ccNumber == BUTTON_PLAY_CC_NUMBER){
                if (ccValue == 127){ playPressed(); } else { playReleased(); }
                return true;
            }
        }
        return false;
    }
    
    void setButtonRGBColour(int buttonNumber, int rgbColorCode){
        int outputChannel = 0;  // output channel detemrines animation type. This si currently not implemented.
        MidiMessage msg = MidiMessage::controllerEvent(outputChannel, buttonNumber, rgbColorCode);
        sendMidiMessage(msg);
    }
    
    void setButtonBWColour(int buttonNumber, int bwColorCode){
        int outputChannel = 0;  // output channel detemrines animation type. This si currently not implemented.
        MidiMessage msg = MidiMessage::controllerEvent(outputChannel, buttonNumber, bwColorCode);
        sendMidiMessage(msg);
    }
    
    // The following methods will be called if a button is pressed/released
    virtual void ba1Pressed(){}
    virtual void ba2Pressed(){}
    virtual void ba3Pressed(){}
    virtual void ba4Pressed(){}
    virtual void ba5Pressed(){}
    virtual void ba6Pressed(){}
    virtual void ba7Pressed(){}
    virtual void ba8Pressed(){}
    virtual void ba1Released(){}
    virtual void ba2Released(){}
    virtual void ba3Released(){}
    virtual void ba4Released(){}
    virtual void ba5Released(){}
    virtual void ba6Released(){}
    virtual void ba7Released(){}
    virtual void ba8Released(){}
    
    virtual void bb1Pressed(){}
    virtual void bb2Pressed(){}
    virtual void bb3Pressed(){}
    virtual void bb4Pressed(){}
    virtual void bb5Pressed(){}
    virtual void bb6Pressed(){}
    virtual void bb7Pressed(){}
    virtual void bb8Pressed(){}
    virtual void bb1Released(){}
    virtual void bb2Released(){}
    virtual void bb3Released(){}
    virtual void bb4Released(){}
    virtual void bb5Released(){}
    virtual void bb6Released(){}
    virtual void bb7Released(){}
    virtual void bb8Released(){}
    
    virtual void playPressed(){}
    virtual void playReleased(){}
};

class Push2EncodersController: public Push2Common
{
public:
    
    virtual ~Push2EncodersController(){}
    
    // Encoder cc number definitions
    static const int ENCODER_TEMPO_CC_NUMBER = 14;
    static const int ENCODER_SWING_CC_NUMBER = 15;
    static const int ENCODER_E1_CC_NUMBER = 71;
    static const int ENCODER_E2_CC_NUMBER = 72;
    static const int ENCODER_E3_CC_NUMBER = 73;
    static const int ENCODER_E4_CC_NUMBER = 74;
    static const int ENCODER_E5_CC_NUMBER = 75;
    static const int ENCODER_E6_CC_NUMBER = 76;
    static const int ENCODER_E7_CC_NUMBER = 77;
    static const int ENCODER_E8_CC_NUMBER = 78;
    static const int ENCODER_MASTER_CC_NUMBER = 79;
    
    bool triggerEncoderActionsFromIncommingMidi(const MidiMessage &message){
        // Check if MIDI message is of type CC and matches one of the CC
        // numbers of the encoders. If there's a match call corresponding
        // encoder action and return True. If there's no match False.
        
        if (message.isController())
        {
            int ccValue = message.getControllerValue();
            int ccNumber = message.getControllerNumber();
            
            if (ccNumber == ENCODER_TEMPO_CC_NUMBER){
                if (ccValue == 127){ tempoEncoderRotated(1); } else { tempoEncoderRotated(-1); }
                return true;
            } else if (ccNumber == ENCODER_SWING_CC_NUMBER){
                if (ccValue == 127){ swingEncoderRotated(1); } else { swingEncoderRotated(-1); }
                return true;
            } else if (ccNumber == ENCODER_E1_CC_NUMBER){
                if (ccValue == 127){ e1Rotated(1); } else { e1Rotated(-1); }
                return true;
            } else if (ccNumber == ENCODER_E2_CC_NUMBER){
                if (ccValue == 127){ e2Rotated(1); } else { e2Rotated(-1); }
                return true;
            } else if (ccNumber == ENCODER_E3_CC_NUMBER){
                if (ccValue == 127){ e3Rotated(1); } else { e3Rotated(-1); }
                return true;
            } else if (ccNumber == ENCODER_E4_CC_NUMBER){
                if (ccValue == 127){ e4Rotated(1); } else { e4Rotated(-1); }
                return true;
            } else if (ccNumber == ENCODER_E5_CC_NUMBER){
                if (ccValue == 127){ e5Rotated(1); } else { e5Rotated(-1); }
                return true;
            } else if (ccNumber == ENCODER_E6_CC_NUMBER){
                if (ccValue == 127){ e6Rotated(1); } else { e6Rotated(-1); }
                return true;
            } else if (ccNumber == ENCODER_E7_CC_NUMBER){
                if (ccValue == 127){ e7Rotated(1); } else { e7Rotated(-1); }
                return true;
            } else if (ccNumber == ENCODER_E8_CC_NUMBER){
                if (ccValue == 127){ e8Rotated(1); } else { e8Rotated(-1); }
                return true;
            } else if (ccNumber == ENCODER_MASTER_CC_NUMBER){
                if (ccValue == 127){ masterEncoderRotated(1); } else { masterEncoderRotated(-1); }
                return true;
            }
        }
        return false;
    }
    
    // The following methods will be called if encoders are rotated
    virtual void tempoEncoderRotated(int increment){}
    virtual void swingEncoderRotated(int increment){}
    virtual void e1Rotated(int increment){}
    virtual void e2Rotated(int increment){}
    virtual void e3Rotated(int increment){}
    virtual void e4Rotated(int increment){}
    virtual void e5Rotated(int increment){}
    virtual void e6Rotated(int increment){}
    virtual void e7Rotated(int increment){}
    virtual void e8Rotated(int increment){}
    virtual void masterEncoderRotated(int increment){}
};
