/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Push2Demo.h"

namespace te = tracktion_engine;


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public AudioAppComponent,
                        public ActionListener,
                        private ChangeListener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;
    
    //==============================================================================
    void actionListenerCallback (const String &message) override;

private:
    // Push interface
    Demo push;
    
    // Tracktion engine
    te::Engine engine { ProjectInfo::projectName };
    std::unique_ptr<te::Edit> edit;
    void changeListenerCallback (ChangeBroadcaster*) override
    {
        // Do nothing, this is to comply with ChangeListener inheritance
    }
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
