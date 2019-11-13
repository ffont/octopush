/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Push2Interface.h"
#include "Push2Simulator.h"
#include "Engine.h"

//==============================================================================
class OctopushOSApplication  : public JUCEApplication
{
public:
    //==============================================================================
    OctopushOSApplication() {}

    const String getApplicationName() override       { return ProjectInfo::projectName; }
    const String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override       { return false; }

    //==============================================================================
    void initialise (const String& commandLine) override
    {
        // Parse command line arguments
        int displayFrameRate = DEFAULT_PUSH_DISPLAY_FRAME_RATE;
        int stateUpdateFrameRate = DEFAULT_STATE_UPDATE_RATE;
        int maxEncoderUpdateRate = DEFAULT_ENCODER_ROTATION_MAX_MESSAGE_RATE_HZ;
        bool playOnStart = DEFAULT_PLAY_ON_START;
        
        StringArray arguments = getCommandLineParameterArray();
        for (int i=0; i<arguments.size(); i++){
            String argument = arguments[i];
            if (argument == "-dfr"){
                String value = arguments[i+1];
                displayFrameRate = value.getIntValue();
            }
            else if (argument == "-sur"){
                String value = arguments[i+1];
                stateUpdateFrameRate = value.getIntValue();
            }
            else if(argument == "-eur"){
                String value = arguments[i+1];
                maxEncoderUpdateRate = value.getIntValue();
            }
            else if (argument == "-pos"){
                playOnStart = true;
            }
        }
        
        // Initialize application engine and Push2 interface
        engine.initialize(playOnStart, stateUpdateFrameRate);
        push.initialize(&engine, displayFrameRate, maxEncoderUpdateRate);
    }

    void shutdown() override
    {
    }

    //==============================================================================
    void systemRequestedQuit() override
    {
        // This is called when the app is being asked to quit: you can ignore this
        // request and let the app carry on running, or call quit() to allow the app to close.
        quit();
    }

    void anotherInstanceStarted (const String& commandLine) override
    {
        // When another instance of the app is launched while this one is running,
        // this method is invoked, and the commandLine parameter tells you what
        // the other instance's command-line arguments were.
    }

    
private:
    // App engine
    Engine engine;
    
    // Push interface
    Push2Interface push;
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (OctopushOSApplication)
