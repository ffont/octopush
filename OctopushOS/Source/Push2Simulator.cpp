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
    setLookAndFeel(&customLookAndFeel);
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

    ba1Button.reset (new TextButton ("ba1"));
    addAndMakeVisible (ba1Button.get());
    ba1Button->setButtonText (TRANS("BA1"));
    ba1Button->addListener (this);

    ba1Button->setBounds (160, 64, 64, 24);

    ba2Button.reset (new TextButton ("ba2"));
    addAndMakeVisible (ba2Button.get());
    ba2Button->setButtonText (TRANS("BA2"));
    ba2Button->addListener (this);

    ba2Button->setBounds (229, 64, 64, 24);

    ba3Button.reset (new TextButton ("ba3"));
    addAndMakeVisible (ba3Button.get());
    ba3Button->setButtonText (TRANS("BA3"));
    ba3Button->addListener (this);

    ba3Button->setBounds (300, 64, 64, 24);

    ba4Button.reset (new TextButton ("ba4"));
    addAndMakeVisible (ba4Button.get());
    ba4Button->setButtonText (TRANS("BA4"));
    ba4Button->addListener (this);

    ba4Button->setBounds (368, 64, 64, 24);

    ba5Button.reset (new TextButton ("ba5"));
    addAndMakeVisible (ba5Button.get());
    ba5Button->setButtonText (TRANS("BA5"));
    ba5Button->addListener (this);

    ba5Button->setBounds (438, 64, 64, 24);

    ba6Button.reset (new TextButton ("ba6"));
    addAndMakeVisible (ba6Button.get());
    ba6Button->setButtonText (TRANS("BA6"));
    ba6Button->addListener (this);

    ba6Button->setBounds (508, 64, 64, 24);

    ba7Button.reset (new TextButton ("ba7"));
    addAndMakeVisible (ba7Button.get());
    ba7Button->setButtonText (TRANS("BA7"));
    ba7Button->addListener (this);

    ba7Button->setBounds (578, 64, 64, 24);

    ba8Button.reset (new TextButton ("ba8"));
    addAndMakeVisible (ba8Button.get());
    ba8Button->setButtonText (TRANS("BA8"));
    ba8Button->addListener (this);

    ba8Button->setBounds (646, 64, 64, 24);

    bb1Button.reset (new TextButton ("bb1"));
    addAndMakeVisible (bb1Button.get());
    bb1Button->setButtonText (TRANS("BB1"));
    bb1Button->addListener (this);

    bb1Button->setBounds (160, 240, 64, 24);

    bb2Button.reset (new TextButton ("bb2"));
    addAndMakeVisible (bb2Button.get());
    bb2Button->setButtonText (TRANS("BB2"));
    bb2Button->addListener (this);

    bb2Button->setBounds (229, 240, 64, 24);

    bb3Button.reset (new TextButton ("bb3"));
    addAndMakeVisible (bb3Button.get());
    bb3Button->setButtonText (TRANS("BB3"));
    bb3Button->addListener (this);

    bb3Button->setBounds (300, 240, 64, 24);

    bb4Button.reset (new TextButton ("bb4"));
    addAndMakeVisible (bb4Button.get());
    bb4Button->setButtonText (TRANS("BB4"));
    bb4Button->addListener (this);

    bb4Button->setBounds (368, 240, 64, 24);

    bb5Button.reset (new TextButton ("bb5"));
    addAndMakeVisible (bb5Button.get());
    bb5Button->setButtonText (TRANS("BB5"));
    bb5Button->addListener (this);

    bb5Button->setBounds (438, 240, 64, 24);

    bb6Button.reset (new TextButton ("bb6"));
    addAndMakeVisible (bb6Button.get());
    bb6Button->setButtonText (TRANS("BB6"));
    bb6Button->addListener (this);

    bb6Button->setBounds (508, 240, 64, 24);

    bb7Button.reset (new TextButton ("bb7"));
    addAndMakeVisible (bb7Button.get());
    bb7Button->setButtonText (TRANS("BB7"));
    bb7Button->addListener (this);

    bb7Button->setBounds (578, 240, 64, 24);

    bb8Button.reset (new TextButton ("bb8"));
    addAndMakeVisible (bb8Button.get());
    bb8Button->setButtonText (TRANS("BB8"));
    bb8Button->addListener (this);

    bb8Button->setBounds (646, 240, 64, 24);

    touchstripSider.reset (new Slider ("touchstrip"));
    addAndMakeVisible (touchstripSider.get());
    touchstripSider->setRange (0, 10, 0);
    touchstripSider->setSliderStyle (Slider::LinearVertical);
    touchstripSider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    touchstripSider->addListener (this);

    touchstripSider->setBounds (80, 288, 48, 416);

    tempoSlider.reset (new Slider ("tempo"));
    addAndMakeVisible (tempoSlider.get());
    tempoSlider->setRange (0, 10, 0);
    tempoSlider->setSliderStyle (Slider::Rotary);
    tempoSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    tempoSlider->addListener (this);

    tempoSlider->setBounds (0, 0, 72, 56);

    swingSlider.reset (new Slider ("swing"));
    addAndMakeVisible (swingSlider.get());
    swingSlider->setRange (0, 10, 0);
    swingSlider->setSliderStyle (Slider::Rotary);
    swingSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    swingSlider->addListener (this);

    swingSlider->setBounds (72, 0, 72, 56);

    e1Slider.reset (new Slider ("e1"));
    addAndMakeVisible (e1Slider.get());
    e1Slider->setRange (0, 10, 0);
    e1Slider->setSliderStyle (Slider::Rotary);
    e1Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    e1Slider->addListener (this);

    e1Slider->setBounds (154, 0, 72, 56);

    e2Slider.reset (new Slider ("e2"));
    addAndMakeVisible (e2Slider.get());
    e2Slider->setRange (0, 10, 0);
    e2Slider->setSliderStyle (Slider::Rotary);
    e2Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    e2Slider->addListener (this);

    e2Slider->setBounds (224, 0, 72, 56);

    e3Slider.reset (new Slider ("e3"));
    addAndMakeVisible (e3Slider.get());
    e3Slider->setRange (0, 10, 0);
    e3Slider->setSliderStyle (Slider::Rotary);
    e3Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    e3Slider->addListener (this);

    e3Slider->setBounds (294, 0, 72, 56);

    e4Slider.reset (new Slider ("e4"));
    addAndMakeVisible (e4Slider.get());
    e4Slider->setRange (0, 10, 0);
    e4Slider->setSliderStyle (Slider::Rotary);
    e4Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    e4Slider->addListener (this);

    e4Slider->setBounds (364, 0, 72, 56);

    e5Slider.reset (new Slider ("e5"));
    addAndMakeVisible (e5Slider.get());
    e5Slider->setRange (0, 10, 0);
    e5Slider->setSliderStyle (Slider::Rotary);
    e5Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    e5Slider->addListener (this);

    e5Slider->setBounds (434, 0, 72, 56);

    e6Slider.reset (new Slider ("e6"));
    addAndMakeVisible (e6Slider.get());
    e6Slider->setRange (0, 10, 0);
    e6Slider->setSliderStyle (Slider::Rotary);
    e6Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    e6Slider->addListener (this);

    e6Slider->setBounds (504, 0, 72, 56);

    e7Slider.reset (new Slider ("e7"));
    addAndMakeVisible (e7Slider.get());
    e7Slider->setRange (0, 10, 0);
    e7Slider->setSliderStyle (Slider::Rotary);
    e7Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    e7Slider->addListener (this);

    e7Slider->setBounds (574, 0, 72, 56);

    e8Slider.reset (new Slider ("e8"));
    addAndMakeVisible (e8Slider.get());
    e8Slider->setRange (0, 10, 0);
    e8Slider->setSliderStyle (Slider::Rotary);
    e8Slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    e8Slider->addListener (this);

    e8Slider->setBounds (644, 0, 72, 56);

    masterSlider.reset (new Slider ("master"));
    addAndMakeVisible (masterSlider.get());
    masterSlider->setRange (0, 10, 0);
    masterSlider->setSliderStyle (Slider::Rotary);
    masterSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    masterSlider->addListener (this);

    masterSlider->setBounds (804, 0, 72, 56);

    displayPlaceholder.reset (new Component());
    addAndMakeVisible (displayPlaceholder.get());
    displayPlaceholder->setName ("display");

    displayPlaceholder->setBounds (156, 114, 555, 98);

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

    repeatButton.reset (new TextButton ("repeat"));
    addAndMakeVisible (repeatButton.get());
    repeatButton->setButtonText (TRANS("Repeat"));
    repeatButton->addListener (this);

    repeatButton->setBounds (796, 446, 45, 45);

    accentButton.reset (new TextButton ("accent"));
    addAndMakeVisible (accentButton.get());
    accentButton->setButtonText (TRANS("Accent"));
    accentButton->addListener (this);

    accentButton->setBounds (843, 446, 45, 45);

    noteButton.reset (new TextButton ("note"));
    addAndMakeVisible (noteButton.get());
    noteButton->setButtonText (TRANS("Note"));
    noteButton->addListener (this);

    noteButton->setBounds (796, 525, 45, 45);

    sesstionButton.reset (new TextButton ("session"));
    addAndMakeVisible (sesstionButton.get());
    sesstionButton->setButtonText (TRANS("Session"));
    sesstionButton->addListener (this);

    sesstionButton->setBounds (843, 525, 45, 45);

    scaleButton.reset (new TextButton ("scale"));
    addAndMakeVisible (scaleButton.get());
    scaleButton->setButtonText (TRANS("Scale"));
    scaleButton->addListener (this);

    scaleButton->setBounds (796, 496, 45, 27);

    layoutButton.reset (new TextButton ("layout"));
    addAndMakeVisible (layoutButton.get());
    layoutButton->setButtonText (TRANS("Layout"));
    layoutButton->addListener (this);

    layoutButton->setBounds (843, 496, 45, 27);

    shiftButton.reset (new TextButton ("shift"));
    addAndMakeVisible (shiftButton.get());
    shiftButton->setButtonText (TRANS("Shift"));
    shiftButton->addListener (this);

    shiftButton->setBounds (796, 677, 45, 27);

    selectButton.reset (new TextButton ("select"));
    addAndMakeVisible (selectButton.get());
    selectButton->setButtonText (TRANS("Select"));
    selectButton->addListener (this);

    selectButton->setBounds (843, 677, 45, 27);

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

    _1_32tButton.reset (new TextButton ("1_32t"));
    addAndMakeVisible (_1_32tButton.get());
    _1_32tButton->setButtonText (TRANS("1/32t"));
    _1_32tButton->addListener (this);

    _1_32tButton->setBounds (736, 286, 45, 45);

    _1_32Button.reset (new TextButton ("1_32"));
    addAndMakeVisible (_1_32Button.get());
    _1_32Button->setButtonText (TRANS("1/32"));
    _1_32Button->addListener (this);

    _1_32Button->setBounds (736, 338, 45, 45);

    _1_16tButton.reset (new TextButton ("1_16t"));
    addAndMakeVisible (_1_16tButton.get());
    _1_16tButton->setButtonText (TRANS("1/16t"));
    _1_16tButton->addListener (this);

    _1_16tButton->setBounds (736, 393, 45, 45);

    _1_16Button.reset (new TextButton ("1_16"));
    addAndMakeVisible (_1_16Button.get());
    _1_16Button->setButtonText (TRANS("1/16"));
    _1_16Button->addListener (this);

    _1_16Button->setBounds (736, 445, 45, 45);

    _1_8tButton.reset (new TextButton ("1_8t"));
    addAndMakeVisible (_1_8tButton.get());
    _1_8tButton->setButtonText (TRANS("1/8t"));
    _1_8tButton->addListener (this);

    _1_8tButton->setBounds (736, 498, 45, 45);

    _1_8Button.reset (new TextButton ("1_8"));
    addAndMakeVisible (_1_8Button.get());
    _1_8Button->setButtonText (TRANS("1/8"));
    _1_8Button->addListener (this);

    _1_8Button->setBounds (736, 551, 45, 45);

    _1_4tButton.reset (new TextButton ("1_4t"));
    addAndMakeVisible (_1_4tButton.get());
    _1_4tButton->setButtonText (TRANS("1/4t"));
    _1_4tButton->addListener (this);

    _1_4tButton->setBounds (736, 605, 45, 45);

    _1_4Button.reset (new TextButton ("1_4"));
    addAndMakeVisible (_1_4Button.get());
    _1_4Button->setButtonText (TRANS("1/4"));
    _1_4Button->addListener (this);

    _1_4Button->setBounds (736, 657, 45, 45);

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

    octaveUpButton.reset (new TextButton ("octaveUp"));
    addAndMakeVisible (octaveUpButton.get());
    octaveUpButton->setButtonText (CharPointer_UTF8 ("o \xe2\x86\x91"));
    octaveUpButton->addListener (this);

    octaveUpButton->setBounds (828, 577, 28, 28);

    pageRightButton.reset (new TextButton ("pageRight"));
    addAndMakeVisible (pageRightButton.get());
    pageRightButton->setButtonText (CharPointer_UTF8 ("p \xe2\x86\x92"));
    pageRightButton->addListener (this);

    pageRightButton->setBounds (860, 609, 28, 28);

    pageLeftButton.reset (new TextButton ("pageLeft"));
    addAndMakeVisible (pageLeftButton.get());
    pageLeftButton->setButtonText (CharPointer_UTF8 ("p \xe2\x86\x90"));
    pageLeftButton->addListener (this);

    pageLeftButton->setBounds (796, 609, 28, 28);

    octaveDownButton.reset (new TextButton ("octaveDown"));
    addAndMakeVisible (octaveDownButton.get());
    octaveDownButton->setButtonText (CharPointer_UTF8 ("o \xe2\x86\x93"));
    octaveDownButton->addListener (this);

    octaveDownButton->setBounds (828, 641, 28, 28);

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
    // Make rotary sliders endles
    tempoSlider->setRotaryParameters(0, float_Pi * 2, false);
    swingSlider->setRotaryParameters(0, float_Pi * 2, false);
    e1Slider->setRotaryParameters(0, float_Pi * 2, false);
    e2Slider->setRotaryParameters(0, float_Pi * 2, false);
    e3Slider->setRotaryParameters(0, float_Pi * 2, false);
    e4Slider->setRotaryParameters(0, float_Pi * 2, false);
    e5Slider->setRotaryParameters(0, float_Pi * 2, false);
    e6Slider->setRotaryParameters(0, float_Pi * 2, false);
    e7Slider->setRotaryParameters(0, float_Pi * 2, false);
    e8Slider->setRotaryParameters(0, float_Pi * 2, false);
    masterSlider->setRotaryParameters(0, float_Pi * 2, false);
    //[/Constructor]
}

Push2Simulator::~Push2Simulator()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    setLookAndFeel (nullptr);
    //[/Destructor_pre]

    tapTempoButton = nullptr;
    metronomeButton = nullptr;
    ba1Button = nullptr;
    ba2Button = nullptr;
    ba3Button = nullptr;
    ba4Button = nullptr;
    ba5Button = nullptr;
    ba6Button = nullptr;
    ba7Button = nullptr;
    ba8Button = nullptr;
    bb1Button = nullptr;
    bb2Button = nullptr;
    bb3Button = nullptr;
    bb4Button = nullptr;
    bb5Button = nullptr;
    bb6Button = nullptr;
    bb7Button = nullptr;
    bb8Button = nullptr;
    touchstripSider = nullptr;
    tempoSlider = nullptr;
    swingSlider = nullptr;
    e1Slider = nullptr;
    e2Slider = nullptr;
    e3Slider = nullptr;
    e4Slider = nullptr;
    e5Slider = nullptr;
    e6Slider = nullptr;
    e7Slider = nullptr;
    e8Slider = nullptr;
    masterSlider = nullptr;
    displayPlaceholder = nullptr;
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
    repeatButton = nullptr;
    accentButton = nullptr;
    noteButton = nullptr;
    sesstionButton = nullptr;
    scaleButton = nullptr;
    layoutButton = nullptr;
    shiftButton = nullptr;
    selectButton = nullptr;
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
    _1_32tButton = nullptr;
    _1_32Button = nullptr;
    _1_16tButton = nullptr;
    _1_16Button = nullptr;
    _1_8tButton = nullptr;
    _1_8Button = nullptr;
    _1_4tButton = nullptr;
    _1_4Button = nullptr;
    arrowUpButton = nullptr;
    rightArrowButton = nullptr;
    leftArrowButton = nullptr;
    downArrowButton = nullptr;
    octaveUpButton = nullptr;
    pageRightButton = nullptr;
    pageLeftButton = nullptr;
    octaveDownButton = nullptr;
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

    g.fillAll (Colour (0xff151515));

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
    else if (buttonThatWasClicked == ba1Button.get())
    {
        //[UserButtonCode_ba1Button] -- add your button handler code here..
        push->ba1Pressed();
        //[/UserButtonCode_ba1Button]
    }
    else if (buttonThatWasClicked == ba2Button.get())
    {
        //[UserButtonCode_ba2Button] -- add your button handler code here..
        push->ba2Pressed();
        //[/UserButtonCode_ba2Button]
    }
    else if (buttonThatWasClicked == ba3Button.get())
    {
        //[UserButtonCode_ba3Button] -- add your button handler code here..
        push->ba3Pressed();
        //[/UserButtonCode_ba3Button]
    }
    else if (buttonThatWasClicked == ba4Button.get())
    {
        //[UserButtonCode_ba4Button] -- add your button handler code here..
        push->ba4Pressed();
        //[/UserButtonCode_ba4Button]
    }
    else if (buttonThatWasClicked == ba5Button.get())
    {
        //[UserButtonCode_ba5Button] -- add your button handler code here..
        push->ba5Pressed();
        //[/UserButtonCode_ba5Button]
    }
    else if (buttonThatWasClicked == ba6Button.get())
    {
        //[UserButtonCode_ba6Button] -- add your button handler code here..
        push->ba6Pressed();
        //[/UserButtonCode_ba6Button]
    }
    else if (buttonThatWasClicked == ba7Button.get())
    {
        //[UserButtonCode_ba7Button] -- add your button handler code here..
        push->ba7Pressed();
        //[/UserButtonCode_ba7Button]
    }
    else if (buttonThatWasClicked == ba8Button.get())
    {
        //[UserButtonCode_ba8Button] -- add your button handler code here..
        push->ba8Pressed();
        //[/UserButtonCode_ba8Button]
    }
    else if (buttonThatWasClicked == bb1Button.get())
    {
        //[UserButtonCode_bb1Button] -- add your button handler code here..
        push->bb1Pressed();
        //[/UserButtonCode_bb1Button]
    }
    else if (buttonThatWasClicked == bb2Button.get())
    {
        //[UserButtonCode_bb2Button] -- add your button handler code here..
        push->bb2Pressed();
        //[/UserButtonCode_bb2Button]
    }
    else if (buttonThatWasClicked == bb3Button.get())
    {
        //[UserButtonCode_bb3Button] -- add your button handler code here..
        push->bb3Pressed();
        //[/UserButtonCode_bb3Button]
    }
    else if (buttonThatWasClicked == bb4Button.get())
    {
        //[UserButtonCode_bb4Button] -- add your button handler code here..
        push->bb4Pressed();
        //[/UserButtonCode_bb4Button]
    }
    else if (buttonThatWasClicked == bb5Button.get())
    {
        //[UserButtonCode_bb5Button] -- add your button handler code here..
        push->bb5Pressed();
        //[/UserButtonCode_bb5Button]
    }
    else if (buttonThatWasClicked == bb6Button.get())
    {
        //[UserButtonCode_bb6Button] -- add your button handler code here..
        push->bb6Pressed();
        //[/UserButtonCode_bb6Button]
    }
    else if (buttonThatWasClicked == bb7Button.get())
    {
        //[UserButtonCode_bb7Button] -- add your button handler code here..
        push->bb7Pressed();
        //[/UserButtonCode_bb7Button]
    }
    else if (buttonThatWasClicked == bb8Button.get())
    {
        //[UserButtonCode_bb8Button] -- add your button handler code here..
        push->bb8Pressed();
        //[/UserButtonCode_bb8Button]
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
    else if (buttonThatWasClicked == repeatButton.get())
    {
        //[UserButtonCode_repeatButton] -- add your button handler code here..
        //[/UserButtonCode_repeatButton]
    }
    else if (buttonThatWasClicked == accentButton.get())
    {
        //[UserButtonCode_accentButton] -- add your button handler code here..
        //[/UserButtonCode_accentButton]
    }
    else if (buttonThatWasClicked == noteButton.get())
    {
        //[UserButtonCode_noteButton] -- add your button handler code here..
        //[/UserButtonCode_noteButton]
    }
    else if (buttonThatWasClicked == sesstionButton.get())
    {
        //[UserButtonCode_sesstionButton] -- add your button handler code here..
        //[/UserButtonCode_sesstionButton]
    }
    else if (buttonThatWasClicked == scaleButton.get())
    {
        //[UserButtonCode_scaleButton] -- add your button handler code here..
        //[/UserButtonCode_scaleButton]
    }
    else if (buttonThatWasClicked == layoutButton.get())
    {
        //[UserButtonCode_layoutButton] -- add your button handler code here..
        //[/UserButtonCode_layoutButton]
    }
    else if (buttonThatWasClicked == shiftButton.get())
    {
        //[UserButtonCode_shiftButton] -- add your button handler code here..
        //[/UserButtonCode_shiftButton]
    }
    else if (buttonThatWasClicked == selectButton.get())
    {
        //[UserButtonCode_selectButton] -- add your button handler code here..
        //[/UserButtonCode_selectButton]
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
        push->playPressed();
        //[/UserButtonCode_playButton]
    }
    else if (buttonThatWasClicked == masterButton.get())
    {
        //[UserButtonCode_masterButton] -- add your button handler code here..
        //[/UserButtonCode_masterButton]
    }
    else if (buttonThatWasClicked == _1_32tButton.get())
    {
        //[UserButtonCode__1_32tButton] -- add your button handler code here..
        //[/UserButtonCode__1_32tButton]
    }
    else if (buttonThatWasClicked == _1_32Button.get())
    {
        //[UserButtonCode__1_32Button] -- add your button handler code here..
        //[/UserButtonCode__1_32Button]
    }
    else if (buttonThatWasClicked == _1_16tButton.get())
    {
        //[UserButtonCode__1_16tButton] -- add your button handler code here..
        //[/UserButtonCode__1_16tButton]
    }
    else if (buttonThatWasClicked == _1_16Button.get())
    {
        //[UserButtonCode__1_16Button] -- add your button handler code here..
        //[/UserButtonCode__1_16Button]
    }
    else if (buttonThatWasClicked == _1_8tButton.get())
    {
        //[UserButtonCode__1_8tButton] -- add your button handler code here..
        //[/UserButtonCode__1_8tButton]
    }
    else if (buttonThatWasClicked == _1_8Button.get())
    {
        //[UserButtonCode__1_8Button] -- add your button handler code here..
        //[/UserButtonCode__1_8Button]
    }
    else if (buttonThatWasClicked == _1_4tButton.get())
    {
        //[UserButtonCode__1_4tButton] -- add your button handler code here..
        //[/UserButtonCode__1_4tButton]
    }
    else if (buttonThatWasClicked == _1_4Button.get())
    {
        //[UserButtonCode__1_4Button] -- add your button handler code here..
        //[/UserButtonCode__1_4Button]
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
    else if (buttonThatWasClicked == octaveUpButton.get())
    {
        //[UserButtonCode_octaveUpButton] -- add your button handler code here..
        //[/UserButtonCode_octaveUpButton]
    }
    else if (buttonThatWasClicked == pageRightButton.get())
    {
        //[UserButtonCode_pageRightButton] -- add your button handler code here..
        //[/UserButtonCode_pageRightButton]
    }
    else if (buttonThatWasClicked == pageLeftButton.get())
    {
        //[UserButtonCode_pageLeftButton] -- add your button handler code here..
        //[/UserButtonCode_pageLeftButton]
    }
    else if (buttonThatWasClicked == octaveDownButton.get())
    {
        //[UserButtonCode_octaveDownButton] -- add your button handler code here..
        //[/UserButtonCode_octaveDownButton]
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
    else if (sliderThatWasMoved == tempoSlider.get())
    {
        //[UserSliderCode_tempoSlider] -- add your slider handling code here..
        double currentValue = tempoSlider.get()->getValue();
        if (currentValue > tempoSliderLastValue){
            push->tempoEncoderRotated(1);  // Send +1 increment
        } else {
            push->tempoEncoderRotated(-1);  // Send -1 decrement
        }
        tempoSliderLastValue = currentValue;
        //[/UserSliderCode_tempoSlider]
    }
    else if (sliderThatWasMoved == swingSlider.get())
    {
        //[UserSliderCode_swingSlider] -- add your slider handling code here..
        double currentValue = swingSlider.get()->getValue();
        if (currentValue > swingSliderLastValue){
            push->swingEncoderRotated(1);  // Send +1 increment
        } else {
            push->swingEncoderRotated(-1);  // Send -1 decrement
        }
        swingSliderLastValue = currentValue;
        //[/UserSliderCode_swingSlider]
    }
    else if (sliderThatWasMoved == e1Slider.get())
    {
        //[UserSliderCode_e1Slider] -- add your slider handling code here..
        
        double currentValue = e1Slider.get()->getValue();
        if (currentValue > e1SliderLastValue){
            push->e1Rotated(1);
        } else {
            push->e1Rotated(-1);
        }
        e1SliderLastValue = currentValue;
        //[/UserSliderCode_e1Slider]
    }
    else if (sliderThatWasMoved == e2Slider.get())
    {
        //[UserSliderCode_e2Slider] -- add your slider handling code here..
        double currentValue = e2Slider.get()->getValue();
        if (currentValue > e2SliderLastValue){
            push->e2Rotated(1);
        } else {
            push->e2Rotated(-1);
        }
        e2SliderLastValue = currentValue;
        //[/UserSliderCode_e2Slider]
    }
    else if (sliderThatWasMoved == e3Slider.get())
    {
        //[UserSliderCode_e3Slider] -- add your slider handling code here..
        double currentValue = e3Slider.get()->getValue();
        if (currentValue > e3SliderLastValue){
            push->e3Rotated(1);
        } else {
            push->e3Rotated(-1);
        }
        e3SliderLastValue = currentValue;
        //[/UserSliderCode_e3Slider]
    }
    else if (sliderThatWasMoved == e4Slider.get())
    {
        //[UserSliderCode_e4Slider] -- add your slider handling code here..
        double currentValue = e4Slider.get()->getValue();
        if (currentValue > e4SliderLastValue){
            push->e4Rotated(1);
        } else {
            push->e4Rotated(-1);
        }
        e4SliderLastValue = currentValue;
        //[/UserSliderCode_e4Slider]
    }
    else if (sliderThatWasMoved == e5Slider.get())
    {
        //[UserSliderCode_e5Slider] -- add your slider handling code here..
        double currentValue = e5Slider.get()->getValue();
        if (currentValue > e5SliderLastValue){
            push->e5Rotated(1);
        } else {
            push->e5Rotated(-1);
        }
        e5SliderLastValue = currentValue;
        //[/UserSliderCode_e5Slider]
    }
    else if (sliderThatWasMoved == e6Slider.get())
    {
        //[UserSliderCode_e6Slider] -- add your slider handling code here..
        double currentValue = e6Slider.get()->getValue();
        if (currentValue > e6SliderLastValue){
            push->e6Rotated(1);
        } else {
            push->e6Rotated(-1);
        }
        e6SliderLastValue = currentValue;
        //[/UserSliderCode_e6Slider]
    }
    else if (sliderThatWasMoved == e7Slider.get())
    {
        //[UserSliderCode_e7Slider] -- add your slider handling code here..
        double currentValue = e7Slider.get()->getValue();
        if (currentValue > e7SliderLastValue){
            push->e7Rotated(1);
        } else {
            push->e7Rotated(-1);
        }
        e7SliderLastValue = currentValue;
        //[/UserSliderCode_e7Slider]
    }
    else if (sliderThatWasMoved == e8Slider.get())
    {
        //[UserSliderCode_e8Slider] -- add your slider handling code here..
        double currentValue = e8Slider.get()->getValue();
        if (currentValue > e8SliderLastValue){
            push->e8Rotated(1);
        } else {
            push->e8Rotated(-1);
        }
        e8SliderLastValue = currentValue;
        //[/UserSliderCode_e8Slider]
    }
    else if (sliderThatWasMoved == masterSlider.get())
    {
        //[UserSliderCode_masterSlider] -- add your slider handling code here..
        double currentValue = masterSlider.get()->getValue();
        if (currentValue > masterSliderLastValue){
            push->masterEncoderRotated(1);
        } else {
            push->masterEncoderRotated(-1);
        }
        masterSliderLastValue = currentValue;
        //[/UserSliderCode_masterSlider]
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
  <BACKGROUND backgroundColour="ff151515"/>
  <TEXTBUTTON name="tapTempo" id="8d928e8228cdad4f" memberName="tapTempoButton"
              virtualName="" explicitFocusOrder="0" pos="8 64 64 24" buttonText="Tap Tempo"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="metronome" id="cb393501935f29c2" memberName="metronomeButton"
              virtualName="" explicitFocusOrder="0" pos="72 64 64 24" buttonText="Metro"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="ba1" id="99b981958a6ca6a6" memberName="ba1Button" virtualName=""
              explicitFocusOrder="0" pos="160 64 64 24" buttonText="BA1" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="ba2" id="1ae0bf5b95445584" memberName="ba2Button" virtualName=""
              explicitFocusOrder="0" pos="229 64 64 24" buttonText="BA2" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="ba3" id="e7d67014d507f88e" memberName="ba3Button" virtualName=""
              explicitFocusOrder="0" pos="300 64 64 24" buttonText="BA3" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="ba4" id="7890b6bc317a9b92" memberName="ba4Button" virtualName=""
              explicitFocusOrder="0" pos="368 64 64 24" buttonText="BA4" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="ba5" id="c90fcbe5aaa74c2d" memberName="ba5Button" virtualName=""
              explicitFocusOrder="0" pos="438 64 64 24" buttonText="BA5" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="ba6" id="c7aee98929cf099c" memberName="ba6Button" virtualName=""
              explicitFocusOrder="0" pos="508 64 64 24" buttonText="BA6" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="ba7" id="6931c9631a8e2092" memberName="ba7Button" virtualName=""
              explicitFocusOrder="0" pos="578 64 64 24" buttonText="BA7" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="ba8" id="bdf5618c765a9b46" memberName="ba8Button" virtualName=""
              explicitFocusOrder="0" pos="646 64 64 24" buttonText="BA8" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="bb1" id="d9ae1e29d035eb37" memberName="bb1Button" virtualName=""
              explicitFocusOrder="0" pos="160 240 64 24" buttonText="BB1" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="bb2" id="fe69bebdeed763ee" memberName="bb2Button" virtualName=""
              explicitFocusOrder="0" pos="229 240 64 24" buttonText="BB2" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="bb3" id="5b2ab4ae1bec3b37" memberName="bb3Button" virtualName=""
              explicitFocusOrder="0" pos="300 240 64 24" buttonText="BB3" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="bb4" id="7cfffa58fe18a6b1" memberName="bb4Button" virtualName=""
              explicitFocusOrder="0" pos="368 240 64 24" buttonText="BB4" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="bb5" id="699886abd9d3c76c" memberName="bb5Button" virtualName=""
              explicitFocusOrder="0" pos="438 240 64 24" buttonText="BB5" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="bb6" id="ea173c8687ab3f2f" memberName="bb6Button" virtualName=""
              explicitFocusOrder="0" pos="508 240 64 24" buttonText="BB6" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="bb7" id="3ae5871a086c2247" memberName="bb7Button" virtualName=""
              explicitFocusOrder="0" pos="578 240 64 24" buttonText="BB7" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="bb8" id="239d72a3d95c3787" memberName="bb8Button" virtualName=""
              explicitFocusOrder="0" pos="646 240 64 24" buttonText="BB8" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <SLIDER name="touchstrip" id="7e43d7dbbcef260d" memberName="touchstripSider"
          virtualName="" explicitFocusOrder="0" pos="80 288 48 416" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="tempo" id="886a64d93c0987ac" memberName="tempoSlider" virtualName=""
          explicitFocusOrder="0" pos="0 0 72 56" min="0.0" max="10.0" int="0.0"
          style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="swing" id="79540299f4b2987f" memberName="swingSlider" virtualName=""
          explicitFocusOrder="0" pos="72 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="e1" id="89b2350bdf808a9" memberName="e1Slider" virtualName=""
          explicitFocusOrder="0" pos="154 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="e2" id="7cacf6d8b1f57e42" memberName="e2Slider" virtualName=""
          explicitFocusOrder="0" pos="224 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="e3" id="4585070a8a7cd9d7" memberName="e3Slider" virtualName=""
          explicitFocusOrder="0" pos="294 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="e4" id="f23033f7978a5f13" memberName="e4Slider" virtualName=""
          explicitFocusOrder="0" pos="364 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="e5" id="beb0c374adbf8190" memberName="e5Slider" virtualName=""
          explicitFocusOrder="0" pos="434 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="e6" id="fa0ee44534ba4337" memberName="e6Slider" virtualName=""
          explicitFocusOrder="0" pos="504 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="e7" id="234d7913d6c2ec90" memberName="e7Slider" virtualName=""
          explicitFocusOrder="0" pos="574 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="e8" id="eca66cd1e01fe58b" memberName="e8Slider" virtualName=""
          explicitFocusOrder="0" pos="644 0 72 56" min="0.0" max="10.0"
          int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="master" id="235dfab35660f24e" memberName="masterSlider"
          virtualName="" explicitFocusOrder="0" pos="804 0 72 56" min="0.0"
          max="10.0" int="0.0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <GENERICCOMPONENT name="display" id="40edd835fcbd5156" memberName="displayPlaceholder"
                    virtualName="" explicitFocusOrder="0" pos="156 114 555 98" class="Component"
                    params=""/>
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
  <TEXTBUTTON name="repeat" id="931b07232ade58b4" memberName="repeatButton"
              virtualName="" explicitFocusOrder="0" pos="796 446 45 45" buttonText="Repeat"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="accent" id="8f30ff7172bc9620" memberName="accentButton"
              virtualName="" explicitFocusOrder="0" pos="843 446 45 45" buttonText="Accent"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="note" id="d0aee787df1872b2" memberName="noteButton" virtualName=""
              explicitFocusOrder="0" pos="796 525 45 45" buttonText="Note"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="session" id="b29b3c8b909083b6" memberName="sesstionButton"
              virtualName="" explicitFocusOrder="0" pos="843 525 45 45" buttonText="Session"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="scale" id="e0c4167095bd34f4" memberName="scaleButton" virtualName=""
              explicitFocusOrder="0" pos="796 496 45 27" buttonText="Scale"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="layout" id="85b54043c509ac07" memberName="layoutButton"
              virtualName="" explicitFocusOrder="0" pos="843 496 45 27" buttonText="Layout"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="shift" id="d2996cb07acef212" memberName="shiftButton" virtualName=""
              explicitFocusOrder="0" pos="796 677 45 27" buttonText="Shift"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="select" id="511be2f2d5cd0a5e" memberName="selectButton"
              virtualName="" explicitFocusOrder="0" pos="843 677 45 27" buttonText="Select"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
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
  <TEXTBUTTON name="1_32t" id="631420ccc9ebc5dc" memberName="_1_32tButton"
              virtualName="" explicitFocusOrder="0" pos="736 286 45 45" buttonText="1/32t"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="1_32" id="a609abb426209092" memberName="_1_32Button" virtualName=""
              explicitFocusOrder="0" pos="736 338 45 45" buttonText="1/32"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="1_16t" id="1d8c71941a15e2a4" memberName="_1_16tButton"
              virtualName="" explicitFocusOrder="0" pos="736 393 45 45" buttonText="1/16t"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="1_16" id="ad8551a61beac128" memberName="_1_16Button" virtualName=""
              explicitFocusOrder="0" pos="736 445 45 45" buttonText="1/16"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="1_8t" id="c03d60c5ce29e9e9" memberName="_1_8tButton" virtualName=""
              explicitFocusOrder="0" pos="736 498 45 45" buttonText="1/8t"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="1_8" id="d20ae4d5fa8d1625" memberName="_1_8Button" virtualName=""
              explicitFocusOrder="0" pos="736 551 45 45" buttonText="1/8" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="1_4t" id="65551547090ead8a" memberName="_1_4tButton" virtualName=""
              explicitFocusOrder="0" pos="736 605 45 45" buttonText="1/4t"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="1_4" id="8266fc8a2e09dc70" memberName="_1_4Button" virtualName=""
              explicitFocusOrder="0" pos="736 657 45 45" buttonText="1/4" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
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
  <TEXTBUTTON name="octaveUp" id="b1fd2108d3a25e62" memberName="octaveUpButton"
              virtualName="" explicitFocusOrder="0" pos="828 577 28 28" buttonText="o &#8593;"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="pageRight" id="70f06277372dbee8" memberName="pageRightButton"
              virtualName="" explicitFocusOrder="0" pos="860 609 28 28" buttonText="p &#8594;"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="pageLeft" id="98ce20aa5ea31bf1" memberName="pageLeftButton"
              virtualName="" explicitFocusOrder="0" pos="796 609 28 28" buttonText="p &#8592;"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="octaveDown" id="b94d6bcd62c3b141" memberName="octaveDownButton"
              virtualName="" explicitFocusOrder="0" pos="828 641 28 28" buttonText="o &#8595;"
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

