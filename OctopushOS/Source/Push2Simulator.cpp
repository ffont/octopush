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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "Push2Simulator.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Push2Simulator::Push2Simulator ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    tapTempoButton.reset (new TextButton ("tapTempo"));
    addAndMakeVisible (tapTempoButton.get());
    tapTempoButton->setButtonText (TRANS("Tap Tempo"));
    tapTempoButton->addListener (this);

    tapTempoButton->setBounds (8, 64, 64, 24);

    metronomeButton.reset (new TextButton ("metronome"));
    addAndMakeVisible (metronomeButton.get());
    metronomeButton->setButtonText (TRANS("Metro"));
    metronomeButton->addListener (this);

    metronomeButton->setBounds (72, 64, 64, 24);

    cc102Button.reset (new TextButton ("cc102"));
    addAndMakeVisible (cc102Button.get());
    cc102Button->addListener (this);

    cc102Button->setBounds (160, 64, 64, 24);

    cc103Button.reset (new TextButton ("cc103"));
    addAndMakeVisible (cc103Button.get());
    cc103Button->addListener (this);

    cc103Button->setBounds (229, 64, 64, 24);

    cc104Button.reset (new TextButton ("cc104"));
    addAndMakeVisible (cc104Button.get());
    cc104Button->addListener (this);

    cc104Button->setBounds (300, 64, 64, 24);

    cc105Button.reset (new TextButton ("cc105"));
    addAndMakeVisible (cc105Button.get());
    cc105Button->addListener (this);

    cc105Button->setBounds (368, 64, 64, 24);

    cc107Button.reset (new TextButton ("cc107"));
    addAndMakeVisible (cc107Button.get());
    cc107Button->addListener (this);

    cc107Button->setBounds (508, 64, 64, 24);

    cc108Button.reset (new TextButton ("cc108"));
    addAndMakeVisible (cc108Button.get());
    cc108Button->addListener (this);

    cc108Button->setBounds (578, 64, 64, 24);

    cc109Button.reset (new TextButton ("cc109"));
    addAndMakeVisible (cc109Button.get());
    cc109Button->addListener (this);

    cc109Button->setBounds (646, 64, 64, 24);

    cc20Button.reset (new TextButton ("cc20"));
    addAndMakeVisible (cc20Button.get());
    cc20Button->addListener (this);

    cc20Button->setBounds (160, 240, 64, 24);

    cc21Button.reset (new TextButton ("cc21"));
    addAndMakeVisible (cc21Button.get());
    cc21Button->addListener (this);

    cc21Button->setBounds (229, 240, 64, 24);

    cc22Button.reset (new TextButton ("cc22"));
    addAndMakeVisible (cc22Button.get());
    cc22Button->addListener (this);

    cc22Button->setBounds (300, 240, 64, 24);

    cc23Button.reset (new TextButton ("cc23"));
    addAndMakeVisible (cc23Button.get());
    cc23Button->addListener (this);

    cc23Button->setBounds (368, 240, 64, 24);

    cc24Button.reset (new TextButton ("cc24"));
    addAndMakeVisible (cc24Button.get());
    cc24Button->addListener (this);

    cc24Button->setBounds (438, 240, 64, 24);

    cc25Button.reset (new TextButton ("cc25"));
    addAndMakeVisible (cc25Button.get());
    cc25Button->addListener (this);

    cc25Button->setBounds (508, 240, 64, 24);

    cc26Button.reset (new TextButton ("cc26"));
    addAndMakeVisible (cc26Button.get());
    cc26Button->addListener (this);

    cc26Button->setBounds (578, 240, 64, 24);

    cc27Button.reset (new TextButton ("cc27"));
    addAndMakeVisible (cc27Button.get());
    cc27Button->addListener (this);

    cc27Button->setBounds (646, 240, 64, 24);

    touchstripSider.reset (new Slider ("touchstrip"));
    addAndMakeVisible (touchstripSider.get());
    touchstripSider->setRange (0, 10, 0);
    touchstripSider->setSliderStyle (Slider::LinearVertical);
    touchstripSider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    touchstripSider->addListener (this);

    touchstripSider->setBounds (80, 288, 48, 416);

    cc14Slider.reset (new Slider ("cc14"));
    addAndMakeVisible (cc14Slider.get());
    cc14Slider->setRange (0, 10, 0);
    cc14Slider->setSliderStyle (Slider::Rotary);
    cc14Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    cc14Slider->addListener (this);

    cc14Slider->setBounds (0, 0, 72, 56);

    cc15Slider.reset (new Slider ("cc15"));
    addAndMakeVisible (cc15Slider.get());
    cc15Slider->setRange (0, 10, 0);
    cc15Slider->setSliderStyle (Slider::Rotary);
    cc15Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    cc15Slider->addListener (this);

    cc15Slider->setBounds (72, 0, 72, 56);

    cc71Slider.reset (new Slider ("cc71"));
    addAndMakeVisible (cc71Slider.get());
    cc71Slider->setRange (0, 10, 0);
    cc71Slider->setSliderStyle (Slider::Rotary);
    cc71Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    cc71Slider->addListener (this);

    cc71Slider->setBounds (154, 0, 72, 56);

    cc72Slider.reset (new Slider ("cc72"));
    addAndMakeVisible (cc72Slider.get());
    cc72Slider->setRange (0, 10, 0);
    cc72Slider->setSliderStyle (Slider::Rotary);
    cc72Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    cc72Slider->addListener (this);

    cc72Slider->setBounds (224, 0, 72, 56);

    cc73Slider.reset (new Slider ("cc73"));
    addAndMakeVisible (cc73Slider.get());
    cc73Slider->setRange (0, 10, 0);
    cc73Slider->setSliderStyle (Slider::Rotary);
    cc73Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    cc73Slider->addListener (this);

    cc73Slider->setBounds (294, 0, 72, 56);

    cc74Slider.reset (new Slider ("cc74"));
    addAndMakeVisible (cc74Slider.get());
    cc74Slider->setRange (0, 10, 0);
    cc74Slider->setSliderStyle (Slider::Rotary);
    cc74Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    cc74Slider->addListener (this);

    cc74Slider->setBounds (364, 0, 72, 56);

    cc75Slider.reset (new Slider ("cc75"));
    addAndMakeVisible (cc75Slider.get());
    cc75Slider->setRange (0, 10, 0);
    cc75Slider->setSliderStyle (Slider::Rotary);
    cc75Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    cc75Slider->addListener (this);

    cc75Slider->setBounds (434, 0, 72, 56);

    cc76Slider.reset (new Slider ("cc76"));
    addAndMakeVisible (cc76Slider.get());
    cc76Slider->setRange (0, 10, 0);
    cc76Slider->setSliderStyle (Slider::Rotary);
    cc76Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    cc76Slider->addListener (this);

    cc76Slider->setBounds (504, 0, 72, 56);

    cc77Slider.reset (new Slider ("cc77"));
    addAndMakeVisible (cc77Slider.get());
    cc77Slider->setRange (0, 10, 0);
    cc77Slider->setSliderStyle (Slider::Rotary);
    cc77Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    cc77Slider->addListener (this);

    cc77Slider->setBounds (574, 0, 72, 56);

    cc78Slider.reset (new Slider ("cc78"));
    addAndMakeVisible (cc78Slider.get());
    cc78Slider->setRange (0, 10, 0);
    cc78Slider->setSliderStyle (Slider::Rotary);
    cc78Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    cc78Slider->addListener (this);

    cc78Slider->setBounds (644, 0, 72, 56);

    cc79Slider.reset (new Slider ("cc79"));
    addAndMakeVisible (cc79Slider.get());
    cc79Slider->setRange (0, 10, 0);
    cc79Slider->setSliderStyle (Slider::Rotary);
    cc79Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    cc79Slider->addListener (this);

    cc79Slider->setBounds (804, 0, 72, 56);

    displayPlaceholder.reset (new Component());
    addAndMakeVisible (displayPlaceholder.get());
    displayPlaceholder->setName ("display");

    displayPlaceholder->setBounds (156, 114, 555, 98);

    cc106Button.reset (new TextButton ("cc106"));
    addAndMakeVisible (cc106Button.get());
    cc106Button->addListener (this);

    cc106Button->setBounds (438, 64, 64, 24);

    setupButton.reset (new TextButton ("setup"));
    addAndMakeVisible (setupButton.get());
    setupButton->setButtonText (TRANS("Setup"));
    setupButton->addListener (this);

    setupButton->setBounds (792, 64, 48, 24);

    userButton.reset (new TextButton ("user"));
    addAndMakeVisible (userButton.get());
    userButton->setButtonText (TRANS("User"));
    userButton->addListener (this);

    userButton->setBounds (840, 64, 48, 24);

    addDeviceButton.reset (new TextButton ("addDevice"));
    addAndMakeVisible (addDeviceButton.get());
    addDeviceButton->setButtonText (TRANS("Add Device"));
    addDeviceButton->addListener (this);

    addDeviceButton->setBounds (736, 118, 45, 45);

    addTrackButton.reset (new TextButton ("addTrack"));
    addAndMakeVisible (addTrackButton.get());
    addTrackButton->setButtonText (TRANS("Add Track"));
    addTrackButton->addListener (this);

    addTrackButton->setBounds (736, 164, 45, 45);

    deviceButton.reset (new TextButton ("device"));
    addAndMakeVisible (deviceButton.get());
    deviceButton->setButtonText (TRANS("Device"));
    deviceButton->addListener (this);

    deviceButton->setBounds (796, 118, 45, 45);

    browseButton.reset (new TextButton ("browse"));
    addAndMakeVisible (browseButton.get());
    browseButton->setButtonText (TRANS("Browse"));
    browseButton->addListener (this);

    browseButton->setBounds (796, 164, 45, 45);

    mixButton.reset (new TextButton ("mix"));
    addAndMakeVisible (mixButton.get());
    mixButton->setButtonText (TRANS("Mix"));
    mixButton->addListener (this);

    mixButton->setBounds (843, 118, 45, 45);

    clipButton.reset (new TextButton ("clip"));
    addAndMakeVisible (clipButton.get());
    clipButton->setButtonText (TRANS("Clip"));
    clipButton->addListener (this);

    clipButton->setBounds (843, 164, 45, 45);

    deleteButton.reset (new TextButton ("delete"));
    addAndMakeVisible (deleteButton.get());
    deleteButton->setButtonText (TRANS("Delete"));
    deleteButton->addListener (this);

    deleteButton->setBounds (8, 118, 45, 45);

    undoButton.reset (new TextButton ("undo"));
    addAndMakeVisible (undoButton.get());
    undoButton->setButtonText (TRANS("Undo"));
    undoButton->addListener (this);

    undoButton->setBounds (8, 164, 45, 45);

    deviceButton2.reset (new TextButton ("device"));
    addAndMakeVisible (deviceButton2.get());
    deviceButton2->setButtonText (TRANS("Device"));
    deviceButton2->addListener (this);

    deviceButton2->setBounds (796, 446, 45, 45);

    mixButton2.reset (new TextButton ("mix"));
    addAndMakeVisible (mixButton2.get());
    mixButton2->setButtonText (TRANS("Mix"));
    mixButton2->addListener (this);

    mixButton2->setBounds (843, 446, 45, 45);

    deviceButton3.reset (new TextButton ("device"));
    addAndMakeVisible (deviceButton3.get());
    deviceButton3->setButtonText (TRANS("Device"));
    deviceButton3->addListener (this);

    deviceButton3->setBounds (796, 525, 45, 45);

    mixButton3.reset (new TextButton ("mix"));
    addAndMakeVisible (mixButton3.get());
    mixButton3->setButtonText (TRANS("Mix"));
    mixButton3->addListener (this);

    mixButton3->setBounds (843, 525, 45, 45);

    deviceButton4.reset (new TextButton ("device"));
    addAndMakeVisible (deviceButton4.get());
    deviceButton4->setButtonText (TRANS("Device"));
    deviceButton4->addListener (this);

    deviceButton4->setBounds (796, 496, 45, 27);

    mixButton4.reset (new TextButton ("mix"));
    addAndMakeVisible (mixButton4.get());
    mixButton4->setButtonText (TRANS("Mix"));
    mixButton4->addListener (this);

    mixButton4->setBounds (843, 496, 45, 27);

    deviceButton5.reset (new TextButton ("device"));
    addAndMakeVisible (deviceButton5.get());
    deviceButton5->setButtonText (TRANS("Device"));
    deviceButton5->addListener (this);

    deviceButton5->setBounds (796, 677, 45, 27);

    mixButton5.reset (new TextButton ("mix"));
    addAndMakeVisible (mixButton5.get());
    mixButton5->setButtonText (TRANS("Mix"));
    mixButton5->addListener (this);

    mixButton5->setBounds (843, 677, 45, 27);

    muteButton.reset (new TextButton ("mute"));
    addAndMakeVisible (muteButton.get());
    muteButton->setButtonText (TRANS("Mute"));
    muteButton->addListener (this);

    muteButton->setBounds (8, 240, 42, 27);

    soloButton.reset (new TextButton ("solo"));
    addAndMakeVisible (soloButton.get());
    soloButton->setButtonText (TRANS("Solo"));
    soloButton->addListener (this);

    soloButton->setBounds (50, 240, 42, 27);

    stopClipButton.reset (new TextButton ("stopClip"));
    addAndMakeVisible (stopClipButton.get());
    stopClipButton->setButtonText (TRANS("Stop Clip"));
    stopClipButton->addListener (this);

    stopClipButton->setBounds (92, 240, 42, 27);

    duplicateButton.reset (new TextButton ("duplicate"));
    addAndMakeVisible (duplicateButton.get());
    duplicateButton->setButtonText (TRANS("Duplicate"));
    duplicateButton->addListener (this);

    duplicateButton->setBounds (8, 425, 45, 45);

    newButton.reset (new TextButton ("new"));
    addAndMakeVisible (newButton.get());
    newButton->setButtonText (TRANS("New"));
    newButton->addListener (this);

    newButton->setBounds (8, 471, 45, 45);

    convertButton.reset (new TextButton ("delete"));
    addAndMakeVisible (convertButton.get());
    convertButton->setButtonText (TRANS("Delete"));
    convertButton->addListener (this);

    convertButton->setBounds (8, 286, 45, 43);

    doubleLoopButton.reset (new TextButton ("doubleLoop"));
    addAndMakeVisible (doubleLoopButton.get());
    doubleLoopButton->setButtonText (TRANS("Double Loop"));
    doubleLoopButton->addListener (this);

    doubleLoopButton->setBounds (8, 330, 45, 43);

    quantizeButton.reset (new TextButton ("quantize"));
    addAndMakeVisible (quantizeButton.get());
    quantizeButton->setButtonText (TRANS("Quantize"));
    quantizeButton->addListener (this);

    quantizeButton->setBounds (8, 374, 45, 43);

    fixLengthButton.reset (new TextButton ("fixLength"));
    addAndMakeVisible (fixLengthButton.get());
    fixLengthButton->setButtonText (TRANS("Fix Length"));
    fixLengthButton->addListener (this);

    fixLengthButton->setBounds (8, 524, 45, 42);

    automateButton.reset (new TextButton ("automate"));
    addAndMakeVisible (automateButton.get());
    automateButton->setButtonText (TRANS("Automate"));
    automateButton->addListener (this);

    automateButton->setBounds (8, 566, 45, 42);

    recordButton.reset (new TextButton ("record"));
    addAndMakeVisible (recordButton.get());
    recordButton->setButtonText (TRANS("Record"));
    recordButton->addListener (this);

    recordButton->setBounds (8, 608, 45, 42);

    playButton.reset (new TextButton ("play"));
    addAndMakeVisible (playButton.get());
    playButton->setButtonText (TRANS("Play"));
    playButton->addListener (this);

    playButton->setBounds (8, 658, 45, 45);

    masterButton.reset (new TextButton ("master"));
    addAndMakeVisible (masterButton.get());
    masterButton->setButtonText (TRANS("Master"));
    masterButton->addListener (this);

    masterButton->setBounds (736, 240, 45, 27);

    browseButton2.reset (new TextButton ("browse"));
    addAndMakeVisible (browseButton2.get());
    browseButton2->setButtonText (TRANS("Browse"));
    browseButton2->addListener (this);

    browseButton2->setBounds (736, 286, 45, 45);

    browseButton3.reset (new TextButton ("browse"));
    addAndMakeVisible (browseButton3.get());
    browseButton3->setButtonText (TRANS("Browse"));
    browseButton3->addListener (this);

    browseButton3->setBounds (736, 338, 45, 45);

    browseButton4.reset (new TextButton ("browse"));
    addAndMakeVisible (browseButton4.get());
    browseButton4->setButtonText (TRANS("Browse"));
    browseButton4->addListener (this);

    browseButton4->setBounds (736, 393, 45, 45);

    browseButton5.reset (new TextButton ("browse"));
    addAndMakeVisible (browseButton5.get());
    browseButton5->setButtonText (TRANS("Browse"));
    browseButton5->addListener (this);

    browseButton5->setBounds (736, 445, 45, 45);

    browseButton6.reset (new TextButton ("browse"));
    addAndMakeVisible (browseButton6.get());
    browseButton6->setButtonText (TRANS("Browse"));
    browseButton6->addListener (this);

    browseButton6->setBounds (736, 498, 45, 45);

    browseButton7.reset (new TextButton ("browse"));
    addAndMakeVisible (browseButton7.get());
    browseButton7->setButtonText (TRANS("Browse"));
    browseButton7->addListener (this);

    browseButton7->setBounds (736, 551, 45, 45);

    browseButton8.reset (new TextButton ("browse"));
    addAndMakeVisible (browseButton8.get());
    browseButton8->setButtonText (TRANS("Browse"));
    browseButton8->addListener (this);

    browseButton8->setBounds (736, 605, 45, 45);

    browseButton9.reset (new TextButton ("browse"));
    addAndMakeVisible (browseButton9.get());
    browseButton9->setButtonText (TRANS("Browse"));
    browseButton9->addListener (this);

    browseButton9->setBounds (736, 657, 45, 45);

    arrowUpButton.reset (new TextButton ("arrowUp"));
    addAndMakeVisible (arrowUpButton.get());
    arrowUpButton->setButtonText (CharPointer_UTF8 ("\xe2\x86\x91"));
    arrowUpButton->addListener (this);

    arrowUpButton->setBounds (828, 239, 28, 28);

    rightArrowButton.reset (new TextButton ("rightArrow"));
    addAndMakeVisible (rightArrowButton.get());
    rightArrowButton->setButtonText (CharPointer_UTF8 ("\xe2\x86\x92"));
    rightArrowButton->addListener (this);

    rightArrowButton->setBounds (860, 271, 28, 28);

    leftArrowButton.reset (new TextButton ("leftArrow"));
    addAndMakeVisible (leftArrowButton.get());
    leftArrowButton->setButtonText (CharPointer_UTF8 ("\xe2\x86\x90"));
    leftArrowButton->addListener (this);

    leftArrowButton->setBounds (796, 271, 28, 28);

    downArrowButton.reset (new TextButton ("downArrow"));
    addAndMakeVisible (downArrowButton.get());
    downArrowButton->setButtonText (CharPointer_UTF8 ("\xe2\x86\x93"));
    downArrowButton->addListener (this);

    downArrowButton->setBounds (828, 303, 28, 28);

    deviceButton14.reset (new TextButton ("device"));
    addAndMakeVisible (deviceButton14.get());
    deviceButton14->setButtonText (TRANS("Device"));
    deviceButton14->addListener (this);

    deviceButton14->setBounds (828, 577, 28, 28);

    deviceButton15.reset (new TextButton ("device"));
    addAndMakeVisible (deviceButton15.get());
    deviceButton15->setButtonText (TRANS("Device"));
    deviceButton15->addListener (this);

    deviceButton15->setBounds (860, 609, 28, 28);

    deviceButton16.reset (new TextButton ("device"));
    addAndMakeVisible (deviceButton16.get());
    deviceButton16->setButtonText (TRANS("Device"));
    deviceButton16->addListener (this);

    deviceButton16->setBounds (796, 609, 28, 28);

    deviceButton17.reset (new TextButton ("device"));
    addAndMakeVisible (deviceButton17.get());
    deviceButton17->setButtonText (TRANS("Device"));
    deviceButton17->addListener (this);

    deviceButton17->setBounds (828, 641, 28, 28);

    nn92Pad.reset (new TextButton ("nn92"));
    addAndMakeVisible (nn92Pad.get());
    nn92Pad->addListener (this);

    nn92Pad->setBounds (160, 286, 62, 44);

    nn93Pad.reset (new TextButton ("nn93"));
    addAndMakeVisible (nn93Pad.get());
    nn93Pad->addListener (this);

    nn93Pad->setBounds (230, 286, 62, 44);

    nn94Pad.reset (new TextButton ("nn94"));
    addAndMakeVisible (nn94Pad.get());
    nn94Pad->addListener (this);

    nn94Pad->setBounds (299, 286, 62, 44);

    nn95Pad.reset (new TextButton ("nn95"));
    addAndMakeVisible (nn95Pad.get());
    nn95Pad->addListener (this);

    nn95Pad->setBounds (369, 286, 62, 44);

    nn96Pad.reset (new TextButton ("nn96"));
    addAndMakeVisible (nn96Pad.get());
    nn96Pad->addListener (this);

    nn96Pad->setBounds (438, 286, 62, 44);

    nn97Pad.reset (new TextButton ("nn97"));
    addAndMakeVisible (nn97Pad.get());
    nn97Pad->addListener (this);

    nn97Pad->setBounds (508, 286, 62, 44);

    nn98Pad.reset (new TextButton ("nn98"));
    addAndMakeVisible (nn98Pad.get());
    nn98Pad->addListener (this);

    nn98Pad->setBounds (577, 286, 62, 44);

    nn99Pad.reset (new TextButton ("nn99"));
    addAndMakeVisible (nn99Pad.get());
    nn99Pad->addListener (this);

    nn99Pad->setBounds (647, 286, 62, 44);

    nn84Pad.reset (new TextButton ("nn84"));
    addAndMakeVisible (nn84Pad.get());
    nn84Pad->addListener (this);

    nn84Pad->setBounds (160, 339, 62, 44);

    nn85Pad.reset (new TextButton ("nn85"));
    addAndMakeVisible (nn85Pad.get());
    nn85Pad->addListener (this);

    nn85Pad->setBounds (230, 339, 62, 44);

    nn86Pad.reset (new TextButton ("nn86"));
    addAndMakeVisible (nn86Pad.get());
    nn86Pad->addListener (this);

    nn86Pad->setBounds (299, 339, 62, 44);

    nn87Pad.reset (new TextButton ("nn87"));
    addAndMakeVisible (nn87Pad.get());
    nn87Pad->addListener (this);

    nn87Pad->setBounds (369, 339, 62, 44);

    nn88Pad.reset (new TextButton ("nn88"));
    addAndMakeVisible (nn88Pad.get());
    nn88Pad->addListener (this);

    nn88Pad->setBounds (438, 339, 62, 44);

    nn89Pad.reset (new TextButton ("nn89"));
    addAndMakeVisible (nn89Pad.get());
    nn89Pad->addListener (this);

    nn89Pad->setBounds (508, 339, 62, 44);

    nn90Pad.reset (new TextButton ("nn90"));
    addAndMakeVisible (nn90Pad.get());
    nn90Pad->addListener (this);

    nn90Pad->setBounds (577, 339, 62, 44);

    nn91Pad.reset (new TextButton ("nn91"));
    addAndMakeVisible (nn91Pad.get());
    nn91Pad->addListener (this);

    nn91Pad->setBounds (647, 339, 62, 44);

    nn76Pad.reset (new TextButton ("nn76"));
    addAndMakeVisible (nn76Pad.get());
    nn76Pad->addListener (this);

    nn76Pad->setBounds (160, 392, 62, 44);

    nn77Pad.reset (new TextButton ("nn77"));
    addAndMakeVisible (nn77Pad.get());
    nn77Pad->addListener (this);

    nn77Pad->setBounds (230, 392, 62, 44);

    nn78Pad.reset (new TextButton ("nn78"));
    addAndMakeVisible (nn78Pad.get());
    nn78Pad->addListener (this);

    nn78Pad->setBounds (299, 392, 62, 44);

    nn79Pad.reset (new TextButton ("nn79"));
    addAndMakeVisible (nn79Pad.get());
    nn79Pad->addListener (this);

    nn79Pad->setBounds (369, 392, 62, 44);

    nn80Pad.reset (new TextButton ("nn80"));
    addAndMakeVisible (nn80Pad.get());
    nn80Pad->addListener (this);

    nn80Pad->setBounds (438, 392, 62, 44);

    nn81Pad.reset (new TextButton ("nn81"));
    addAndMakeVisible (nn81Pad.get());
    nn81Pad->addListener (this);

    nn81Pad->setBounds (508, 392, 62, 44);

    nn82Pad.reset (new TextButton ("nn82"));
    addAndMakeVisible (nn82Pad.get());
    nn82Pad->addListener (this);

    nn82Pad->setBounds (577, 392, 62, 44);

    nn83Pad.reset (new TextButton ("nn83"));
    addAndMakeVisible (nn83Pad.get());
    nn83Pad->addListener (this);

    nn83Pad->setBounds (647, 392, 62, 44);

    nn68Pad.reset (new TextButton ("nn68"));
    addAndMakeVisible (nn68Pad.get());
    nn68Pad->addListener (this);

    nn68Pad->setBounds (160, 445, 62, 44);

    nn69Pad.reset (new TextButton ("nn69"));
    addAndMakeVisible (nn69Pad.get());
    nn69Pad->addListener (this);

    nn69Pad->setBounds (230, 445, 62, 44);

    nn70Pad.reset (new TextButton ("nn70"));
    addAndMakeVisible (nn70Pad.get());
    nn70Pad->addListener (this);

    nn70Pad->setBounds (299, 445, 62, 44);

    nn71Pad.reset (new TextButton ("nn71"));
    addAndMakeVisible (nn71Pad.get());
    nn71Pad->addListener (this);

    nn71Pad->setBounds (369, 445, 62, 44);

    nn72Pad.reset (new TextButton ("nn72"));
    addAndMakeVisible (nn72Pad.get());
    nn72Pad->addListener (this);

    nn72Pad->setBounds (438, 445, 62, 44);

    nn73Pad.reset (new TextButton ("nn73"));
    addAndMakeVisible (nn73Pad.get());
    nn73Pad->addListener (this);

    nn73Pad->setBounds (508, 445, 62, 44);

    nn74Pad.reset (new TextButton ("nn74"));
    addAndMakeVisible (nn74Pad.get());
    nn74Pad->addListener (this);

    nn74Pad->setBounds (577, 445, 62, 44);

    nn75Pad.reset (new TextButton ("nn75"));
    addAndMakeVisible (nn75Pad.get());
    nn75Pad->addListener (this);

    nn75Pad->setBounds (647, 445, 62, 44);

    nn60Pad.reset (new TextButton ("nn60"));
    addAndMakeVisible (nn60Pad.get());
    nn60Pad->addListener (this);

    nn60Pad->setBounds (160, 499, 62, 44);

    nn61Pad.reset (new TextButton ("nn61"));
    addAndMakeVisible (nn61Pad.get());
    nn61Pad->addListener (this);

    nn61Pad->setBounds (230, 499, 62, 44);

    nn62Pad.reset (new TextButton ("nn62"));
    addAndMakeVisible (nn62Pad.get());
    nn62Pad->addListener (this);

    nn62Pad->setBounds (299, 499, 62, 44);

    nn63Pad.reset (new TextButton ("nn63"));
    addAndMakeVisible (nn63Pad.get());
    nn63Pad->addListener (this);

    nn63Pad->setBounds (369, 499, 62, 44);

    nn64Pad.reset (new TextButton ("nn64"));
    addAndMakeVisible (nn64Pad.get());
    nn64Pad->addListener (this);

    nn64Pad->setBounds (438, 499, 62, 44);

    nn65Pad.reset (new TextButton ("nn65"));
    addAndMakeVisible (nn65Pad.get());
    nn65Pad->addListener (this);

    nn65Pad->setBounds (508, 499, 62, 44);

    nn66Pad.reset (new TextButton ("nn66"));
    addAndMakeVisible (nn66Pad.get());
    nn66Pad->addListener (this);

    nn66Pad->setBounds (577, 499, 62, 44);

    nn67Pad.reset (new TextButton ("nn67"));
    addAndMakeVisible (nn67Pad.get());
    nn67Pad->addListener (this);

    nn67Pad->setBounds (647, 499, 62, 44);

    nn52Pad.reset (new TextButton ("nn52"));
    addAndMakeVisible (nn52Pad.get());
    nn52Pad->addListener (this);

    nn52Pad->setBounds (160, 552, 62, 44);

    nn53Pad.reset (new TextButton ("nn53"));
    addAndMakeVisible (nn53Pad.get());
    nn53Pad->addListener (this);

    nn53Pad->setBounds (230, 552, 62, 44);

    nn54Pad.reset (new TextButton ("nn54"));
    addAndMakeVisible (nn54Pad.get());
    nn54Pad->addListener (this);

    nn54Pad->setBounds (299, 552, 62, 44);

    nn55Pad.reset (new TextButton ("nn55"));
    addAndMakeVisible (nn55Pad.get());
    nn55Pad->addListener (this);

    nn55Pad->setBounds (369, 552, 62, 44);

    nn56Pad.reset (new TextButton ("nn56"));
    addAndMakeVisible (nn56Pad.get());
    nn56Pad->addListener (this);

    nn56Pad->setBounds (438, 552, 62, 44);

    nn57Pad.reset (new TextButton ("nn57"));
    addAndMakeVisible (nn57Pad.get());
    nn57Pad->addListener (this);

    nn57Pad->setBounds (508, 552, 62, 44);

    nn58Pad.reset (new TextButton ("nn58"));
    addAndMakeVisible (nn58Pad.get());
    nn58Pad->addListener (this);

    nn58Pad->setBounds (577, 552, 62, 44);

    nn59Pad.reset (new TextButton ("nn59"));
    addAndMakeVisible (nn59Pad.get());
    nn59Pad->addListener (this);

    nn59Pad->setBounds (647, 552, 62, 44);

    nn44Pad.reset (new TextButton ("nn44"));
    addAndMakeVisible (nn44Pad.get());
    nn44Pad->addListener (this);

    nn44Pad->setBounds (160, 605, 62, 44);

    nn45Pad.reset (new TextButton ("nn45"));
    addAndMakeVisible (nn45Pad.get());
    nn45Pad->addListener (this);

    nn45Pad->setBounds (230, 605, 62, 44);

    nn46Pad.reset (new TextButton ("nn46"));
    addAndMakeVisible (nn46Pad.get());
    nn46Pad->addListener (this);

    nn46Pad->setBounds (299, 605, 62, 44);

    nn47Pad.reset (new TextButton ("nn47"));
    addAndMakeVisible (nn47Pad.get());
    nn47Pad->addListener (this);

    nn47Pad->setBounds (369, 605, 62, 44);

    nn48Pad.reset (new TextButton ("nn48"));
    addAndMakeVisible (nn48Pad.get());
    nn48Pad->addListener (this);

    nn48Pad->setBounds (438, 605, 62, 44);

    nn49Pad.reset (new TextButton ("nn49"));
    addAndMakeVisible (nn49Pad.get());
    nn49Pad->addListener (this);

    nn49Pad->setBounds (508, 605, 62, 44);

    nn50Pad.reset (new TextButton ("nn50"));
    addAndMakeVisible (nn50Pad.get());
    nn50Pad->addListener (this);

    nn50Pad->setBounds (577, 605, 62, 44);

    nn51Pad.reset (new TextButton ("nn51"));
    addAndMakeVisible (nn51Pad.get());
    nn51Pad->addListener (this);

    nn51Pad->setBounds (647, 605, 62, 44);

    nn36Pad.reset (new TextButton ("nn36"));
    addAndMakeVisible (nn36Pad.get());
    nn36Pad->setButtonText (TRANS("n36"));
    nn36Pad->addListener (this);

    nn36Pad->setBounds (160, 658, 62, 44);

    nn37Pad.reset (new TextButton ("nn37"));
    addAndMakeVisible (nn37Pad.get());
    nn37Pad->addListener (this);

    nn37Pad->setBounds (230, 658, 62, 44);

    nn38Pad.reset (new TextButton ("nn38"));
    addAndMakeVisible (nn38Pad.get());
    nn38Pad->addListener (this);

    nn38Pad->setBounds (299, 658, 62, 44);

    nn39Pad.reset (new TextButton ("nn39"));
    addAndMakeVisible (nn39Pad.get());
    nn39Pad->addListener (this);

    nn39Pad->setBounds (369, 658, 62, 44);

    nn40Pad.reset (new TextButton ("nn40"));
    addAndMakeVisible (nn40Pad.get());
    nn40Pad->addListener (this);

    nn40Pad->setBounds (438, 658, 62, 44);

    nn41Pad.reset (new TextButton ("nn41"));
    addAndMakeVisible (nn41Pad.get());
    nn41Pad->addListener (this);

    nn41Pad->setBounds (508, 658, 62, 44);

    nn42Pad.reset (new TextButton ("nn42"));
    addAndMakeVisible (nn42Pad.get());
    nn42Pad->addListener (this);

    nn42Pad->setBounds (577, 658, 62, 44);

    nn43Pad.reset (new TextButton ("nn43"));
    addAndMakeVisible (nn43Pad.get());
    nn43Pad->addListener (this);

    nn43Pad->setBounds (647, 658, 62, 44);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (900, 726);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

Push2Simulator::~Push2Simulator()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    tapTempoButton = nullptr;
    metronomeButton = nullptr;
    cc102Button = nullptr;
    cc103Button = nullptr;
    cc104Button = nullptr;
    cc105Button = nullptr;
    cc107Button = nullptr;
    cc108Button = nullptr;
    cc109Button = nullptr;
    cc20Button = nullptr;
    cc21Button = nullptr;
    cc22Button = nullptr;
    cc23Button = nullptr;
    cc24Button = nullptr;
    cc25Button = nullptr;
    cc26Button = nullptr;
    cc27Button = nullptr;
    touchstripSider = nullptr;
    cc14Slider = nullptr;
    cc15Slider = nullptr;
    cc71Slider = nullptr;
    cc72Slider = nullptr;
    cc73Slider = nullptr;
    cc74Slider = nullptr;
    cc75Slider = nullptr;
    cc76Slider = nullptr;
    cc77Slider = nullptr;
    cc78Slider = nullptr;
    cc79Slider = nullptr;
    displayPlaceholder = nullptr;
    cc106Button = nullptr;
    setupButton = nullptr;
    userButton = nullptr;
    addDeviceButton = nullptr;
    addTrackButton = nullptr;
    deviceButton = nullptr;
    browseButton = nullptr;
    mixButton = nullptr;
    clipButton = nullptr;
    deleteButton = nullptr;
    undoButton = nullptr;
    deviceButton2 = nullptr;
    mixButton2 = nullptr;
    deviceButton3 = nullptr;
    mixButton3 = nullptr;
    deviceButton4 = nullptr;
    mixButton4 = nullptr;
    deviceButton5 = nullptr;
    mixButton5 = nullptr;
    muteButton = nullptr;
    soloButton = nullptr;
    stopClipButton = nullptr;
    duplicateButton = nullptr;
    newButton = nullptr;
    convertButton = nullptr;
    doubleLoopButton = nullptr;
    quantizeButton = nullptr;
    fixLengthButton = nullptr;
    automateButton = nullptr;
    recordButton = nullptr;
    playButton = nullptr;
    masterButton = nullptr;
    browseButton2 = nullptr;
    browseButton3 = nullptr;
    browseButton4 = nullptr;
    browseButton5 = nullptr;
    browseButton6 = nullptr;
    browseButton7 = nullptr;
    browseButton8 = nullptr;
    browseButton9 = nullptr;
    arrowUpButton = nullptr;
    rightArrowButton = nullptr;
    leftArrowButton = nullptr;
    downArrowButton = nullptr;
    deviceButton14 = nullptr;
    deviceButton15 = nullptr;
    deviceButton16 = nullptr;
    deviceButton17 = nullptr;
    nn92Pad = nullptr;
    nn93Pad = nullptr;
    nn94Pad = nullptr;
    nn95Pad = nullptr;
    nn96Pad = nullptr;
    nn97Pad = nullptr;
    nn98Pad = nullptr;
    nn99Pad = nullptr;
    nn84Pad = nullptr;
    nn85Pad = nullptr;
    nn86Pad = nullptr;
    nn87Pad = nullptr;
    nn88Pad = nullptr;
    nn89Pad = nullptr;
    nn90Pad = nullptr;
    nn91Pad = nullptr;
    nn76Pad = nullptr;
    nn77Pad = nullptr;
    nn78Pad = nullptr;
    nn79Pad = nullptr;
    nn80Pad = nullptr;
    nn81Pad = nullptr;
    nn82Pad = nullptr;
    nn83Pad = nullptr;
    nn68Pad = nullptr;
    nn69Pad = nullptr;
    nn70Pad = nullptr;
    nn71Pad = nullptr;
    nn72Pad = nullptr;
    nn73Pad = nullptr;
    nn74Pad = nullptr;
    nn75Pad = nullptr;
    nn60Pad = nullptr;
    nn61Pad = nullptr;
    nn62Pad = nullptr;
    nn63Pad = nullptr;
    nn64Pad = nullptr;
    nn65Pad = nullptr;
    nn66Pad = nullptr;
    nn67Pad = nullptr;
    nn52Pad = nullptr;
    nn53Pad = nullptr;
    nn54Pad = nullptr;
    nn55Pad = nullptr;
    nn56Pad = nullptr;
    nn57Pad = nullptr;
    nn58Pad = nullptr;
    nn59Pad = nullptr;
    nn44Pad = nullptr;
    nn45Pad = nullptr;
    nn46Pad = nullptr;
    nn47Pad = nullptr;
    nn48Pad = nullptr;
    nn49Pad = nullptr;
    nn50Pad = nullptr;
    nn51Pad = nullptr;
    nn36Pad = nullptr;
    nn37Pad = nullptr;
    nn38Pad = nullptr;
    nn39Pad = nullptr;
    nn40Pad = nullptr;
    nn41Pad = nullptr;
    nn42Pad = nullptr;
    nn43Pad = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Push2Simulator::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    g.drawImage(push->lastFrame, displayPlaceholder.get()->getBounds().toFloat());
    //[/UserPaint]
}

void Push2Simulator::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Push2Simulator::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == tapTempoButton.get())
    {
        //[UserButtonCode_tapTempoButton] -- add your button handler code here..
        //[/UserButtonCode_tapTempoButton]
    }
    else if (buttonThatWasClicked == metronomeButton.get())
    {
        //[UserButtonCode_metronomeButton] -- add your button handler code here..
        //[/UserButtonCode_metronomeButton]
    }
    else if (buttonThatWasClicked == cc102Button.get())
    {
        //[UserButtonCode_cc102Button] -- add your button handler code here..
        //[/UserButtonCode_cc102Button]
    }
    else if (buttonThatWasClicked == cc103Button.get())
    {
        //[UserButtonCode_cc103Button] -- add your button handler code here..
        //[/UserButtonCode_cc103Button]
    }
    else if (buttonThatWasClicked == cc104Button.get())
    {
        //[UserButtonCode_cc104Button] -- add your button handler code here..
        //[/UserButtonCode_cc104Button]
    }
    else if (buttonThatWasClicked == cc105Button.get())
    {
        //[UserButtonCode_cc105Button] -- add your button handler code here..
        //[/UserButtonCode_cc105Button]
    }
    else if (buttonThatWasClicked == cc107Button.get())
    {
        //[UserButtonCode_cc107Button] -- add your button handler code here..
        //[/UserButtonCode_cc107Button]
    }
    else if (buttonThatWasClicked == cc108Button.get())
    {
        //[UserButtonCode_cc108Button] -- add your button handler code here..
        //[/UserButtonCode_cc108Button]
    }
    else if (buttonThatWasClicked == cc109Button.get())
    {
        //[UserButtonCode_cc109Button] -- add your button handler code here..
        //[/UserButtonCode_cc109Button]
    }
    else if (buttonThatWasClicked == cc20Button.get())
    {
        //[UserButtonCode_cc20Button] -- add your button handler code here..
        //[/UserButtonCode_cc20Button]
    }
    else if (buttonThatWasClicked == cc21Button.get())
    {
        //[UserButtonCode_cc21Button] -- add your button handler code here..
        //[/UserButtonCode_cc21Button]
    }
    else if (buttonThatWasClicked == cc22Button.get())
    {
        //[UserButtonCode_cc22Button] -- add your button handler code here..
        //[/UserButtonCode_cc22Button]
    }
    else if (buttonThatWasClicked == cc23Button.get())
    {
        //[UserButtonCode_cc23Button] -- add your button handler code here..
        //[/UserButtonCode_cc23Button]
    }
    else if (buttonThatWasClicked == cc24Button.get())
    {
        //[UserButtonCode_cc24Button] -- add your button handler code here..
        //[/UserButtonCode_cc24Button]
    }
    else if (buttonThatWasClicked == cc25Button.get())
    {
        //[UserButtonCode_cc25Button] -- add your button handler code here..
        //[/UserButtonCode_cc25Button]
    }
    else if (buttonThatWasClicked == cc26Button.get())
    {
        //[UserButtonCode_cc26Button] -- add your button handler code here..
        //[/UserButtonCode_cc26Button]
    }
    else if (buttonThatWasClicked == cc27Button.get())
    {
        //[UserButtonCode_cc27Button] -- add your button handler code here..
        //[/UserButtonCode_cc27Button]
    }
    else if (buttonThatWasClicked == cc106Button.get())
    {
        //[UserButtonCode_cc106Button] -- add your button handler code here..
        //[/UserButtonCode_cc106Button]
    }
    else if (buttonThatWasClicked == setupButton.get())
    {
        //[UserButtonCode_setupButton] -- add your button handler code here..
        //[/UserButtonCode_setupButton]
    }
    else if (buttonThatWasClicked == userButton.get())
    {
        //[UserButtonCode_userButton] -- add your button handler code here..
        //[/UserButtonCode_userButton]
    }
    else if (buttonThatWasClicked == addDeviceButton.get())
    {
        //[UserButtonCode_addDeviceButton] -- add your button handler code here..
        //[/UserButtonCode_addDeviceButton]
    }
    else if (buttonThatWasClicked == addTrackButton.get())
    {
        //[UserButtonCode_addTrackButton] -- add your button handler code here..
        //[/UserButtonCode_addTrackButton]
    }
    else if (buttonThatWasClicked == deviceButton.get())
    {
        //[UserButtonCode_deviceButton] -- add your button handler code here..
        //[/UserButtonCode_deviceButton]
    }
    else if (buttonThatWasClicked == browseButton.get())
    {
        //[UserButtonCode_browseButton] -- add your button handler code here..
        //[/UserButtonCode_browseButton]
    }
    else if (buttonThatWasClicked == mixButton.get())
    {
        //[UserButtonCode_mixButton] -- add your button handler code here..
        //[/UserButtonCode_mixButton]
    }
    else if (buttonThatWasClicked == clipButton.get())
    {
        //[UserButtonCode_clipButton] -- add your button handler code here..
        //[/UserButtonCode_clipButton]
    }
    else if (buttonThatWasClicked == deleteButton.get())
    {
        //[UserButtonCode_deleteButton] -- add your button handler code here..
        //[/UserButtonCode_deleteButton]
    }
    else if (buttonThatWasClicked == undoButton.get())
    {
        //[UserButtonCode_undoButton] -- add your button handler code here..
        //[/UserButtonCode_undoButton]
    }
    else if (buttonThatWasClicked == deviceButton2.get())
    {
        //[UserButtonCode_deviceButton2] -- add your button handler code here..
        //[/UserButtonCode_deviceButton2]
    }
    else if (buttonThatWasClicked == mixButton2.get())
    {
        //[UserButtonCode_mixButton2] -- add your button handler code here..
        //[/UserButtonCode_mixButton2]
    }
    else if (buttonThatWasClicked == deviceButton3.get())
    {
        //[UserButtonCode_deviceButton3] -- add your button handler code here..
        //[/UserButtonCode_deviceButton3]
    }
    else if (buttonThatWasClicked == mixButton3.get())
    {
        //[UserButtonCode_mixButton3] -- add your button handler code here..
        //[/UserButtonCode_mixButton3]
    }
    else if (buttonThatWasClicked == deviceButton4.get())
    {
        //[UserButtonCode_deviceButton4] -- add your button handler code here..
        //[/UserButtonCode_deviceButton4]
    }
    else if (buttonThatWasClicked == mixButton4.get())
    {
        //[UserButtonCode_mixButton4] -- add your button handler code here..
        //[/UserButtonCode_mixButton4]
    }
    else if (buttonThatWasClicked == deviceButton5.get())
    {
        //[UserButtonCode_deviceButton5] -- add your button handler code here..
        //[/UserButtonCode_deviceButton5]
    }
    else if (buttonThatWasClicked == mixButton5.get())
    {
        //[UserButtonCode_mixButton5] -- add your button handler code here..
        //[/UserButtonCode_mixButton5]
    }
    else if (buttonThatWasClicked == muteButton.get())
    {
        //[UserButtonCode_muteButton] -- add your button handler code here..
        //[/UserButtonCode_muteButton]
    }
    else if (buttonThatWasClicked == soloButton.get())
    {
        //[UserButtonCode_soloButton] -- add your button handler code here..
        //[/UserButtonCode_soloButton]
    }
    else if (buttonThatWasClicked == stopClipButton.get())
    {
        //[UserButtonCode_stopClipButton] -- add your button handler code here..
        //[/UserButtonCode_stopClipButton]
    }
    else if (buttonThatWasClicked == duplicateButton.get())
    {
        //[UserButtonCode_duplicateButton] -- add your button handler code here..
        //[/UserButtonCode_duplicateButton]
    }
    else if (buttonThatWasClicked == newButton.get())
    {
        //[UserButtonCode_newButton] -- add your button handler code here..
        //[/UserButtonCode_newButton]
    }
    else if (buttonThatWasClicked == convertButton.get())
    {
        //[UserButtonCode_convertButton] -- add your button handler code here..
        //[/UserButtonCode_convertButton]
    }
    else if (buttonThatWasClicked == doubleLoopButton.get())
    {
        //[UserButtonCode_doubleLoopButton] -- add your button handler code here..
        //[/UserButtonCode_doubleLoopButton]
    }
    else if (buttonThatWasClicked == quantizeButton.get())
    {
        //[UserButtonCode_quantizeButton] -- add your button handler code here..
        //[/UserButtonCode_quantizeButton]
    }
    else if (buttonThatWasClicked == fixLengthButton.get())
    {
        //[UserButtonCode_fixLengthButton] -- add your button handler code here..
        //[/UserButtonCode_fixLengthButton]
    }
    else if (buttonThatWasClicked == automateButton.get())
    {
        //[UserButtonCode_automateButton] -- add your button handler code here..
        //[/UserButtonCode_automateButton]
    }
    else if (buttonThatWasClicked == recordButton.get())
    {
        //[UserButtonCode_recordButton] -- add your button handler code here..
        //[/UserButtonCode_recordButton]
    }
    else if (buttonThatWasClicked == playButton.get())
    {
        //[UserButtonCode_playButton] -- add your button handler code here..
        //[/UserButtonCode_playButton]
    }
    else if (buttonThatWasClicked == masterButton.get())
    {
        //[UserButtonCode_masterButton] -- add your button handler code here..
        //[/UserButtonCode_masterButton]
    }
    else if (buttonThatWasClicked == browseButton2.get())
    {
        //[UserButtonCode_browseButton2] -- add your button handler code here..
        //[/UserButtonCode_browseButton2]
    }
    else if (buttonThatWasClicked == browseButton3.get())
    {
        //[UserButtonCode_browseButton3] -- add your button handler code here..
        //[/UserButtonCode_browseButton3]
    }
    else if (buttonThatWasClicked == browseButton4.get())
    {
        //[UserButtonCode_browseButton4] -- add your button handler code here..
        //[/UserButtonCode_browseButton4]
    }
    else if (buttonThatWasClicked == browseButton5.get())
    {
        //[UserButtonCode_browseButton5] -- add your button handler code here..
        //[/UserButtonCode_browseButton5]
    }
    else if (buttonThatWasClicked == browseButton6.get())
    {
        //[UserButtonCode_browseButton6] -- add your button handler code here..
        //[/UserButtonCode_browseButton6]
    }
    else if (buttonThatWasClicked == browseButton7.get())
    {
        //[UserButtonCode_browseButton7] -- add your button handler code here..
        //[/UserButtonCode_browseButton7]
    }
    else if (buttonThatWasClicked == browseButton8.get())
    {
        //[UserButtonCode_browseButton8] -- add your button handler code here..
        //[/UserButtonCode_browseButton8]
    }
    else if (buttonThatWasClicked == browseButton9.get())
    {
        //[UserButtonCode_browseButton9] -- add your button handler code here..
        //[/UserButtonCode_browseButton9]
    }
    else if (buttonThatWasClicked == arrowUpButton.get())
    {
        //[UserButtonCode_arrowUpButton] -- add your button handler code here..
        //[/UserButtonCode_arrowUpButton]
    }
    else if (buttonThatWasClicked == rightArrowButton.get())
    {
        //[UserButtonCode_rightArrowButton] -- add your button handler code here..
        //[/UserButtonCode_rightArrowButton]
    }
    else if (buttonThatWasClicked == leftArrowButton.get())
    {
        //[UserButtonCode_leftArrowButton] -- add your button handler code here..
        //[/UserButtonCode_leftArrowButton]
    }
    else if (buttonThatWasClicked == downArrowButton.get())
    {
        //[UserButtonCode_downArrowButton] -- add your button handler code here..
        //[/UserButtonCode_downArrowButton]
    }
    else if (buttonThatWasClicked == deviceButton14.get())
    {
        //[UserButtonCode_deviceButton14] -- add your button handler code here..
        //[/UserButtonCode_deviceButton14]
    }
    else if (buttonThatWasClicked == deviceButton15.get())
    {
        //[UserButtonCode_deviceButton15] -- add your button handler code here..
        //[/UserButtonCode_deviceButton15]
    }
    else if (buttonThatWasClicked == deviceButton16.get())
    {
        //[UserButtonCode_deviceButton16] -- add your button handler code here..
        //[/UserButtonCode_deviceButton16]
    }
    else if (buttonThatWasClicked == deviceButton17.get())
    {
        //[UserButtonCode_deviceButton17] -- add your button handler code here..
        //[/UserButtonCode_deviceButton17]
    }
    else if (buttonThatWasClicked == nn92Pad.get())
    {
        //[UserButtonCode_nn92Pad] -- add your button handler code here..
        //[/UserButtonCode_nn92Pad]
    }
    else if (buttonThatWasClicked == nn93Pad.get())
    {
        //[UserButtonCode_nn93Pad] -- add your button handler code here..
        //[/UserButtonCode_nn93Pad]
    }
    else if (buttonThatWasClicked == nn94Pad.get())
    {
        //[UserButtonCode_nn94Pad] -- add your button handler code here..
        //[/UserButtonCode_nn94Pad]
    }
    else if (buttonThatWasClicked == nn95Pad.get())
    {
        //[UserButtonCode_nn95Pad] -- add your button handler code here..
        //[/UserButtonCode_nn95Pad]
    }
    else if (buttonThatWasClicked == nn96Pad.get())
    {
        //[UserButtonCode_nn96Pad] -- add your button handler code here..
        //[/UserButtonCode_nn96Pad]
    }
    else if (buttonThatWasClicked == nn97Pad.get())
    {
        //[UserButtonCode_nn97Pad] -- add your button handler code here..
        //[/UserButtonCode_nn97Pad]
    }
    else if (buttonThatWasClicked == nn98Pad.get())
    {
        //[UserButtonCode_nn98Pad] -- add your button handler code here..
        //[/UserButtonCode_nn98Pad]
    }
    else if (buttonThatWasClicked == nn99Pad.get())
    {
        //[UserButtonCode_nn99Pad] -- add your button handler code here..
        //[/UserButtonCode_nn99Pad]
    }
    else if (buttonThatWasClicked == nn84Pad.get())
    {
        //[UserButtonCode_nn84Pad] -- add your button handler code here..
        //[/UserButtonCode_nn84Pad]
    }
    else if (buttonThatWasClicked == nn85Pad.get())
    {
        //[UserButtonCode_nn85Pad] -- add your button handler code here..
        //[/UserButtonCode_nn85Pad]
    }
    else if (buttonThatWasClicked == nn86Pad.get())
    {
        //[UserButtonCode_nn86Pad] -- add your button handler code here..
        //[/UserButtonCode_nn86Pad]
    }
    else if (buttonThatWasClicked == nn87Pad.get())
    {
        //[UserButtonCode_nn87Pad] -- add your button handler code here..
        //[/UserButtonCode_nn87Pad]
    }
    else if (buttonThatWasClicked == nn88Pad.get())
    {
        //[UserButtonCode_nn88Pad] -- add your button handler code here..
        //[/UserButtonCode_nn88Pad]
    }
    else if (buttonThatWasClicked == nn89Pad.get())
    {
        //[UserButtonCode_nn89Pad] -- add your button handler code here..
        //[/UserButtonCode_nn89Pad]
    }
    else if (buttonThatWasClicked == nn90Pad.get())
    {
        //[UserButtonCode_nn90Pad] -- add your button handler code here..
        //[/UserButtonCode_nn90Pad]
    }
    else if (buttonThatWasClicked == nn91Pad.get())
    {
        //[UserButtonCode_nn91Pad] -- add your button handler code here..
        //[/UserButtonCode_nn91Pad]
    }
    else if (buttonThatWasClicked == nn76Pad.get())
    {
        //[UserButtonCode_nn76Pad] -- add your button handler code here..
        //[/UserButtonCode_nn76Pad]
    }
    else if (buttonThatWasClicked == nn77Pad.get())
    {
        //[UserButtonCode_nn77Pad] -- add your button handler code here..
        //[/UserButtonCode_nn77Pad]
    }
    else if (buttonThatWasClicked == nn78Pad.get())
    {
        //[UserButtonCode_nn78Pad] -- add your button handler code here..
        //[/UserButtonCode_nn78Pad]
    }
    else if (buttonThatWasClicked == nn79Pad.get())
    {
        //[UserButtonCode_nn79Pad] -- add your button handler code here..
        //[/UserButtonCode_nn79Pad]
    }
    else if (buttonThatWasClicked == nn80Pad.get())
    {
        //[UserButtonCode_nn80Pad] -- add your button handler code here..
        //[/UserButtonCode_nn80Pad]
    }
    else if (buttonThatWasClicked == nn81Pad.get())
    {
        //[UserButtonCode_nn81Pad] -- add your button handler code here..
        //[/UserButtonCode_nn81Pad]
    }
    else if (buttonThatWasClicked == nn82Pad.get())
    {
        //[UserButtonCode_nn82Pad] -- add your button handler code here..
        //[/UserButtonCode_nn82Pad]
    }
    else if (buttonThatWasClicked == nn83Pad.get())
    {
        //[UserButtonCode_nn83Pad] -- add your button handler code here..
        //[/UserButtonCode_nn83Pad]
    }
    else if (buttonThatWasClicked == nn68Pad.get())
    {
        //[UserButtonCode_nn68Pad] -- add your button handler code here..
        //[/UserButtonCode_nn68Pad]
    }
    else if (buttonThatWasClicked == nn69Pad.get())
    {
        //[UserButtonCode_nn69Pad] -- add your button handler code here..
        //[/UserButtonCode_nn69Pad]
    }
    else if (buttonThatWasClicked == nn70Pad.get())
    {
        //[UserButtonCode_nn70Pad] -- add your button handler code here..
        //[/UserButtonCode_nn70Pad]
    }
    else if (buttonThatWasClicked == nn71Pad.get())
    {
        //[UserButtonCode_nn71Pad] -- add your button handler code here..
        //[/UserButtonCode_nn71Pad]
    }
    else if (buttonThatWasClicked == nn72Pad.get())
    {
        //[UserButtonCode_nn72Pad] -- add your button handler code here..
        //[/UserButtonCode_nn72Pad]
    }
    else if (buttonThatWasClicked == nn73Pad.get())
    {
        //[UserButtonCode_nn73Pad] -- add your button handler code here..
        //[/UserButtonCode_nn73Pad]
    }
    else if (buttonThatWasClicked == nn74Pad.get())
    {
        //[UserButtonCode_nn74Pad] -- add your button handler code here..
        //[/UserButtonCode_nn74Pad]
    }
    else if (buttonThatWasClicked == nn75Pad.get())
    {
        //[UserButtonCode_nn75Pad] -- add your button handler code here..
        //[/UserButtonCode_nn75Pad]
    }
    else if (buttonThatWasClicked == nn60Pad.get())
    {
        //[UserButtonCode_nn60Pad] -- add your button handler code here..
        //[/UserButtonCode_nn60Pad]
    }
    else if (buttonThatWasClicked == nn61Pad.get())
    {
        //[UserButtonCode_nn61Pad] -- add your button handler code here..
        //[/UserButtonCode_nn61Pad]
    }
    else if (buttonThatWasClicked == nn62Pad.get())
    {
        //[UserButtonCode_nn62Pad] -- add your button handler code here..
        //[/UserButtonCode_nn62Pad]
    }
    else if (buttonThatWasClicked == nn63Pad.get())
    {
        //[UserButtonCode_nn63Pad] -- add your button handler code here..
        //[/UserButtonCode_nn63Pad]
    }
    else if (buttonThatWasClicked == nn64Pad.get())
    {
        //[UserButtonCode_nn64Pad] -- add your button handler code here..
        //[/UserButtonCode_nn64Pad]
    }
    else if (buttonThatWasClicked == nn65Pad.get())
    {
        //[UserButtonCode_nn65Pad] -- add your button handler code here..
        //[/UserButtonCode_nn65Pad]
    }
    else if (buttonThatWasClicked == nn66Pad.get())
    {
        //[UserButtonCode_nn66Pad] -- add your button handler code here..
        //[/UserButtonCode_nn66Pad]
    }
    else if (buttonThatWasClicked == nn67Pad.get())
    {
        //[UserButtonCode_nn67Pad] -- add your button handler code here..
        //[/UserButtonCode_nn67Pad]
    }
    else if (buttonThatWasClicked == nn52Pad.get())
    {
        //[UserButtonCode_nn52Pad] -- add your button handler code here..
        //[/UserButtonCode_nn52Pad]
    }
    else if (buttonThatWasClicked == nn53Pad.get())
    {
        //[UserButtonCode_nn53Pad] -- add your button handler code here..
        //[/UserButtonCode_nn53Pad]
    }
    else if (buttonThatWasClicked == nn54Pad.get())
    {
        //[UserButtonCode_nn54Pad] -- add your button handler code here..
        //[/UserButtonCode_nn54Pad]
    }
    else if (buttonThatWasClicked == nn55Pad.get())
    {
        //[UserButtonCode_nn55Pad] -- add your button handler code here..
        //[/UserButtonCode_nn55Pad]
    }
    else if (buttonThatWasClicked == nn56Pad.get())
    {
        //[UserButtonCode_nn56Pad] -- add your button handler code here..
        //[/UserButtonCode_nn56Pad]
    }
    else if (buttonThatWasClicked == nn57Pad.get())
    {
        //[UserButtonCode_nn57Pad] -- add your button handler code here..
        //[/UserButtonCode_nn57Pad]
    }
    else if (buttonThatWasClicked == nn58Pad.get())
    {
        //[UserButtonCode_nn58Pad] -- add your button handler code here..
        //[/UserButtonCode_nn58Pad]
    }
    else if (buttonThatWasClicked == nn59Pad.get())
    {
        //[UserButtonCode_nn59Pad] -- add your button handler code here..
        //[/UserButtonCode_nn59Pad]
    }
    else if (buttonThatWasClicked == nn44Pad.get())
    {
        //[UserButtonCode_nn44Pad] -- add your button handler code here..
        //[/UserButtonCode_nn44Pad]
    }
    else if (buttonThatWasClicked == nn45Pad.get())
    {
        //[UserButtonCode_nn45Pad] -- add your button handler code here..
        //[/UserButtonCode_nn45Pad]
    }
    else if (buttonThatWasClicked == nn46Pad.get())
    {
        //[UserButtonCode_nn46Pad] -- add your button handler code here..
        //[/UserButtonCode_nn46Pad]
    }
    else if (buttonThatWasClicked == nn47Pad.get())
    {
        //[UserButtonCode_nn47Pad] -- add your button handler code here..
        //[/UserButtonCode_nn47Pad]
    }
    else if (buttonThatWasClicked == nn48Pad.get())
    {
        //[UserButtonCode_nn48Pad] -- add your button handler code here..
        //[/UserButtonCode_nn48Pad]
    }
    else if (buttonThatWasClicked == nn49Pad.get())
    {
        //[UserButtonCode_nn49Pad] -- add your button handler code here..
        //[/UserButtonCode_nn49Pad]
    }
    else if (buttonThatWasClicked == nn50Pad.get())
    {
        //[UserButtonCode_nn50Pad] -- add your button handler code here..
        //[/UserButtonCode_nn50Pad]
    }
    else if (buttonThatWasClicked == nn51Pad.get())
    {
        //[UserButtonCode_nn51Pad] -- add your button handler code here..
        //[/UserButtonCode_nn51Pad]
    }
    else if (buttonThatWasClicked == nn36Pad.get())
    {
        //[UserButtonCode_nn36Pad] -- add your button handler code here..
        //[/UserButtonCode_nn36Pad]
    }
    else if (buttonThatWasClicked == nn37Pad.get())
    {
        //[UserButtonCode_nn37Pad] -- add your button handler code here..
        //[/UserButtonCode_nn37Pad]
    }
    else if (buttonThatWasClicked == nn38Pad.get())
    {
        //[UserButtonCode_nn38Pad] -- add your button handler code here..
        //[/UserButtonCode_nn38Pad]
    }
    else if (buttonThatWasClicked == nn39Pad.get())
    {
        //[UserButtonCode_nn39Pad] -- add your button handler code here..
        //[/UserButtonCode_nn39Pad]
    }
    else if (buttonThatWasClicked == nn40Pad.get())
    {
        //[UserButtonCode_nn40Pad] -- add your button handler code here..
        //[/UserButtonCode_nn40Pad]
    }
    else if (buttonThatWasClicked == nn41Pad.get())
    {
        //[UserButtonCode_nn41Pad] -- add your button handler code here..
        //[/UserButtonCode_nn41Pad]
    }
    else if (buttonThatWasClicked == nn42Pad.get())
    {
        //[UserButtonCode_nn42Pad] -- add your button handler code here..
        //[/UserButtonCode_nn42Pad]
    }
    else if (buttonThatWasClicked == nn43Pad.get())
    {
        //[UserButtonCode_nn43Pad] -- add your button handler code here..
        //[/UserButtonCode_nn43Pad]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void Push2Simulator::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == touchstripSider.get())
    {
        //[UserSliderCode_touchstripSider] -- add your slider handling code here..
        //[/UserSliderCode_touchstripSider]
    }
    else if (sliderThatWasMoved == cc14Slider.get())
    {
        //[UserSliderCode_cc14Slider] -- add your slider handling code here..
        //[/UserSliderCode_cc14Slider]
    }
    else if (sliderThatWasMoved == cc15Slider.get())
    {
        //[UserSliderCode_cc15Slider] -- add your slider handling code here..
        //[/UserSliderCode_cc15Slider]
    }
    else if (sliderThatWasMoved == cc71Slider.get())
    {
        //[UserSliderCode_cc71Slider] -- add your slider handling code here..
        //[/UserSliderCode_cc71Slider]
    }
    else if (sliderThatWasMoved == cc72Slider.get())
    {
        //[UserSliderCode_cc72Slider] -- add your slider handling code here..
        //[/UserSliderCode_cc72Slider]
    }
    else if (sliderThatWasMoved == cc73Slider.get())
    {
        //[UserSliderCode_cc73Slider] -- add your slider handling code here..
        //[/UserSliderCode_cc73Slider]
    }
    else if (sliderThatWasMoved == cc74Slider.get())
    {
        //[UserSliderCode_cc74Slider] -- add your slider handling code here..
        //[/UserSliderCode_cc74Slider]
    }
    else if (sliderThatWasMoved == cc75Slider.get())
    {
        //[UserSliderCode_cc75Slider] -- add your slider handling code here..
        //[/UserSliderCode_cc75Slider]
    }
    else if (sliderThatWasMoved == cc76Slider.get())
    {
        //[UserSliderCode_cc76Slider] -- add your slider handling code here..
        //[/UserSliderCode_cc76Slider]
    }
    else if (sliderThatWasMoved == cc77Slider.get())
    {
        //[UserSliderCode_cc77Slider] -- add your slider handling code here..
        //[/UserSliderCode_cc77Slider]
    }
    else if (sliderThatWasMoved == cc78Slider.get())
    {
        //[UserSliderCode_cc78Slider] -- add your slider handling code here..
        //[/UserSliderCode_cc78Slider]
    }
    else if (sliderThatWasMoved == cc79Slider.get())
    {
        //[UserSliderCode_cc79Slider] -- add your slider handling code here..
        //[/UserSliderCode_cc79Slider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void Push2Simulator::setPush2Interface(Push2Interface* push_)
{
    push = push_;
    push->addActionListener(this);  // Make MainComponent receive notifications from Push2 so it can update replicated display (for debug only)
}

void Push2Simulator::actionListenerCallback (const String &message)
{
    if (message == "NEW_FRAME_AVAILABLE")
    {
        repaint();
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Push2Simulator" componentName=""
                 parentClasses="public Component, public ActionListener" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="0" snapShown="0"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="900" initialHeight="726">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTBUTTON name="tapTempo" id="8d928e8228cdad4f" memberName="tapTempoButton"
              virtualName="" explicitFocusOrder="0" pos="8 64 64 24" buttonText="Tap Tempo"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="metronome" id="cb393501935f29c2" memberName="metronomeButton"
              virtualName="" explicitFocusOrder="0" pos="72 64 64 24" buttonText="Metro"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="cc102" id="99b981958a6ca6a6" memberName="cc102Button" virtualName=""
              explicitFocusOrder="0" pos="160 64 64 24" buttonText="cc102"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="cc103" id="1ae0bf5b95445584" memberName="cc103Button" virtualName=""
              explicitFocusOrder="0" pos="229 64 64 24" buttonText="cc103"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="cc104" id="e7d67014d507f88e" memberName="cc104Button" virtualName=""
              explicitFocusOrder="0" pos="300 64 64 24" buttonText="cc104"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="cc105" id="7890b6bc317a9b92" memberName="cc105Button" virtualName=""
              explicitFocusOrder="0" pos="368 64 64 24" buttonText="cc105"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="cc107" id="c7aee98929cf099c" memberName="cc107Button" virtualName=""
              explicitFocusOrder="0" pos="508 64 64 24" buttonText="cc107"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="cc108" id="6931c9631a8e2092" memberName="cc108Button" virtualName=""
              explicitFocusOrder="0" pos="578 64 64 24" buttonText="cc108"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="cc109" id="bdf5618c765a9b46" memberName="cc109Button" virtualName=""
              explicitFocusOrder="0" pos="646 64 64 24" buttonText="cc109"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="cc20" id="d9ae1e29d035eb37" memberName="cc20Button" virtualName=""
              explicitFocusOrder="0" pos="160 240 64 24" buttonText="cc20"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="cc21" id="fe69bebdeed763ee" memberName="cc21Button" virtualName=""
              explicitFocusOrder="0" pos="229 240 64 24" buttonText="cc21"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="cc22" id="5b2ab4ae1bec3b37" memberName="cc22Button" virtualName=""
              explicitFocusOrder="0" pos="300 240 64 24" buttonText="cc22"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="cc23" id="7cfffa58fe18a6b1" memberName="cc23Button" virtualName=""
              explicitFocusOrder="0" pos="368 240 64 24" buttonText="cc23"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="cc24" id="699886abd9d3c76c" memberName="cc24Button" virtualName=""
              explicitFocusOrder="0" pos="438 240 64 24" buttonText="cc24"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="cc25" id="ea173c8687ab3f2f" memberName="cc25Button" virtualName=""
              explicitFocusOrder="0" pos="508 240 64 24" buttonText="cc25"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="cc26" id="3ae5871a086c2247" memberName="cc26Button" virtualName=""
              explicitFocusOrder="0" pos="578 240 64 24" buttonText="cc26"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="cc27" id="239d72a3d95c3787" memberName="cc27Button" virtualName=""
              explicitFocusOrder="0" pos="646 240 64 24" buttonText="cc27"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="touchstrip" id="7e43d7dbbcef260d" memberName="touchstripSider"
          virtualName="" explicitFocusOrder="0" pos="80 288 48 416" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="cc14" id="886a64d93c0987ac" memberName="cc14Slider" virtualName=""
          explicitFocusOrder="0" pos="0 0 72 56" min="0.0" max="10.0" int="0.0"
          style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="cc15" id="79540299f4b2987f" memberName="cc15Slider" virtualName=""
          explicitFocusOrder="0" pos="72 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="cc71" id="89b2350bdf808a9" memberName="cc71Slider" virtualName=""
          explicitFocusOrder="0" pos="154 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="cc72" id="7cacf6d8b1f57e42" memberName="cc72Slider" virtualName=""
          explicitFocusOrder="0" pos="224 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="cc73" id="4585070a8a7cd9d7" memberName="cc73Slider" virtualName=""
          explicitFocusOrder="0" pos="294 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="cc74" id="f23033f7978a5f13" memberName="cc74Slider" virtualName=""
          explicitFocusOrder="0" pos="364 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="cc75" id="beb0c374adbf8190" memberName="cc75Slider" virtualName=""
          explicitFocusOrder="0" pos="434 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="cc76" id="fa0ee44534ba4337" memberName="cc76Slider" virtualName=""
          explicitFocusOrder="0" pos="504 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="cc77" id="234d7913d6c2ec90" memberName="cc77Slider" virtualName=""
          explicitFocusOrder="0" pos="574 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="cc78" id="eca66cd1e01fe58b" memberName="cc78Slider" virtualName=""
          explicitFocusOrder="0" pos="644 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="cc79" id="235dfab35660f24e" memberName="cc79Slider" virtualName=""
          explicitFocusOrder="0" pos="804 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <GENERICCOMPONENT name="display" id="40edd835fcbd5156" memberName="displayPlaceholder"
                    virtualName="" explicitFocusOrder="0" pos="156 114 555 98" class="Component"
                    params=""/>
  <TEXTBUTTON name="cc106" id="c90fcbe5aaa74c2d" memberName="cc106Button" virtualName=""
              explicitFocusOrder="0" pos="438 64 64 24" buttonText="cc106"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="setup" id="529a328d8fa439ec" memberName="setupButton" virtualName=""
              explicitFocusOrder="0" pos="792 64 48 24" buttonText="Setup"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="user" id="a5624d6cd508f008" memberName="userButton" virtualName=""
              explicitFocusOrder="0" pos="840 64 48 24" buttonText="User" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="addDevice" id="acc4169b549d89f1" memberName="addDeviceButton"
              virtualName="" explicitFocusOrder="0" pos="736 118 45 45" buttonText="Add Device"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="addTrack" id="80d1493944d0276b" memberName="addTrackButton"
              virtualName="" explicitFocusOrder="0" pos="736 164 45 45" buttonText="Add Track"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="device" id="7ad9dae6bba97060" memberName="deviceButton"
              virtualName="" explicitFocusOrder="0" pos="796 118 45 45" buttonText="Device"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="browse" id="ec9d34ceb881a666" memberName="browseButton"
              virtualName="" explicitFocusOrder="0" pos="796 164 45 45" buttonText="Browse"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="mix" id="9ec0764339f18cd" memberName="mixButton" virtualName=""
              explicitFocusOrder="0" pos="843 118 45 45" buttonText="Mix" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="clip" id="d37146d81fe1f44" memberName="clipButton" virtualName=""
              explicitFocusOrder="0" pos="843 164 45 45" buttonText="Clip"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="delete" id="ee192a4a50969003" memberName="deleteButton"
              virtualName="" explicitFocusOrder="0" pos="8 118 45 45" buttonText="Delete"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="undo" id="779cba6da0a2f4f5" memberName="undoButton" virtualName=""
              explicitFocusOrder="0" pos="8 164 45 45" buttonText="Undo" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="device" id="931b07232ade58b4" memberName="deviceButton2"
              virtualName="" explicitFocusOrder="0" pos="796 446 45 45" buttonText="Device"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="mix" id="8f30ff7172bc9620" memberName="mixButton2" virtualName=""
              explicitFocusOrder="0" pos="843 446 45 45" buttonText="Mix" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="device" id="d0aee787df1872b2" memberName="deviceButton3"
              virtualName="" explicitFocusOrder="0" pos="796 525 45 45" buttonText="Device"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="mix" id="b29b3c8b909083b6" memberName="mixButton3" virtualName=""
              explicitFocusOrder="0" pos="843 525 45 45" buttonText="Mix" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="device" id="e0c4167095bd34f4" memberName="deviceButton4"
              virtualName="" explicitFocusOrder="0" pos="796 496 45 27" buttonText="Device"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="mix" id="85b54043c509ac07" memberName="mixButton4" virtualName=""
              explicitFocusOrder="0" pos="843 496 45 27" buttonText="Mix" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="device" id="d2996cb07acef212" memberName="deviceButton5"
              virtualName="" explicitFocusOrder="0" pos="796 677 45 27" buttonText="Device"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="mix" id="511be2f2d5cd0a5e" memberName="mixButton5" virtualName=""
              explicitFocusOrder="0" pos="843 677 45 27" buttonText="Mix" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="mute" id="cb54c758432ec715" memberName="muteButton" virtualName=""
              explicitFocusOrder="0" pos="8 240 42 27" buttonText="Mute" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="solo" id="475b139744cbf798" memberName="soloButton" virtualName=""
              explicitFocusOrder="0" pos="50 240 42 27" buttonText="Solo" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="stopClip" id="17ae6dadb83827dd" memberName="stopClipButton"
              virtualName="" explicitFocusOrder="0" pos="92 240 42 27" buttonText="Stop Clip"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="duplicate" id="d5bd5d43321d3927" memberName="duplicateButton"
              virtualName="" explicitFocusOrder="0" pos="8 425 45 45" buttonText="Duplicate"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new" id="658e13a518f0a2f1" memberName="newButton" virtualName=""
              explicitFocusOrder="0" pos="8 471 45 45" buttonText="New" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="delete" id="950a9e7bab083596" memberName="convertButton"
              virtualName="" explicitFocusOrder="0" pos="8 286 45 43" buttonText="Delete"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="doubleLoop" id="a56b0670ecaad02c" memberName="doubleLoopButton"
              virtualName="" explicitFocusOrder="0" pos="8 330 45 43" buttonText="Double Loop"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="quantize" id="afa68fcf00729fc8" memberName="quantizeButton"
              virtualName="" explicitFocusOrder="0" pos="8 374 45 43" buttonText="Quantize"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="fixLength" id="6048d151d19615d9" memberName="fixLengthButton"
              virtualName="" explicitFocusOrder="0" pos="8 524 45 42" buttonText="Fix Length"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="automate" id="2fe2458440f08201" memberName="automateButton"
              virtualName="" explicitFocusOrder="0" pos="8 566 45 42" buttonText="Automate"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="record" id="779e0ff065dbd114" memberName="recordButton"
              virtualName="" explicitFocusOrder="0" pos="8 608 45 42" buttonText="Record"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="play" id="aba4e8cf88fd3c7a" memberName="playButton" virtualName=""
              explicitFocusOrder="0" pos="8 658 45 45" buttonText="Play" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="master" id="10e3054efb51d3a" memberName="masterButton"
              virtualName="" explicitFocusOrder="0" pos="736 240 45 27" buttonText="Master"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="browse" id="631420ccc9ebc5dc" memberName="browseButton2"
              virtualName="" explicitFocusOrder="0" pos="736 286 45 45" buttonText="Browse"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="browse" id="a609abb426209092" memberName="browseButton3"
              virtualName="" explicitFocusOrder="0" pos="736 338 45 45" buttonText="Browse"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="browse" id="1d8c71941a15e2a4" memberName="browseButton4"
              virtualName="" explicitFocusOrder="0" pos="736 393 45 45" buttonText="Browse"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="browse" id="ad8551a61beac128" memberName="browseButton5"
              virtualName="" explicitFocusOrder="0" pos="736 445 45 45" buttonText="Browse"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="browse" id="c03d60c5ce29e9e9" memberName="browseButton6"
              virtualName="" explicitFocusOrder="0" pos="736 498 45 45" buttonText="Browse"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="browse" id="d20ae4d5fa8d1625" memberName="browseButton7"
              virtualName="" explicitFocusOrder="0" pos="736 551 45 45" buttonText="Browse"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="browse" id="65551547090ead8a" memberName="browseButton8"
              virtualName="" explicitFocusOrder="0" pos="736 605 45 45" buttonText="Browse"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="browse" id="8266fc8a2e09dc70" memberName="browseButton9"
              virtualName="" explicitFocusOrder="0" pos="736 657 45 45" buttonText="Browse"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="arrowUp" id="824cd281cec4669b" memberName="arrowUpButton"
              virtualName="" explicitFocusOrder="0" pos="828 239 28 28" buttonText="&#8593;"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="rightArrow" id="2a3b9b05c39d5669" memberName="rightArrowButton"
              virtualName="" explicitFocusOrder="0" pos="860 271 28 28" buttonText="&#8594;"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="leftArrow" id="e4ca7ac5b285f7c5" memberName="leftArrowButton"
              virtualName="" explicitFocusOrder="0" pos="796 271 28 28" buttonText="&#8592;"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="downArrow" id="b7386b4a4523e5df" memberName="downArrowButton"
              virtualName="" explicitFocusOrder="0" pos="828 303 28 28" buttonText="&#8595;"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="device" id="b1fd2108d3a25e62" memberName="deviceButton14"
              virtualName="" explicitFocusOrder="0" pos="828 577 28 28" buttonText="Device"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="device" id="70f06277372dbee8" memberName="deviceButton15"
              virtualName="" explicitFocusOrder="0" pos="860 609 28 28" buttonText="Device"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="device" id="98ce20aa5ea31bf1" memberName="deviceButton16"
              virtualName="" explicitFocusOrder="0" pos="796 609 28 28" buttonText="Device"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="device" id="b94d6bcd62c3b141" memberName="deviceButton17"
              virtualName="" explicitFocusOrder="0" pos="828 641 28 28" buttonText="Device"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn92" id="e66ab4b251afbf2c" memberName="nn92Pad" virtualName=""
              explicitFocusOrder="0" pos="160 286 62 44" buttonText="nn92"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn93" id="83f053bedcb0a79a" memberName="nn93Pad" virtualName=""
              explicitFocusOrder="0" pos="230 286 62 44" buttonText="nn93"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn94" id="5e4b1051c9464864" memberName="nn94Pad" virtualName=""
              explicitFocusOrder="0" pos="299 286 62 44" buttonText="nn94"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn95" id="899bb70b22148250" memberName="nn95Pad" virtualName=""
              explicitFocusOrder="0" pos="369 286 62 44" buttonText="nn95"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn96" id="a76c520f07642864" memberName="nn96Pad" virtualName=""
              explicitFocusOrder="0" pos="438 286 62 44" buttonText="nn96"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn97" id="765ecc71469637bc" memberName="nn97Pad" virtualName=""
              explicitFocusOrder="0" pos="508 286 62 44" buttonText="nn97"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn98" id="c760b48d116508db" memberName="nn98Pad" virtualName=""
              explicitFocusOrder="0" pos="577 286 62 44" buttonText="nn98"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn99" id="6df69d0da007613a" memberName="nn99Pad" virtualName=""
              explicitFocusOrder="0" pos="647 286 62 44" buttonText="nn99"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn84" id="c3245eb174c3a6bf" memberName="nn84Pad" virtualName=""
              explicitFocusOrder="0" pos="160 339 62 44" buttonText="nn84"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn85" id="f10a106e88feec2c" memberName="nn85Pad" virtualName=""
              explicitFocusOrder="0" pos="230 339 62 44" buttonText="nn85"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn86" id="78c5c7e5bf6b96e1" memberName="nn86Pad" virtualName=""
              explicitFocusOrder="0" pos="299 339 62 44" buttonText="nn86"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn87" id="de42dd55c9341177" memberName="nn87Pad" virtualName=""
              explicitFocusOrder="0" pos="369 339 62 44" buttonText="nn87"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn88" id="b978cc5f4ca75099" memberName="nn88Pad" virtualName=""
              explicitFocusOrder="0" pos="438 339 62 44" buttonText="nn88"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn89" id="b7451eaa67010906" memberName="nn89Pad" virtualName=""
              explicitFocusOrder="0" pos="508 339 62 44" buttonText="nn89"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn90" id="dcd2b9f42d4ff617" memberName="nn90Pad" virtualName=""
              explicitFocusOrder="0" pos="577 339 62 44" buttonText="nn90"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn91" id="fe41b4c9b33618d3" memberName="nn91Pad" virtualName=""
              explicitFocusOrder="0" pos="647 339 62 44" buttonText="nn91"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn76" id="865d8b9f0b739c75" memberName="nn76Pad" virtualName=""
              explicitFocusOrder="0" pos="160 392 62 44" buttonText="nn76"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn77" id="cc206dc227a84e44" memberName="nn77Pad" virtualName=""
              explicitFocusOrder="0" pos="230 392 62 44" buttonText="nn77"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn78" id="55a84210136fa844" memberName="nn78Pad" virtualName=""
              explicitFocusOrder="0" pos="299 392 62 44" buttonText="nn78"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn79" id="50c9f4346721d429" memberName="nn79Pad" virtualName=""
              explicitFocusOrder="0" pos="369 392 62 44" buttonText="nn79"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn80" id="1c85d7b681da5f0" memberName="nn80Pad" virtualName=""
              explicitFocusOrder="0" pos="438 392 62 44" buttonText="nn80"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn81" id="24fa7d0df96c1f21" memberName="nn81Pad" virtualName=""
              explicitFocusOrder="0" pos="508 392 62 44" buttonText="nn81"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn82" id="2e710b7d1fdef04" memberName="nn82Pad" virtualName=""
              explicitFocusOrder="0" pos="577 392 62 44" buttonText="nn82"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn83" id="30a9cc8dbfd2f205" memberName="nn83Pad" virtualName=""
              explicitFocusOrder="0" pos="647 392 62 44" buttonText="nn83"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn68" id="461fda2d52f36fd6" memberName="nn68Pad" virtualName=""
              explicitFocusOrder="0" pos="160 445 62 44" buttonText="nn68"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn69" id="f5fc5c70b9c3f718" memberName="nn69Pad" virtualName=""
              explicitFocusOrder="0" pos="230 445 62 44" buttonText="nn69"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn70" id="1f9382befb8b0690" memberName="nn70Pad" virtualName=""
              explicitFocusOrder="0" pos="299 445 62 44" buttonText="nn70"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn71" id="7e82cf72004b8734" memberName="nn71Pad" virtualName=""
              explicitFocusOrder="0" pos="369 445 62 44" buttonText="nn71"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn72" id="3571a6e434713f8c" memberName="nn72Pad" virtualName=""
              explicitFocusOrder="0" pos="438 445 62 44" buttonText="nn72"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn73" id="defe9915303a3045" memberName="nn73Pad" virtualName=""
              explicitFocusOrder="0" pos="508 445 62 44" buttonText="nn73"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn74" id="f3af2e17ba9702e5" memberName="nn74Pad" virtualName=""
              explicitFocusOrder="0" pos="577 445 62 44" buttonText="nn74"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn75" id="e362dda06b77aefb" memberName="nn75Pad" virtualName=""
              explicitFocusOrder="0" pos="647 445 62 44" buttonText="nn75"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn60" id="5a32eb0924d1d04" memberName="nn60Pad" virtualName=""
              explicitFocusOrder="0" pos="160 499 62 44" buttonText="nn60"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn61" id="eb4a02bb73fc697d" memberName="nn61Pad" virtualName=""
              explicitFocusOrder="0" pos="230 499 62 44" buttonText="nn61"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn62" id="f70bbbcc232a85b2" memberName="nn62Pad" virtualName=""
              explicitFocusOrder="0" pos="299 499 62 44" buttonText="nn62"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn63" id="4923ff562c0dc904" memberName="nn63Pad" virtualName=""
              explicitFocusOrder="0" pos="369 499 62 44" buttonText="nn63"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn64" id="2f5f094ddae60634" memberName="nn64Pad" virtualName=""
              explicitFocusOrder="0" pos="438 499 62 44" buttonText="nn64"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn65" id="5da96f8b617bf1b8" memberName="nn65Pad" virtualName=""
              explicitFocusOrder="0" pos="508 499 62 44" buttonText="nn65"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn66" id="a7c515189b4d4439" memberName="nn66Pad" virtualName=""
              explicitFocusOrder="0" pos="577 499 62 44" buttonText="nn66"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn67" id="f27dde077dcc20df" memberName="nn67Pad" virtualName=""
              explicitFocusOrder="0" pos="647 499 62 44" buttonText="nn67"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn52" id="102a08cb280aa614" memberName="nn52Pad" virtualName=""
              explicitFocusOrder="0" pos="160 552 62 44" buttonText="nn52"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn53" id="3508202d054d20db" memberName="nn53Pad" virtualName=""
              explicitFocusOrder="0" pos="230 552 62 44" buttonText="nn53"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn54" id="cdd6d149cb6e6df7" memberName="nn54Pad" virtualName=""
              explicitFocusOrder="0" pos="299 552 62 44" buttonText="nn54"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn55" id="ba73a33dcc237977" memberName="nn55Pad" virtualName=""
              explicitFocusOrder="0" pos="369 552 62 44" buttonText="nn55"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn56" id="ea7d2a75c1d1d460" memberName="nn56Pad" virtualName=""
              explicitFocusOrder="0" pos="438 552 62 44" buttonText="nn56"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn57" id="3d96e7b15c77d184" memberName="nn57Pad" virtualName=""
              explicitFocusOrder="0" pos="508 552 62 44" buttonText="nn57"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn58" id="8e12233c99ecd5d2" memberName="nn58Pad" virtualName=""
              explicitFocusOrder="0" pos="577 552 62 44" buttonText="nn58"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn59" id="743bceea873155a4" memberName="nn59Pad" virtualName=""
              explicitFocusOrder="0" pos="647 552 62 44" buttonText="nn59"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn44" id="b9fe5dd978cea7c8" memberName="nn44Pad" virtualName=""
              explicitFocusOrder="0" pos="160 605 62 44" buttonText="nn44"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn45" id="a1ec9f0c64ef3865" memberName="nn45Pad" virtualName=""
              explicitFocusOrder="0" pos="230 605 62 44" buttonText="nn45"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn46" id="46db905456b408e6" memberName="nn46Pad" virtualName=""
              explicitFocusOrder="0" pos="299 605 62 44" buttonText="nn46"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn47" id="1332e1254c919f91" memberName="nn47Pad" virtualName=""
              explicitFocusOrder="0" pos="369 605 62 44" buttonText="nn47"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn48" id="836b094a85f5e071" memberName="nn48Pad" virtualName=""
              explicitFocusOrder="0" pos="438 605 62 44" buttonText="nn48"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn49" id="8b637d94d8d392c3" memberName="nn49Pad" virtualName=""
              explicitFocusOrder="0" pos="508 605 62 44" buttonText="nn49"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn50" id="2be93cf489fde101" memberName="nn50Pad" virtualName=""
              explicitFocusOrder="0" pos="577 605 62 44" buttonText="nn50"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn51" id="aae5baa8347cbf3d" memberName="nn51Pad" virtualName=""
              explicitFocusOrder="0" pos="647 605 62 44" buttonText="nn51"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn36" id="f09e9e61c8d62275" memberName="nn36Pad" virtualName=""
              explicitFocusOrder="0" pos="160 658 62 44" buttonText="n36" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn37" id="12990187d5cb24f9" memberName="nn37Pad" virtualName=""
              explicitFocusOrder="0" pos="230 658 62 44" buttonText="nn37"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn38" id="19ce490681c3e726" memberName="nn38Pad" virtualName=""
              explicitFocusOrder="0" pos="299 658 62 44" buttonText="nn38"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn39" id="54d78d50332200fd" memberName="nn39Pad" virtualName=""
              explicitFocusOrder="0" pos="369 658 62 44" buttonText="nn39"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn40" id="7a273e78adad005e" memberName="nn40Pad" virtualName=""
              explicitFocusOrder="0" pos="438 658 62 44" buttonText="nn40"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn41" id="cbd26884fe0c88f3" memberName="nn41Pad" virtualName=""
              explicitFocusOrder="0" pos="508 658 62 44" buttonText="nn41"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn42" id="47e53c77b60a860b" memberName="nn42Pad" virtualName=""
              explicitFocusOrder="0" pos="577 658 62 44" buttonText="nn42"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="nn43" id="1e55ca11b784bf8" memberName="nn43Pad" virtualName=""
              explicitFocusOrder="0" pos="647 658 62 44" buttonText="nn43"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

