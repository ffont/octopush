/*
  ==============================================================================

    Push2Interface.cpp
    Created: 24 Oct 2019 6:26:33pm
    Author:  Frederic Font Corbera

  ==============================================================================
*/

#include "Push2Interface.h"


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
}

//------------------------------------------------------------------------------

void Push2Interface::initialize(Engine* engine_)
{
    // Assign reference to application engine
    engine = engine_;
    engine->addActionListener(this);
    
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
    
    // Init properties
    frameWaveHeightMultiplier = 1.0;
    waveformColor = Colours::white;
    elapsedTimeAnimation = 0;
    
    // Start the timer to draw the animation
    startTimerHz(PUSH_DISPLAY_FRAME_RATE);
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
    result = openMidiDevice();
    RETURN_IF_FAILED_MESSAGE(result, "Failed to open midi device");
    
    return NBase::Result::NoError;
}


//------------------------------------------------------------------------------

NBase::Result Push2Interface::openMidiDevice()
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
        return NBase::Result("Failed to open input device");
    }
    
    // Store and starts listening to the device
    midiInput = MidiInput::openDevice(deviceIndex, this);
    
    midiInput.get()->start();
    
    return NBase::Result::NoError;
}


//------------------------------------------------------------------------------

void Push2Interface::handleIncomingMidiMessage (MidiInput* /*source*/, const MidiMessage &message)
{
    if (triggerButtonActionsFromIncommingMidi(message)) { return; };
    if (triggerEncoderActionsFromIncommingMidi(message)) { return; };
}


//------------------------------------------------------------------------------

void Push2Interface::timerCallback()
{
    elapsedTimeAnimation += 0.02f;
    drawFrame();
}


//------------------------------------------------------------------------------

Image Push2Interface::computeFrame()
{
    // Create a path for the animated wave
    const auto height = ableton::Push2DisplayBitmap::kHeight;
    const auto width = ableton::Push2DisplayBitmap::kWidth;
    
    Image frame = Image(Image::RGB, width, height, true);
    Graphics g(frame);
    
    // Clear previous frame
    g.fillAll(juce::Colour(0xff000000));
    
    Path wavePath;
    
    const float waveStep = 10.0f;
    const float waveY = height * 0.44f;
    int i = 0;
    
    for (float x = waveStep * 0.5f; x < width; x += waveStep)
    {
        const float y1 = waveY + height * 0.10f * std::sin(i * 0.38f + elapsedTimeAnimation) * frameWaveHeightMultiplier;
        const float y2 = waveY + height * 0.20f * std::sin(i * 0.20f + elapsedTimeAnimation * 2.0f) * frameWaveHeightMultiplier;
        
        wavePath.addLineSegment(Line<float>(x, y1, x, y2), 2.0f);
        wavePath.addEllipse(x - waveStep * 0.3f, y1 - waveStep * 0.3f, waveStep * 0.6f, waveStep * 0.6f);
        wavePath.addEllipse(x - waveStep * 0.3f, y2 - waveStep * 0.3f, waveStep * 0.6f, waveStep * 0.6f);
        
        ++i;
    }
    
    // Draw the path
    g.setColour(waveformColor);
    g.fillPath(wavePath);
    
    // Blit the logo on top
    // auto logo = ImageCache::getFromMemory(BinaryData::PushStartup_png, BinaryData::PushStartup_pngSize);
    // g.drawImageAt(logo, (width - logo.getWidth()) / 2 , (height - logo.getHeight()) / 2);
    
    
    return frame;
}



void Push2Interface::drawFrame()
{
    lastFrame = computeFrame();
    
    if (pushInitializedSuccessfully)
    {
        // Request a juce::Graphics from the bridge
        auto& g = bridge.GetGraphic();
        g.drawImageAt(lastFrame, 0, 0, false);
        
        // Tells the bridge we're done with drawing and the frame can be sent to the display
        bridge.Flip();
    }
    
    // Update main component as well so it shows on screen the same thing that in Push screen
    sendActionMessage("NEW_FRAME_AVAILABLE");
}


//------------------------------------------------------------------------------

void Push2Interface::actionListenerCallback (const String &message)
{
    
}


//------------------------------------------------------------------------------

void Push2Interface::e1Rotated(int increment){
    
    frameWaveHeightMultiplier += 0.04 * increment;
    frameWaveHeightMultiplier = jlimit(0.0, 1.0, (double)frameWaveHeightMultiplier);
}

//------------------------------------------------------------------------------

void Push2Interface::ba1Pressed(){
    auto& random = Random::getSystemRandom();
    Colour randomColour (random.nextInt (256),
                         random.nextInt (256),
                         random.nextInt (256));
    waveformColor = randomColour;
}

void Push2Interface::playPressed(){
    engine->transportTogglePlayStop();
}
