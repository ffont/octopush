/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

//#include "Push2Interface.h"
//#include "OctopushAudioEngine.h"
#include "Utilities.h"  // Tracktion engine utilities


static String organPatch = "<PLUGIN type=\"4osc\" windowLocked=\"1\" id=\"1069\" enabled=\"1\" filterType=\"1\" presetDirty=\"0\" presetName=\"4OSC: Organ\" filterFreq=\"127.00000000000000000000\" ampAttack=\"0.60000002384185791016\" ampDecay=\"10.00000000000000000000\" ampSustain=\"100.00000000000000000000\" ampRelease=\"0.40000000596046447754\" waveShape1=\"4\" tune2=\"-24.00000000000000000000\" waveShape2=\"4\"> <MACROPARAMETERS id=\"1069\"/> <MODIFIERASSIGNMENTS/> <MODMATRIX/> </PLUGIN>";


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
    static void setupInputs (te::Edit& edit)
    {
        auto& dm = edit.engine.getDeviceManager();
        
        for (int i = 0; i < dm.getNumMidiInDevices(); i++)
        {
            auto dev = dm.getMidiInDevice (i);
            dev->setEnabled (true);
            dev->setEndToEndEnabled (true);
        }
        
        edit.playInStopEnabled = true;
        edit.getTransport().ensureContextAllocated (true);

        // Add the midi input to track 1
        if (auto t = EngineHelpers::getOrInsertAudioTrackAt (edit, 0))
            if (auto dev = dm.getMidiInDevice (0))
                for (auto instance : edit.getAllInputDevices())
                    if (&instance->getInputDevice() == dev)
                        instance->setTargetTrack (*t, 0, true);

        // Also add the same midi input to track 2
        if (auto t = EngineHelpers::getOrInsertAudioTrackAt (edit, 1))
            if (auto dev = dm.getMidiInDevice (0))
                for (auto instance : edit.getAllInputDevices())
                    if (&instance->getInputDevice() == dev)
                        instance->setTargetTrack (*t, 0, false);


        edit.restartPlayback();
    }

    static void setupOutputs (te::Edit& edit)
    {
        auto& dm = edit.engine.getDeviceManager();

        for (int i = 0; i < dm.getNumMidiOutDevices(); i++)
        {
            auto dev = dm.getMidiOutDevice (i);
            dev->setEnabled (true);
        }

        edit.playInStopEnabled = true;
        edit.getTransport().ensureContextAllocated (true);

        // Set track 2 to send to midi output
        if (auto t = EngineHelpers::getOrInsertAudioTrackAt (edit, 1))
        {
            auto& output = t->getOutput();
            output.setOutputToDefaultDevice (true);
        }

        edit.restartPlayback();
    }

    static void create4OSCPlugin (te::Edit& edit)
    {
        if (auto synth = dynamic_cast<te::FourOscPlugin*> (edit.getPluginCache().createNewPlugin (te::FourOscPlugin::xmlTypeName, {}).get()))
        {
            auto vt = ValueTree::fromXml (organPatch);
            
            if (vt.isValid())
                synth->restorePluginStateFromValueTree (vt);
            
            if (auto t = EngineHelpers::getOrInsertAudioTrackAt (edit, 0))
                t->pluginList.insertPlugin (*synth, 0, nullptr);
        }
    }
    
    //==============================================================================
    
    class PluginEngineBehaviour : public te::EngineBehaviour
    {
    public:
        bool autoInitialiseDeviceManager() override { return false; }
    };
    
    //==============================================================================
    
    struct EngineWrapper
    {
        EngineWrapper()
            : audioInterface (engine.getDeviceManager().getHostedAudioDeviceInterface())
        {
            JUCE_ASSERT_MESSAGE_THREAD
            audioInterface.initialise ({});
            
            /*
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
            #endif*/
            
            setupInputs (edit);
            setupOutputs (edit);
            create4OSCPlugin (edit);
            
            // Add background playing file in loop
            if (auto track = EngineHelpers::getOrInsertAudioTrackAt (edit, 2)){
                auto f = File::createTempFile ("test_file.wav");
                f.replaceWithData (BinaryData::_31655_wav, BinaryData::_31655_wavSize);
                te::AudioFile audioFile (engine, f);
                auto clip = track->insertWaveClip (f.getFileNameWithoutExtension(), f, { { 0.0, audioFile.getLength() }, 0.0 }, false);
            }
            
            // Configure transport and start playing
            edit.tempoSequence.getTempos()[0]->setBpm (130);
            transport.setLoopRange (te::EditTimeRange(0.0, 60.0 / 130.0 * 4.0)); // Will this be 1 bar (?)
            transport.looping = true;
            transport.position = 0.0;
            transport.play(false);
            edit.clickTrackEnabled = true;
        }

        te::Engine engine { ProjectInfo::projectName, nullptr, std::make_unique<PluginEngineBehaviour>() };
        te::Edit edit { engine, te::createEmptyEdit (engine), te::Edit::forEditing, nullptr, 0 };
        te::TransportControl& transport { edit.getTransport() };
        te::HostedAudioDeviceInterface& audioInterface;
        te::ExternalPlayheadSynchroniser playheadSynchroniser { edit };
        
        // Ocotpush app engine and push2 interface
        //OctopushAudioEngine octopush_audio_engine;
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
