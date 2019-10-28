/*
  ==============================================================================

    push2.h
    Created: 27 Oct 2019 10:50:50am
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


class Push2ButtonsListener
{
public:
    
    // Button CC number definitions
    int BUTTON_A1_CC_NUMBER = 102;
    int BUTTON_A2_CC_NUMBER = 103;
    int BUTTON_A3_CC_NUMBER = 104;
    int BUTTON_A4_CC_NUMBER = 105;
    int BUTTON_A5_CC_NUMBER = 106;
    int BUTTON_A6_CC_NUMBER = 107;
    int BUTTON_A7_CC_NUMBER = 108;
    int BUTTON_A8_CC_NUMBER = 109;
    int BUTTON_B1_CC_NUMBER = 20;
    int BUTTON_B2_CC_NUMBER = 21;
    int BUTTON_B3_CC_NUMBER = 22;
    int BUTTON_B4_CC_NUMBER = 23;
    int BUTTON_B5_CC_NUMBER = 24;
    int BUTTON_B6_CC_NUMBER = 25;
    int BUTTON_B7_CC_NUMBER = 26;
    int BUTTON_B8_CC_NUMBER = 27;
    int BUTTON_PLAY_CC_NUMBER = 85;
    
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
    
    // Upper row buttons methods (to be implemented in classes inheriting form Push2EncodersListener)
    void ba1Pressed(){}
    void ba2Pressed(){}
    void ba3Pressed(){}
    void ba4Pressed(){}
    void ba5Pressed(){}
    void ba6Pressed(){}
    void ba7Pressed(){}
    void ba8Pressed(){}
    void ba1Released(){}
    void ba2Released(){}
    void ba3Released(){}
    void ba4Released(){}
    void ba5Released(){}
    void ba6Released(){}
    void ba7Released(){}
    void ba8Released(){}
    
    // Lower row buttons methods (to be implemented in classes inheriting form Push2EncodersListener)
    void bb1Pressed(){}
    void bb2Pressed(){}
    void bb3Pressed(){}
    void bb4Pressed(){}
    void bb5Pressed(){}
    void bb6Pressed(){}
    void bb7Pressed(){}
    void bb8Pressed(){}
    void bb1Released(){}
    void bb2Released(){}
    void bb3Released(){}
    void bb4Released(){}
    void bb5Released(){}
    void bb6Released(){}
    void bb7Released(){}
    void bb8Released(){}
    
    // Transport buttons methods (to be implemented in classes inheriting form Push2EncodersListener)
    void playPressed(){}
    void playReleased(){}
};

class Push2EncodersListener
{
public:
    
    // Encoder cc number definitions
    int ENCODER_TEMPO_CC_NUMBER = 14;
    int ENCODER_SWING_CC_NUMBER = 15;
    int ENCODER_E1_CC_NUMBER = 71;
    int ENCODER_E2_CC_NUMBER = 72;
    int ENCODER_E3_CC_NUMBER = 73;
    int ENCODER_E4_CC_NUMBER = 74;
    int ENCODER_E5_CC_NUMBER = 75;
    int ENCODER_E6_CC_NUMBER = 76;
    int ENCODER_E7_CC_NUMBER = 77;
    int ENCODER_E8_CC_NUMBER = 78;
    int ENCODER_MASTER_CC_NUMBER = 79;
    
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
    
    // Encoder methods (to be implemented in classes inheriting form Push2EncodersListener)
    void tempoEncoderRotated(int increment){}
    void swingEncoderRotated(int increment){}
    void e1Rotated(int increment){}
    void e2Rotated(int increment){}
    void e3Rotated(int increment){}
    void e4Rotated(int increment){}
    void e5Rotated(int increment){}
    void e6Rotated(int increment){}
    void e7Rotated(int increment){}
    void e8Rotated(int increment){}
    void masterEncoderRotated(int increment){}
};
