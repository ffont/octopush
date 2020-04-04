/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
OctopushOsAudioProcessor::OctopushOsAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

OctopushOsAudioProcessor::~OctopushOsAudioProcessor()
{
}

//==============================================================================
const String OctopushOsAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool OctopushOsAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool OctopushOsAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool OctopushOsAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double OctopushOsAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int OctopushOsAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int OctopushOsAudioProcessor::getCurrentProgram()
{
    return 0;
}

void OctopushOsAudioProcessor::setCurrentProgram (int index)
{
}

const String OctopushOsAudioProcessor::getProgramName (int index)
{
    return {};
}

void OctopushOsAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void OctopushOsAudioProcessor::prepareToPlay (double sampleRate, int expectedBlockSize)
{
    // On Linux the plugin and prepareToPlay may not be called on the message thread.
    // Engine needs to be created on the message thread so we'll do that now
    ensureEngineCreatedOnMessageThread();
    
    setLatencySamples (expectedBlockSize);
    ensurePrepareToPlayCalledOnMessageThread (sampleRate, expectedBlockSize);
}

void OctopushOsAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool OctopushOsAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void OctopushOsAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    // Update position info first
    engineWrapper->playheadSynchroniser.synchronise (*this);

    ScopedNoDenormals noDenormals;
    
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    engineWrapper->audioInterface.processBlock (buffer, midiMessages);
}

//==============================================================================
bool OctopushOsAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* OctopushOsAudioProcessor::createEditor()
{
    return new OctopushOsAudioProcessorEditor (*this);
}

//==============================================================================
void OctopushOsAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void OctopushOsAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new OctopushOsAudioProcessor();
}
