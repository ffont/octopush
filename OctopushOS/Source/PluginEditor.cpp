/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
OctopushOsAudioProcessorEditor::OctopushOsAudioProcessorEditor (OctopushOsAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    #if JUCE_DEBUG
    bool debug = true;
    #else
    bool debug = false;
    #endif
    bool showSimulator = false;
    String showSimulatorValue = "";
    
    if (showSimulatorValue == "show"){
        showSimulator = true;
    } else if (showSimulatorValue == "hide"){
        showSimulator = false;
    } else {
        // If not force/hide show simulator we'll only show it if push was not initialized properly and we're in debug mode
        if (!processor.push.pushInitializedSuccessfully && debug){
            showSimulator = true;
        }
    }
    
    if (showSimulator) {
        setSize (900, 726);
        push2SimulatorComponent.setPush2Interface(&processor.push);
        addAndMakeVisible(push2SimulatorComponent);
    }
}

OctopushOsAudioProcessorEditor::~OctopushOsAudioProcessorEditor()
{
}

//==============================================================================
void OctopushOsAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("OctopushOS up and running!", getLocalBounds(), Justification::centred, 1);
}

void OctopushOsAudioProcessorEditor::resized()
{
    #if JUCE_DEBUG
    if (!processor.push.pushInitializedSuccessfully) {
        push2SimulatorComponent.setBounds(getBounds());
    }
    #endif
}
