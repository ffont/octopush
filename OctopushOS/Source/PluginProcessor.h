/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Push2Interface.h"
#include "Engine.h"

//==============================================================================
/**
*/
class OctopushOsAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    OctopushOsAudioProcessor();
    ~OctopushOsAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int expectedBlockSize) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
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
                       
            octopush_engine.initialize(&engine, &edit, playOnStart, stateUpdateFrameRate, minimalEngine);
            push.initialize(&octopush_engine, displayFrameRate, maxEncoderUpdateRate);
        }

        te::Engine engine { ProjectInfo::projectName, nullptr, std::make_unique<PluginEngineBehaviour>() };
        te::Edit edit { engine, te::createEmptyEdit (engine), te::Edit::forEditing, nullptr, 0 };
        te::HostedAudioDeviceInterface& audioInterface;
        te::ExternalPlayheadSynchroniser playheadSynchroniser { edit };
        
        // Ocotpush app engine and push2 interface
        Engine octopush_engine;
        Push2Interface push;
    };
    std::unique_ptr<EngineWrapper> engineWrapper;  // Should this be private??
    
private:
    
    class PluginEngineBehaviour : public te::EngineBehaviour
    {
    public:
        bool autoInitialiseDeviceManager() override { return false; }
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
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OctopushOsAudioProcessor)

};
