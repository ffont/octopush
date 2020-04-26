/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Push2Interface.h"
#include "OctopushAudioEngine.h"


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
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;
    
    //==============================================================================
    const String getName() const override                  { return JucePlugin_Name;}
    bool acceptsMidi() const override                      { return true; }
    bool producesMidi() const override                     { return true; }
    bool isMidiEffect() const override                     { return false; }
    double getTailLengthSeconds() const override           { return 0; }

    //==============================================================================
    int getNumPrograms() override                          { return 1; }
    int getCurrentProgram() override                       { return 0; }
    void setCurrentProgram (int) override                  {}
    const String getProgramName (int) override             { return {}; }
    void changeProgramName (int, const String&) override   {}
    
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
            
            #if ELK_BUILD
            std::cout << "Configuring Octopush for ELK build" << std::endl;
            minimalEngine = true;
            stateUpdateFrameRate = 0;
            displayFrameRate = 0;
            #endif
                       
            octopush_audio_engine.initialize(&engine, &edit, playOnStart, stateUpdateFrameRate, minimalEngine);
            #if !ELK_BUILD
            push.initialize(&octopush_audio_engine, displayFrameRate, maxEncoderUpdateRate);
            #endif
        }

        te::Engine engine { ProjectInfo::projectName, nullptr, std::make_unique<PluginEngineBehaviour>() };
        te::Edit edit { engine, te::createEmptyEdit (engine), te::Edit::forEditing, nullptr, 0 };
        te::HostedAudioDeviceInterface& audioInterface;
        te::ExternalPlayheadSynchroniser playheadSynchroniser { edit };
        
        // Ocotpush app engine and push2 interface
        OctopushAudioEngine octopush_audio_engine;
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
