/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Push2Simulator.h"

//==============================================================================
/**
*/
class OctopushOspluginAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    OctopushOspluginAudioProcessorEditor (OctopushOspluginAudioProcessor&);
    ~OctopushOspluginAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    OctopushOspluginAudioProcessor& processor;
    
    Push2Simulator push2SimulatorComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OctopushOspluginAudioProcessorEditor)
};
