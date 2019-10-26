/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.5

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "Push2Interface.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Push2Simulator  : public Component,
                        public ActionListener,
                        public Button::Listener,
                        public Slider::Listener
{
public:
    //==============================================================================
    Push2Simulator ();
    ~Push2Simulator();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setPush2Interface(Push2Interface* push_);
    void actionListenerCallback (const String &message) override;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;

    // Binary resources:
    static const char* midiMapping_png;
    static const int midiMapping_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Push2Interface* push;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<TextButton> tapTempoButton;
    std::unique_ptr<TextButton> metronomeButton2;
    std::unique_ptr<TextButton> cc102Button;
    std::unique_ptr<TextButton> cc103Button;
    std::unique_ptr<TextButton> cc104Button;
    std::unique_ptr<TextButton> cc105Button;
    std::unique_ptr<TextButton> cc107Button;
    std::unique_ptr<TextButton> cc108Button;
    std::unique_ptr<TextButton> cc109Button;
    std::unique_ptr<TextButton> cc20Button;
    std::unique_ptr<TextButton> cc21Button;
    std::unique_ptr<TextButton> cc22Button;
    std::unique_ptr<TextButton> cc23Button;
    std::unique_ptr<TextButton> cc24Button;
    std::unique_ptr<TextButton> cc25Button;
    std::unique_ptr<TextButton> cc26Button;
    std::unique_ptr<TextButton> cc27Button;
    std::unique_ptr<Slider> touchstripSider;
    std::unique_ptr<Slider> cc14Slider;
    std::unique_ptr<Slider> cc15Slider;
    std::unique_ptr<Slider> cc71Slider;
    std::unique_ptr<Slider> cc72Slider;
    std::unique_ptr<Slider> cc73Slider;
    std::unique_ptr<Slider> cc74Slider;
    std::unique_ptr<Slider> cc75Slider;
    std::unique_ptr<Slider> cc76Slider;
    std::unique_ptr<Slider> cc77Slider;
    std::unique_ptr<Slider> cc78Slider;
    std::unique_ptr<Slider> cc79Slider;
    std::unique_ptr<Component> displayPlaceholder;
    std::unique_ptr<TextButton> cc106Button;
    Image cachedImage_midiMapping_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Push2Simulator)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

