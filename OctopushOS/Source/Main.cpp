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
        String showSimulatorValue = "";  // Anything different than "show" or "hide" will mean "default"
        bool playOnStart = DEFAULT_PLAY_ON_START;
        bool minimalEngine = false;
        
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
            else if (argument == "-sim"){
                showSimulatorValue = arguments[i+1];
            }
            else if (argument == "-pos"){
                playOnStart = true;
            }
            else if (argument == "-minimal"){
                minimalEngine = true;  // This will set up the audio engine with only one channel and one file
            }
        }
        
        // Initialize application engine and Push2 interface
        engine.initialize(playOnStart, stateUpdateFrameRate, minimalEngine);
        push.initialize(&engine, displayFrameRate, maxEncoderUpdateRate);
        
        // Initialize simulator in main window (if requested)
        #if JUCE_DEBUG
        bool debug = true;
        #else
        bool debug = false;
        #endif
        bool showSimulator = false;
        
        if (showSimulatorValue == "show"){
            showSimulator = true;
        } else if (showSimulatorValue == "hide"){
            showSimulator = false;
        } else {
            // If not force/hide show simulator we'll only show it if push was not initialized properly and we're in debug mode
            if (!push.pushInitializedSuccessfully && debug){
                showSimulator = true;
            }
        }
       
        if (showSimulator) {
            mainWindow.reset (new MainWindow (getApplicationName()));
            static_cast<Push2Simulator*>(mainWindow.get()->getContentComponent())->setPush2Interface(&push);
            mainWindowRunning = true;
        }
    }

    void shutdown() override
    {
        // Add your application's shutdown code here..
        if (mainWindowRunning){
            mainWindow = nullptr; // (deletes our window)
        }
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

    //==============================================================================
    /*
        This class implements the desktop window that contains an instance of
        our Push2Simulator class.
    */
    class MainWindow    : public DocumentWindow
    {
    public:
        MainWindow (String name)  : DocumentWindow (name,
                                                    Desktop::getInstance().getDefaultLookAndFeel()
                                                                          .findColour (ResizableWindow::backgroundColourId),
                                                    DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar (true);
            setContentOwned (new Push2Simulator(), true);

           #if JUCE_IOS || JUCE_ANDROID
            setFullScreen (true);
           #else
            setResizable (true, true);
            centreWithSize (getWidth(), getHeight());
           #endif

            setVisible (true);
        }

        void closeButtonPressed() override
        {
            // This is called when the user tries to close this window. Here, we'll just
            // ask the app to quit when this happens, but you can change this to do
            // whatever you need.
            JUCEApplication::getInstance()->systemRequestedQuit();
        }

        /* Note: Be careful if you override any DocumentWindow methods - the base
           class uses a lot of them, so by overriding you might break its functionality.
           It's best to do all your work in your content component instead, but if
           you really have to override any DocumentWindow methods, make sure your
           subclass also calls the superclass's method.
        */

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };

private:
    // App engine
    Engine engine;
    
    // Push interface
    Push2Interface push;
    
    // Main window (not really used when deployed to hardware, just used to replicate Push2 display contents)
    bool mainWindowRunning = false;
    std::unique_ptr<MainWindow> mainWindow;
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (OctopushOSApplication)
