/*
  ==============================================================================

    Push2Interface.cpp
    Created: 24 Oct 2019 6:26:33pm
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#include "Push2Interface.h"
#include "../JuceLibraryCode/BinaryData.h"


//------------------------------------------------------------------------------

namespace
{
    bool SMatchSubStringNoCase(const std::string& haystack, const std::string& needle)
    {
        auto it = std::search(
                              haystack.begin(), haystack.end(),
                              needle.begin(), needle.end(),
                              [](char ch1, char ch2)                // case insensitive
                              {
                                  return std::toupper(ch1) == std::toupper(ch2);
                              });
        return it != haystack.end();
    }
}

//------------------------------------------------------------------------------

Push2Interface::Push2Interface()
{
}

Push2Interface::~Push2Interface()
{
    // Stop timer
    stopTimer();
}

//------------------------------------------------------------------------------

void Push2Interface::initialize(Engine* engine_, int displayFrameRate_, int maxEncoderUpdateRate_)
{
    // Assign reference to application engine
    engine = engine_;
    engine->addActionListener(this);
    state = &engine->state; // Shorcut to access application state
    
    // Initialize Push2 connection
    NBase::Result result = connectToPush();
    if (result.Succeeded())
    {
        std::cout << "Push 2 connected" << std::endl;
        pushInitializedSuccessfully = true;
    }
    else
    {
        // Something went wrong while connecting to Push2
        std::cout << "ERROR connecting to Push 2: " << result.GetDescription() << std::endl;
        pushInitializedSuccessfully = false;
    }
    
    // Configure encoder update rate
    if (pushInitializedSuccessfully){
        setMaxEncoderUpdateRate(maxEncoderUpdateRate_);
    }
    
    // Set initial UI
    setInitialUI();
    
    // Start the timer to draw the animation
    displayFrameRate = displayFrameRate_;
    if (displayFrameRate > 0){
        startTimerHz(displayFrameRate);
    } else {
        std::cout << "WARNING: display frame timer is disabled" << std::endl;
    }
}


//------------------------------------------------------------------------------

NBase::Result Push2Interface::connectToPush()
{
    // First we initialise the low level push2 object
    NBase::Result result = push2Display.Init();
    RETURN_IF_FAILED_MESSAGE(result, "Failed to init push2");
    
    // Then we initialise the juce to push bridge
    result = bridge.Init(push2Display);
    RETURN_IF_FAILED_MESSAGE(result, "Failed to init bridge");
    
    // Initialises the midi input
    result = openMidiInDevice();
    RETURN_IF_FAILED_MESSAGE(result, "Failed to open midi in device");
    
    // Initialises the midi output
    result = openMidiOutDevice();
    RETURN_IF_FAILED_MESSAGE(result, "Failed to open midi out device");
    
    return NBase::Result::NoError;
}


//------------------------------------------------------------------------------

NBase::Result Push2Interface::openMidiInDevice()
{
    // Look for an input device matching push 2
    
    auto devices = MidiInput::getDevices();
    int deviceIndex = -1;
    int index = 0;
    for (auto& device: devices)
    {
        if (SMatchSubStringNoCase(device.toStdString(), "ableton push 2"))
        {
            deviceIndex = index;
            break;
        }
        index++;
    }
    
    if (deviceIndex == -1)
    {
        return NBase::Result("Failed to find input midi device for push2");
    }
    
    // Try opening the device
    auto input = MidiInput::openDevice(deviceIndex, this);
    if (!input)
    {
        return NBase::Result("Failed to open push2 input device");
    }
    
    // Store and starts listening to the device
    midiInput = MidiInput::openDevice(deviceIndex, this);
    midiInput.get()->start();
    
    return NBase::Result::NoError;
}

NBase::Result Push2Interface::openMidiOutDevice()
{
    // Look for an input device matching push 2
    
    auto devices = MidiOutput::getDevices();
    int deviceIndex = -1;
    int index = 0;
    for (auto& device: devices)
    {
        if (SMatchSubStringNoCase(device.toStdString(), "ableton push 2"))
        {
            deviceIndex = index;
            break;
        }
        index++;
    }
    
    if (deviceIndex == -1)
    {
        return NBase::Result("Failed to find input output device for push2");
    }
    
    // Try opening the device
    auto output = MidiOutput::openDevice(deviceIndex);
    if (!output)
    {
        return NBase::Result("Failed to open push2 output device");
    }
    
    // Open the device
    midiOutput = MidiOutput::openDevice(deviceIndex);
    
    return NBase::Result::NoError;
}


//------------------------------------------------------------------------------

void Push2Interface::handleIncomingMidiMessage (MidiInput* /*source*/, const MidiMessage &message)
{
    if (triggerPadActionsFromIncommingMidi(message)) { return; };
    if (triggerButtonActionsFromIncommingMidi(message)) { return; };
    if (triggerEncoderActionsFromIncommingMidi(message)) { return; };
}

void Push2Interface::sendMidiMessage(MidiMessage msg){
    if ((midiOutput.get() != nullptr)) {
        midiOutput.get()->sendMessageNow(msg);
    }
}


//------------------------------------------------------------------------------

void Push2Interface::timerCallback()
{
    state->animationElapsedTime += 1.0 / displayFrameRate;
    updateUI();
    
    // Measure frame rate and save it to state
    displayFrameRateCounter += 1;
    if (displayFrameCurrentSecond == 0){
        // Init variables
        displayFrameCurrentSecond = Time::getCurrentTime().toMilliseconds();
    } else {
        int64 currentTime = Time::getCurrentTime().toMilliseconds();
        if (currentTime - displayFrameCurrentSecond > 1000.0){
            displayFrameCurrentSecond = currentTime;
            state->displayFrameRate = displayFrameRateCounter;
            displayFrameRateCounter = 0;
            std::cout << "Display frames per second: " << state->displayFrameRate << std::endl;
        }
    }
}


//------------------------------------------------------------------------------

Image Push2Interface::computeDisplayFrameFromState()
{
    // Create a path for the animated wave
    const auto height = ableton::Push2DisplayBitmap::kHeight;
    const auto width = ableton::Push2DisplayBitmap::kWidth;
    
    Image frame = Image(Image::RGB, width, height, true);
    Graphics g(frame);
    
    // Clear previous frame
    g.fillAll(juce::Colour(0xff000000));
    
    // Draw logo (only during first second(s) at startup)
    if (state->animationElapsedTime < 1.0){
        auto logo = ImageCache::getFromMemory(BinaryData::startup_img_png, BinaryData::startup_img_pngSize);
        g.drawImageAt(logo, (width - logo.getWidth()) / 2 , (height - logo.getHeight()) / 2);
        return frame;
    }
    
    // Draw demo waveform
    Path wavePath;
    
    const float waveStep = 10.0f;
    const float waveY = height * 0.44f;
    int i = 0;
    
    for (float x = waveStep * 0.5f; x < width; x += waveStep)
    {
        const float y1 = waveY + height * 0.10f * std::sin(i * 0.38f + state->animationElapsedTime) * state->demoWaveAmplitude;
        const float y2 = waveY + height * 0.20f * std::sin(i * 0.20f + state->animationElapsedTime * 2.0f) * state->demoWaveAmplitude;
        
        wavePath.addLineSegment(Line<float>(x, y1, x, y2), 2.0f);
        wavePath.addEllipse(x - waveStep * 0.3f, y1 - waveStep * 0.3f, waveStep * 0.6f, waveStep * 0.6f);
        wavePath.addEllipse(x - waveStep * 0.3f, y2 - waveStep * 0.3f, waveStep * 0.6f, waveStep * 0.6f);
        
        ++i;
    }
    
    g.setColour(state->demoWaveColor);
    g.fillPath(wavePath);
    
    // Draw audio tracks level meter and volume
    int trackNum = 0;
    int numTracks = state->audioTrackSettings.size();
    for (auto settings : state->audioTrackSettings) {
        float trackWidth = width / 8;
        float trackX = (trackNum * trackWidth) + (width - (numTracks * trackWidth)); // Align right of display
        
        // Draw meter
        g.setColour(Colours::green);
        double minDbValueShown = -60.0;
        double clippedLevel = settings.measuredLevel;
        if (clippedLevel < minDbValueShown){
            clippedLevel = minDbValueShown;
        }
        double barHeight = jmap(clippedLevel, minDbValueShown, 0.0, 0.0, 1.0) * height;
        g.fillRect((int)(trackX + (trackWidth / 2 - 6)), height - barHeight, 20, barHeight);
        
        // Draw volume indicator
        g.setColour(Colours::white);
        g.drawText(String::formatted("%.2f dB", settings.volume), (int)trackX, 5, trackWidth, 12, Justification::centred);
        
        trackNum++;
    }
    
    // Draw display frame rate and update rate stats
    g.drawSingleLineText(String::formatted("display frames/second: %i", state->displayFrameRate), 5, height - (5 + 14));
    g.drawSingleLineText(String::formatted("state updates/second:%i", state->stateUpdateFrameRate), 5, height - 5);
    
    return frame;
}

void Push2Interface::updateDisplayFromState()
{
    // Update display (compute the frame outside the pushInitializedSuccessfully if because it can be used by the simulator)
    lastFrame = computeDisplayFrameFromState();
    
    if (pushInitializedSuccessfully)
    {
        // Send last computed frame to dipslay
        auto& g = bridge.GetGraphic();
        g.drawImageAt(lastFrame, 0, 0, false);
        bridge.Flip();
    }

    #if JUCE_DEBUG
        // Update main component as well so it shows on screen the same thing that in Push screen
        sendActionMessage("NEW_FRAME_AVAILABLE");
    #endif
}

void Push2Interface::updatePush2ButtonsFromState(){
    if (!pushInitializedSuccessfully) { return; }
    
    setButtonRGBColour(BUTTON_A1_CC_NUMBER, RGB_COLOUR_WHITE);  // Light button A1
    
    // Light Play button, green if playing, white otherwise
    if (state->isPlaying){
        setButtonRGBColour(BUTTON_PLAY_CC_NUMBER, RGB_COLOUR_GREEN);
    } else {
        setButtonRGBColour(BUTTON_PLAY_CC_NUMBER, RGB_COLOUR_WHITE);
    }
    
    // Light track mute buttons (blue if active, red if muted)
    int trackNum = 0;
    for (auto settings : state->audioTrackSettings) {
        int buttonNumber = 0;
        if (trackNum == 0){
            buttonNumber = BUTTON_A5_CC_NUMBER;
        } else if (trackNum == 1){
            buttonNumber = BUTTON_A6_CC_NUMBER;
        } else if (trackNum == 2){
            buttonNumber = BUTTON_A7_CC_NUMBER;
        } else if (trackNum == 3){
            buttonNumber = BUTTON_A8_CC_NUMBER;
        }
        
        if (settings.mute){
            setButtonRGBColour(buttonNumber, RGB_COLOUR_RED);
        } else {
            setButtonRGBColour(buttonNumber, RGB_COLOUR_BLUE);
        }
        trackNum++;
    }
}

void Push2Interface::updatePush2PadsFromState()
{
    // Display step sequencer pattern in pads
    
    // Init padGridColourValues to black
    std::array<std::array<int, 8>, 8> padGridColourValues = {RGB_COLOUR_BLACK};
    
    // Iterate sequence and set corresponding position colours
    for (int i=0; i<state->stepSequencerPattern.size(); i++){
        for (int j=0; j<state->stepSequencerPattern[0].size(); j++){
            // i = instrument type (0-3)
            // j = step number (0-15)
            if (state->stepSequencerPattern[i][j]) {  // If event present for that instrument/step
                if (j <= 7 ){
                    // First 4-pads row
                    padGridColourValues[i][j] = RGB_COLOUR_ORANGE;
                } else {
                    // Second 4-pads row
                    padGridColourValues[4 + i][j - 8] = RGB_COLOUR_PINK;
                }
            }
        }
    }
    
    // Add playhead position
    int currentStepN =  (int)floor(state->currentStepProportion * 16);
    if (currentStepN <= 7 ){
        // First 4-pads row
        for (int i=0; i<4; i++){
            padGridColourValues[i][currentStepN] = RGB_COLOUR_WHITE;
        }
    } else {
        // Second 4-pads row
        for (int i=4; i<8; i++){
            padGridColourValues[i][currentStepN - 8] = RGB_COLOUR_WHITE;
        }
    }
    
    // Set prepared padGridColourValues to Push's pads
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            PadIJ padIJ;
            padIJ.i = i;
            padIJ.j = j;
            setPadRGBColour(padIJ, padGridColourValues[i][j]);
        }
    }
}


void Push2Interface::updateUI()
{
    updateDisplayFromState();
    updatePush2ButtonsFromState();
    updatePush2PadsFromState();
}

void Push2Interface::setInitialUI()
{
    // UI stuff to do once at initialization time
}


//------------------------------------------------------------------------------

void Push2Interface::actionListenerCallback (const String &message)
{
    
}


//------------------------------------------------------------------------------

void Push2Interface::e1Rotated(int increment){
    state->demoWaveAmplitude += 0.04 * increment;
    state->demoWaveAmplitude = jlimit(0.0, 1.0, (double)state->demoWaveAmplitude);
}

void Push2Interface::e2Rotated(int increment){
    int trackNum = 0;  // Track #0
    float newVolume = state->audioTrackSettings[trackNum].volume += 0.25 * increment;
    newVolume = jlimit(-100.0, 6.0, (double)newVolume);
    engine->setTrackVolume(trackNum, newVolume);
}

void Push2Interface::e3Rotated(int increment){
    int trackNum = 1;  // Track #1
    float newVolume = state->audioTrackSettings[trackNum].volume += 0.25 * increment;
    newVolume = jlimit(-100.0, 6.0, (double)newVolume);
    engine->setTrackVolume(trackNum, newVolume);
}

void Push2Interface::e4Rotated(int increment){
    int trackNum = 2;  // Track #2
    float newVolume = state->audioTrackSettings[trackNum].volume += 0.25 * increment;
    newVolume = jlimit(-100.0, 6.0, (double)newVolume);
    engine->setTrackVolume(trackNum, newVolume);
}

void Push2Interface::e5Rotated(int increment){
    int trackNum = 3;  // Track #3
    float newVolume = state->audioTrackSettings[trackNum].volume += 0.25 * increment;
    newVolume = jlimit(-100.0, 6.0, (double)newVolume);
    engine->setTrackVolume(trackNum, newVolume);
}

void Push2Interface::e6Rotated(int increment){
    int trackNum = 4;  // Track #4
    float newVolume = state->audioTrackSettings[trackNum].volume += 0.25 * increment;
    newVolume = jlimit(-100.0, 6.0, (double)newVolume);
    engine->setTrackVolume(trackNum, newVolume);
}

void Push2Interface::e7Rotated(int increment){
    int trackNum = 5;  // Track #5
    float newVolume = state->audioTrackSettings[trackNum].volume += 0.25 * increment;
    newVolume = jlimit(-100.0, 6.0, (double)newVolume);
    engine->setTrackVolume(trackNum, newVolume);
}

void Push2Interface::e8Rotated(int increment){
    int trackNum = 6;  // Track #6
    float newVolume = state->audioTrackSettings[trackNum].volume += 0.25 * increment;
    newVolume = jlimit(-100.0, 6.0, (double)newVolume);
    engine->setTrackVolume(trackNum, newVolume);
    /*
     state->reverberationRoomSize += 0.04 * increment;
     state->reverberationRoomSize = jlimit(0.0, 1.0, (double)state->reverberationRoomSize);
     engine->setReverberationRoomSize(state->reverberationRoomSize);*/
}

//------------------------------------------------------------------------------

void Push2Interface::ba1Pressed(){
    auto& random = Random::getSystemRandom();
    Colour randomColour (random.nextInt (256),
                         random.nextInt (256),
                         random.nextInt (256));
    state->demoWaveColor = randomColour;
}

void Push2Interface::ba2Pressed(){
    engine->toggleMuteTrack(0);
}

void Push2Interface::ba3Pressed(){
    engine->toggleMuteTrack(1);
}

void Push2Interface::ba4Pressed(){
    engine->toggleMuteTrack(2);
}

void Push2Interface::ba5Pressed(){
    engine->toggleMuteTrack(3);
}

void Push2Interface::ba6Pressed(){
    engine->toggleMuteTrack(4);
}

void Push2Interface::ba7Pressed(){
    engine->toggleMuteTrack(5);
}

void Push2Interface::ba8Pressed(){
    engine->toggleMuteTrack(6);
}

void Push2Interface::playPressed(){
    engine->transportTogglePlayStop();
}

//------------------------------------------------------------------------------

void Push2Interface::padPressed(PadIJ padIJ, int velocity){
    // Update step sequencer pattern
    int samplerChannel = padIJ.i % 4;
    int step = padIJ.i < 4 ? padIJ.j : padIJ.j + 8;
    engine->updateStepSequencerPattern(samplerChannel, step);
}
