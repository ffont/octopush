/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"



OctopushOsAudioProcessor::OctopushOsAudioProcessor()
    : AudioProcessor (BusesProperties().withInput  ("Input",  AudioChannelSet::stereo())
                                       .withOutput ("Output", AudioChannelSet::stereo()))
{
}

OctopushOsAudioProcessor::~OctopushOsAudioProcessor()
{
}

//==============================================================================
bool OctopushOsAudioProcessor::hasEditor() const
{
    #if !ELK_BUILD
        return true; // (change this to false if you choose to not supply an editor)
    #else
        return false;
    #endif
}

AudioProcessorEditor* OctopushOsAudioProcessor::createEditor()
{
    return new OctopushOsAudioProcessorEditor (*this);
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

bool OctopushOsAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;

    return true;
}

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
