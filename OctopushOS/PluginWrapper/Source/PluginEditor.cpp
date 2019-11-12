/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
OctopushOspluginAudioProcessorEditor::OctopushOspluginAudioProcessorEditor (OctopushOspluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    
    #if JUCE_DEBUG
    if (!processor.push.pushInitializedSuccessfully) {
        setSize (900, 726);
        push2SimulatorComponent.setPush2Interface(&processor.push);
        addAndMakeVisible(push2SimulatorComponent);
    }
    #endif
}

OctopushOspluginAudioProcessorEditor::~OctopushOspluginAudioProcessorEditor()
{
}

//==============================================================================
void OctopushOspluginAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("OctopushOS up and running!", getLocalBounds(), Justification::centred, 1);
}

void OctopushOspluginAudioProcessorEditor::resized()
{
    #if JUCE_DEBUG
    if (!processor.push.pushInitializedSuccessfully) {
        push2SimulatorComponent.setBounds(getBounds());
    }
    #endif
}
