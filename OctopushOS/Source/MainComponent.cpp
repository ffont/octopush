/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainComponent::MainComponent()
{    
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (910, 160);
}

MainComponent::~MainComponent()
{
    push->removeActionListener(this);
}

void MainComponent::setPush2Interface(Push2Interface* push_)
{
    push = push_;
    push->addActionListener(this);  // Make MainComponent receive notifications from Push2 so it can update replicated display (for debug only)
}


//==============================================================================
void MainComponent::paint (Graphics& g)
{
    g.drawImageAt(push->lastFrame, 0, 0);
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}


//==============================================================================
void MainComponent::actionListenerCallback (const String &message)
{
    if (message == "NEW_FRAME_AVAILABLE")
    {
        repaint();
    }
}
