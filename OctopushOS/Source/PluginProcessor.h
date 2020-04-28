/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

//#include "Push2Interface.h"
#include "OctopushAudioEngine.h"
//#include "Utilities.h"  // Tracktion engine utilities


//==============================================================================
/**
*/
class OctopushOsAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================  
    OctopushOsAudioProcessor()
        : AudioProcessor (BusesProperties().withInput  ("Input",  AudioChannelSet::stereo())
                                           .withOutput ("Output", AudioChannelSet::stereo()))
    {
    }
    
    ~OctopushOsAudioProcessor()
    {
        std::cout << "OctopushOsAudioProcessor destructor called..." << std::endl;
    }
    
    //==============================================================================
    void prepareToPlay (double sampleRate, int expectedBlockSize) override
    {
        // On Linux the plugin and prepareToPlay may not be called on the message thread.
        // Engine needs to be created on the message thread so we'll do that now
        ensureEngineCreatedOnMessageThread();
        
        setLatencySamples (expectedBlockSize);
        ensurePrepareToPlayCalledOnMessageThread (sampleRate, expectedBlockSize);
    }
    
    void releaseResources() override
    {
        // When playback stops, you can use this as an opportunity to free up any
        // spare memory, etc.
    }
    
    void processBlock (AudioBuffer<float>& buffer, MidiBuffer& midi) override
    {
        // Update position info first
        engineWrapper->playheadSynchroniser.synchronise (*this);

        ScopedNoDenormals noDenormals;
        
        auto totalNumInputChannels  = getTotalNumInputChannels();
        auto totalNumOutputChannels = getTotalNumOutputChannels();

        for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
            buffer.clear (i, 0, buffer.getNumSamples());

        engineWrapper->audioInterface.processBlock (buffer, midi);
    }

    //==============================================================================
    AudioProcessorEditor* createEditor() override          { return new OctopushOsAudioProcessorEditor (*this); }
    bool hasEditor() const override                        { return true;   }
 
    //==============================================================================
    const String getName() const override                  { return JucePlugin_Name;}
    bool acceptsMidi() const override                      { return true; }
    bool producesMidi() const override                     { return true; }
    double getTailLengthSeconds() const override           { return 0; }

    //==============================================================================
    int getNumPrograms() override                          { return 1; }
    int getCurrentProgram() override                       { return 0; }
    void setCurrentProgram (int) override                  {}
    const String getProgramName (int) override             { return {}; }
    void changeProgramName (int, const String&) override   {}
    
    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override
    {
        // You should use this method to store your parameters in the memory block.
        // You could do that either as raw data, or use the XML or ValueTree classes
        // as intermediaries to make it easy to save and load complex data.
    }
    
    void setStateInformation (const void* data, int sizeInBytes) override
    {
        // You should use this method to restore your parameters from this memory block,
        // whose contents will have been created by the getStateInformation() call.
    }
    //==============================================================================
    
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override
    {
        if (layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
            return false;

        if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
            return false;

        return true;
    }


private:
    
    //==============================================================================
    
    class PluginEngineBehaviour : public te::EngineBehaviour
    {
    public:
        bool autoInitialiseDeviceManager() override { return false; }
        int getNumberOfCPUsToUseForAudio() override { return 1; }
    };
    
    //==============================================================================
    
    struct EngineWrapper
    {
        EngineWrapper()
            : audioInterface (engine.getDeviceManager().getHostedAudioDeviceInterface())
        {
            JUCE_ASSERT_MESSAGE_THREAD
            audioInterface.initialise ({});
            
            // Octopush app initialize
            bool playOnStart = DEFAULT_PLAY_ON_START;
            int stateUpdateFrameRate = DEFAULT_STATE_UPDATE_RATE;
            int displayFrameRate = DEFAULT_PUSH_DISPLAY_FRAME_RATE;
            int maxEncoderUpdateRate = DEFAULT_ENCODER_ROTATION_MAX_MESSAGE_RATE_HZ;
            bool minimalEngine = DEFAULT_MINIMAL_ENGINE;
            
            #if ELK_BUILD
            std::cout << "Configuring Octopush for ELK build" << std::endl;
            minimalEngine = true;
            stateUpdateFrameRate = 0;
            displayFrameRate = 0;
            #endif
                       
            oae.initialize(&engine, &edit, playOnStart, stateUpdateFrameRate, minimalEngine);
            #if !ELK_BUILD
            //push.initialize(&oae, displayFrameRate, maxEncoderUpdateRate);
            #endif

        }

        te::Engine engine { ProjectInfo::projectName, nullptr, std::make_unique<PluginEngineBehaviour>() };
        te::Edit edit { engine, te::createEmptyEdit (engine), te::Edit::forEditing, nullptr, 0 };
        //te::TransportControl& transport { edit.getTransport() };
        te::HostedAudioDeviceInterface& audioInterface;
        te::ExternalPlayheadSynchroniser playheadSynchroniser { edit };
        
        // Ocotpush app engine and push2 interface
        OctopushAudioEngine oae;
        //Push2Interface push;
    };

    
    //==============================================================================
    
    template<typename Function>
    void callFunctionOnMessageThread (Function&& func)
    {
        if (MessageManager::getInstance()->isThisTheMessageThread())
        {
            func();
        }
        else
        {
            jassert (! MessageManager::getInstance()->currentThreadHasLockedMessageManager());
            WaitableEvent finishedSignal;
            MessageManager::callAsync ([&]
                                       {
                                           func();
                                           finishedSignal.signal();
                                       });
            finishedSignal.wait (-1);
        }
    }
    
    void ensureEngineCreatedOnMessageThread()
    {
        if (! engineWrapper)
            callFunctionOnMessageThread ([&] { engineWrapper = std::make_unique<EngineWrapper>(); });
    }
    
    void ensurePrepareToPlayCalledOnMessageThread (double sampleRate, int expectedBlockSize)
    {
        jassert (engineWrapper);
        callFunctionOnMessageThread ([&] { engineWrapper->audioInterface.prepareToPlay (sampleRate, expectedBlockSize); });
    }
    
    //==============================================================================
    
    std::unique_ptr<EngineWrapper> engineWrapper;
    
    //==============================================================================
    
    class OctopushOsAudioProcessorEditor : public AudioProcessorEditor
    {
    public:
        OctopushOsAudioProcessorEditor (OctopushOsAudioProcessor& p)
            : AudioProcessorEditor (p),
              processor (p)
        {
            // Make sure that before the constructor has finished, you've set the
            // editor's size to whatever you need it to be.
            setSize (400, 300);
            
            /*
            
            #if ELK_BUILD
                // If no ELK build, don't load Push2 simulator
            
            #else
                // If on a normal build, follow some heuristics to decide if the Push2 simulator should be shown
                // (if on debug build and push is not connected)
            
                #if JUCE_DEBUG
                bool debug = true;
                #else
                bool debug = false;
                #endif
                bool showSimulator = false;
                String showSimulatorValue = "";
                
                if (showSimulatorValue == "show"){
                    showSimulator = true;
                } else if (showSimulatorValue == "hide"){
                    showSimulator = false;
                } else {
                    // If not force/hide show simulator we'll only show it if push was not initialized properly and we're in debug mode
                    //if (!processor.engineWrapper->push.pushInitializedSuccessfully && debug){
                    //    showSimulator = true;
                    //}
                }
                
                if (showSimulator) {
                    setSize (900, 726);
                    //push2SimulatorComponent.setPush2Interface(&processor.engineWrapper->push);
                    //addAndMakeVisible(push2SimulatorComponent);
                }
            #endif
            */
        }
        

        //==============================================================================
        void paint (Graphics& g) override
        {
            g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
            g.setColour (Colours::white);
            g.setFont (15.0f);
            g.drawFittedText ("OctopushOS up and running!", getLocalBounds(), Justification::centred, 1);
        }

        void resized() override
        {
            #if !ELK_BUILD
                #if JUCE_DEBUG
                //if (!processor.engineWrapper->push.pushInitializedSuccessfully) {
                //    push2SimulatorComponent.setBounds(getBounds());
                //}
                #endif
            #endif
        }
        
    private:
        OctopushOsAudioProcessor& processor;
        //Push2Simulator push2SimulatorComponent;
        
    };
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OctopushOsAudioProcessor)
    
};
