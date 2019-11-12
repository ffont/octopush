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
        // Initialize application engine and Push2 interface
        engine.initialize();
        push.initialize(&engine);
        
        // Initialize main window (will only be used to replicate Push2 display and controls when Push2
        // is not connected and we are in DEBUG mode)
        #if JUCE_DEBUG
        if (!push.pushInitializedSuccessfully) {
            mainWindow.reset (new MainWindow (getApplicationName()));
            static_cast<Push2Simulator*>(mainWindow.get()->getContentComponent())->setPush2Interface(&push);
            mainWindowRunning = true;
        }
        #endif
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
