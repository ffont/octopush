/*
  ==============================================================================

    State.h
    Created: 25 Oct 2019 4:14:26pm
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "definitions.h"

struct AudioTrackSettings {
    float measuredLevel = -100.0;  // in dB
    float volume = 0.0;  // in dB
    bool mute = false;
};

class State
{
public:
    State(){
        
        // Init stepSequencerPattern to basic pattern
        for (int samplerChannel=0; samplerChannel < 4; samplerChannel++){
            if (samplerChannel == 0){ // Kick
                stepSequencerPattern[samplerChannel][0] = true;
                stepSequencerPattern[samplerChannel][4] = true;
                stepSequencerPattern[samplerChannel][8] = true;
                stepSequencerPattern[samplerChannel][12] = true;
            } else if (samplerChannel == 1){ // Hihat
                stepSequencerPattern[samplerChannel][1] = true;
                stepSequencerPattern[samplerChannel][3] = true;
                stepSequencerPattern[samplerChannel][5] = true;
                stepSequencerPattern[samplerChannel][7] = true;
                stepSequencerPattern[samplerChannel][9] = true;
                stepSequencerPattern[samplerChannel][11] = true;
                stepSequencerPattern[samplerChannel][13] = true;
                stepSequencerPattern[samplerChannel][15] = true;
            } else if (samplerChannel == 2){ // Snare
                stepSequencerPattern[samplerChannel][2] = true;
                stepSequencerPattern[samplerChannel][6] = true;
                stepSequencerPattern[samplerChannel][10] = true;
                stepSequencerPattern[samplerChannel][14] = true;
            } else if (samplerChannel == 3){ // Clap
                stepSequencerPattern[samplerChannel][2] = true;
                stepSequencerPattern[samplerChannel][6] = true;
                stepSequencerPattern[samplerChannel][10] = true;
                stepSequencerPattern[samplerChannel][14] = true;
            }
        }
    }
    
    ~State(){
        
    }
    
    float animationElapsedTime = 0.0;
    float demoWaveAmplitude = 0.5;
    Colour demoWaveColor = Colours::white;
    
    bool isPlaying = false;
    float tempo = 60.0;
    
    std::array<std::array<bool, 16>, 4> stepSequencerPattern;
    double currentStepPosition = 0.0;
    double currentStepProportion = 0.0;
    
    std::array<AudioTrackSettings, N_AUDIO_TRACKS> audioTrackSettings;
    
    float reverberationRoomSize = 0.5;
    
private:
    
  
};
