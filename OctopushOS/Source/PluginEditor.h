/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#if !ELK_BUILD
#include "Push2Simulator.h"
#endif

//==============================================================================
/**
*/
class OctopushOsAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    OctopushOsAudioProcessorEditor (OctopushOsAudioProcessor&);
    ~OctopushOsAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    OctopushOsAudioProcessor& processor;
    
    #if !ELK_BUILD
    Push2Simulator push2SimulatorComponent;
    #endif

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OctopushOsAudioProcessorEditor)
};
