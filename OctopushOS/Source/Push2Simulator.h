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



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Push2Interface* push;
    double tempoSliderLastValue = 0.0;
    double swingSliderLastValue = 0.0;
    double e1SliderLastValue = 0.0;
    double e2SliderLastValue = 0.0;
    double e3SliderLastValue = 0.0;
    double e4SliderLastValue = 0.0;
    double e5SliderLastValue = 0.0;
    double e6SliderLastValue = 0.0;
    double e7SliderLastValue = 0.0;
    double e8SliderLastValue = 0.0;
    double masterSliderLastValue = 0.0;
    
    class CustomLookAndFeel: public LookAndFeel_V4
    {
    public:
        CustomLookAndFeel()
        {
            buttonFont = Typeface::createSystemTypefaceFor(Font());
            
            // Specify custom colors
            // Background window color specified in paint method to be 0xff151515
            Colour bgColour = Colour (0xff151515);
            setColour (TextButton::buttonColourId, bgColour.darker());
            setColour (Slider::thumbColourId, Colours::white);
            setColour (Slider::trackColourId , bgColour.brighter());
            setColour (Slider::backgroundColourId , bgColour.brighter());
            setColour (Slider::rotarySliderOutlineColourId , bgColour.brighter());
            setColour (Slider::rotarySliderFillColourId , bgColour.brighter());
        }
        
        ~CustomLookAndFeel()
        {
        }
        
        Font getTextButtonFont (TextButton&, int buttonHeight) override
        {
            Font font = Font(buttonFont);
            font.setHeight(12.0);
            return font;
        }
        
        Typeface::Ptr buttonFont;
    };
    
    CustomLookAndFeel customLookAndFeel;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<TextButton> tapTempoButton;
    std::unique_ptr<TextButton> metronomeButton;
    std::unique_ptr<TextButton> ba1Button;
    std::unique_ptr<TextButton> ba2Button;
    std::unique_ptr<TextButton> ba3Button;
    std::unique_ptr<TextButton> ba4Button;
    std::unique_ptr<TextButton> ba5Button;
    std::unique_ptr<TextButton> ba6Button;
    std::unique_ptr<TextButton> ba7Button;
    std::unique_ptr<TextButton> ba8Button;
    std::unique_ptr<TextButton> bb1Button;
    std::unique_ptr<TextButton> bb2Button;
    std::unique_ptr<TextButton> bb3Button;
    std::unique_ptr<TextButton> bb4Button;
    std::unique_ptr<TextButton> bb5Button;
    std::unique_ptr<TextButton> bb6Button;
    std::unique_ptr<TextButton> bb7Button;
    std::unique_ptr<TextButton> bb8Button;
    std::unique_ptr<Slider> touchstripSider;
    std::unique_ptr<Slider> tempoSlider;
    std::unique_ptr<Slider> swingSlider;
    std::unique_ptr<Slider> e1Slider;
    std::unique_ptr<Slider> e2Slider;
    std::unique_ptr<Slider> e3Slider;
    std::unique_ptr<Slider> e4Slider;
    std::unique_ptr<Slider> e5Slider;
    std::unique_ptr<Slider> e6Slider;
    std::unique_ptr<Slider> e7Slider;
    std::unique_ptr<Slider> e8Slider;
    std::unique_ptr<Slider> masterSlider;
    std::unique_ptr<Component> displayPlaceholder;
    std::unique_ptr<TextButton> setupButton;
    std::unique_ptr<TextButton> userButton;
    std::unique_ptr<TextButton> addDeviceButton;
    std::unique_ptr<TextButton> addTrackButton;
    std::unique_ptr<TextButton> deviceButton;
    std::unique_ptr<TextButton> browseButton;
    std::unique_ptr<TextButton> mixButton;
    std::unique_ptr<TextButton> clipButton;
    std::unique_ptr<TextButton> deleteButton;
    std::unique_ptr<TextButton> undoButton;
    std::unique_ptr<TextButton> repeatButton;
    std::unique_ptr<TextButton> accentButton;
    std::unique_ptr<TextButton> noteButton;
    std::unique_ptr<TextButton> sesstionButton;
    std::unique_ptr<TextButton> scaleButton;
    std::unique_ptr<TextButton> layoutButton;
    std::unique_ptr<TextButton> shiftButton;
    std::unique_ptr<TextButton> selectButton;
    std::unique_ptr<TextButton> muteButton;
    std::unique_ptr<TextButton> soloButton;
    std::unique_ptr<TextButton> stopClipButton;
    std::unique_ptr<TextButton> duplicateButton;
    std::unique_ptr<TextButton> newButton;
    std::unique_ptr<TextButton> convertButton;
    std::unique_ptr<TextButton> doubleLoopButton;
    std::unique_ptr<TextButton> quantizeButton;
    std::unique_ptr<TextButton> fixLengthButton;
    std::unique_ptr<TextButton> automateButton;
    std::unique_ptr<TextButton> recordButton;
    std::unique_ptr<TextButton> playButton;
    std::unique_ptr<TextButton> masterButton;
    std::unique_ptr<TextButton> _1_32tButton;
    std::unique_ptr<TextButton> _1_32Button;
    std::unique_ptr<TextButton> _1_16tButton;
    std::unique_ptr<TextButton> _1_16Button;
    std::unique_ptr<TextButton> _1_8tButton;
    std::unique_ptr<TextButton> _1_8Button;
    std::unique_ptr<TextButton> _1_4tButton;
    std::unique_ptr<TextButton> _1_4Button;
    std::unique_ptr<TextButton> arrowUpButton;
    std::unique_ptr<TextButton> rightArrowButton;
    std::unique_ptr<TextButton> leftArrowButton;
    std::unique_ptr<TextButton> downArrowButton;
    std::unique_ptr<TextButton> octaveUpButton;
    std::unique_ptr<TextButton> pageRightButton;
    std::unique_ptr<TextButton> pageLeftButton;
    std::unique_ptr<TextButton> octaveDownButton;
    std::unique_ptr<TextButton> nn92Pad;
    std::unique_ptr<TextButton> nn93Pad;
    std::unique_ptr<TextButton> nn94Pad;
    std::unique_ptr<TextButton> nn95Pad;
    std::unique_ptr<TextButton> nn96Pad;
    std::unique_ptr<TextButton> nn97Pad;
    std::unique_ptr<TextButton> nn98Pad;
    std::unique_ptr<TextButton> nn99Pad;
    std::unique_ptr<TextButton> nn84Pad;
    std::unique_ptr<TextButton> nn85Pad;
    std::unique_ptr<TextButton> nn86Pad;
    std::unique_ptr<TextButton> nn87Pad;
    std::unique_ptr<TextButton> nn88Pad;
    std::unique_ptr<TextButton> nn89Pad;
    std::unique_ptr<TextButton> nn90Pad;
    std::unique_ptr<TextButton> nn91Pad;
    std::unique_ptr<TextButton> nn76Pad;
    std::unique_ptr<TextButton> nn77Pad;
    std::unique_ptr<TextButton> nn78Pad;
    std::unique_ptr<TextButton> nn79Pad;
    std::unique_ptr<TextButton> nn80Pad;
    std::unique_ptr<TextButton> nn81Pad;
    std::unique_ptr<TextButton> nn82Pad;
    std::unique_ptr<TextButton> nn83Pad;
    std::unique_ptr<TextButton> nn68Pad;
    std::unique_ptr<TextButton> nn69Pad;
    std::unique_ptr<TextButton> nn70Pad;
    std::unique_ptr<TextButton> nn71Pad;
    std::unique_ptr<TextButton> nn72Pad;
    std::unique_ptr<TextButton> nn73Pad;
    std::unique_ptr<TextButton> nn74Pad;
    std::unique_ptr<TextButton> nn75Pad;
    std::unique_ptr<TextButton> nn60Pad;
    std::unique_ptr<TextButton> nn61Pad;
    std::unique_ptr<TextButton> nn62Pad;
    std::unique_ptr<TextButton> nn63Pad;
    std::unique_ptr<TextButton> nn64Pad;
    std::unique_ptr<TextButton> nn65Pad;
    std::unique_ptr<TextButton> nn66Pad;
    std::unique_ptr<TextButton> nn67Pad;
    std::unique_ptr<TextButton> nn52Pad;
    std::unique_ptr<TextButton> nn53Pad;
    std::unique_ptr<TextButton> nn54Pad;
    std::unique_ptr<TextButton> nn55Pad;
    std::unique_ptr<TextButton> nn56Pad;
    std::unique_ptr<TextButton> nn57Pad;
    std::unique_ptr<TextButton> nn58Pad;
    std::unique_ptr<TextButton> nn59Pad;
    std::unique_ptr<TextButton> nn44Pad;
    std::unique_ptr<TextButton> nn45Pad;
    std::unique_ptr<TextButton> nn46Pad;
    std::unique_ptr<TextButton> nn47Pad;
    std::unique_ptr<TextButton> nn48Pad;
    std::unique_ptr<TextButton> nn49Pad;
    std::unique_ptr<TextButton> nn50Pad;
    std::unique_ptr<TextButton> nn51Pad;
    std::unique_ptr<TextButton> nn36Pad;
    std::unique_ptr<TextButton> nn37Pad;
    std::unique_ptr<TextButton> nn38Pad;
    std::unique_ptr<TextButton> nn39Pad;
    std::unique_ptr<TextButton> nn40Pad;
    std::unique_ptr<TextButton> nn41Pad;
    std::unique_ptr<TextButton> nn42Pad;
    std::unique_ptr<TextButton> nn43Pad;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Push2Simulator)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

