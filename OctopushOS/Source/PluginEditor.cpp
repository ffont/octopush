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
    
    
    #if ELK_BUILD
        // If no ELK build, don't load Push2 simulator
    
    #else
        // If on a normal build, follow some heuristics to decide if the Push2 simulator should be shown
        // (if on debug build and push is not connected)
    
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
            //if (!processor.engineWrapper->push.pushInitializedSuccessfully && debug){
            //    showSimulator = true;
            //}
        }
        
        if (showSimulator) {
            setSize (900, 726);
            //push2SimulatorComponent.setPush2Interface(&processor.engineWrapper->push);
            //addAndMakeVisible(push2SimulatorComponent);
        }
    #endif
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
    #if !ELK_BUILD
        #if JUCE_DEBUG
        //if (!processor.engineWrapper->push.pushInitializedSuccessfully) {
        //    push2SimulatorComponent.setBounds(getBounds());
        //}
        #endif
    #endif
}
