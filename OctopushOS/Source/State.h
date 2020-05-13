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

// -- for collect system stats
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>


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
    
    std::string exec(const char* cmd) {
        std::array<char, 128> buffer;
        std::string result;
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }
        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            result += buffer.data();
        }
        return result;
    }
    
    void collectSystemStats() {
        std::cout << "----------- System stats:" << std::endl;
        std::cout << "CPU freq: " << exec("cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq");
        std::cout << "CPU temp: " << exec("sudo vcgencmd measure_temp");
        std::cout << "Memory used (%): " << exec("free | grep Mem | awk '{print $3/$2 * 100.0}'");
        std::cout << "CPU used (%): " << exec("grep 'cpu ' /proc/stat | awk '{usage=($2+$4)*100/($2+$4+$5)} END {print usage \"%\"}'");
        std::cout << "MSW:\nCPU  PID    MSW        CSW        XSC        PF    STAT       %CPU  NAME\n" << exec("more /proc/xenomai/sched/stat | grep sushi_b64");
        std::cout << "-----------" << std::endl;
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
    
    int stateUpdateFrameRate = 0;
    int displayFrameRate = 0;
    
private:
    
  
};
