#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new OctopushOsAudioProcessor();
}
