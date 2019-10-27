/*
  ==============================================================================

    push2.h
    Created: 27 Oct 2019 10:50:50am
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#pragma once


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
    
    // Upper row buttons methods (to be implemented in classes inheriting form Push2EncodersListener)
    void ba1Pressed(){}
    void ba2Pressed(){}
    void ba3Pressed(){}
    void ba4Pressed(){}
    void ba5Pressed(){}
    void ba6Pressed(){}
    void ba7Pressed(){}
    void ba8Pressed(){}
    
    // Lower row buttons methods (to be implemented in classes inheriting form Push2EncodersListener)
    void bb1Pressed(){}
    void bb2Pressed(){}
    void bb3Pressed(){}
    void bb4Pressed(){}
    void bb5Pressed(){}
    void bb6Pressed(){}
    void bb7Pressed(){}
    void bb8Pressed(){}
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
