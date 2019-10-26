/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Push2Interface.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent: public Component,
                     public ActionListener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();
    
    void setPush2Interface(Push2Interface* push_);

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;
    
    //==============================================================================
    void actionListenerCallback (const String &message) override;

private:
    
    Push2Interface* push;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
