/*
    ,--.                     ,--.     ,--.  ,--.
  ,-'  '-.,--.--.,--,--.,---.|  |,-.,-'  '-.`--' ,---. ,--,--,      Copyright 2018
  '-.  .-'|  .--' ,-.  | .--'|     /'-.  .-',--.| .-. ||      \   Tracktion Software
    |  |  |  |  \ '-'  \ `--.|  \  \  |  |  |  |' '-' '|  ||  |       Corporation
    `---' `--'   `--`--'`---'`--'`--' `---' `--' `---' `--''--'    www.tracktion.com

    Tracktion Engine uses a GPL/commercial licence - see LICENCE.md for details.
*/

namespace tracktion_engine
{

MidiModifierPlugin::MidiModifierPlugin (PluginCreationInfo info) : Plugin (info)
{
    semitones = addParam ("semitones up", TRANS("Semitones"),
                          { -getMaximumSemitones(), getMaximumSemitones() },
                          [] (float value)      { return std::abs (value) < 0.01f ? "(" + TRANS("Original pitch") + ")"
                                                                                  : getSemitonesAsString (value); },
                          [] (const String& s)  { return jlimit (-MidiModifierPlugin::getMaximumSemitones(),
                                                                 MidiModifierPlugin::getMaximumSemitones(),
                                                                 s.getFloatValue()); });

    semitonesValue.referTo (state, IDs::semitonesUp, getUndoManager());
    semitones->attachToCurrentValue (semitonesValue);
}

MidiModifierPlugin::~MidiModifierPlugin()
{
    notifyListenersOfDeletion();

    semitones->detachFromCurrentValue();
}

const char* MidiModifierPlugin::xmlTypeName ("midiModifier");

String MidiModifierPlugin::getName()                                               { return TRANS("MIDI Modifier"); }
String MidiModifierPlugin::getPluginType()                                         { return xmlTypeName; }
String MidiModifierPlugin::getShortName (int)                                      { return TRANS("MIDI Modifier"); }
void MidiModifierPlugin::initialise (const PlaybackInitialisationInfo&)            {}
void MidiModifierPlugin::deinitialise()                                            {}
double MidiModifierPlugin::getLatencySeconds()                                     { return 0.0; }
int MidiModifierPlugin::getNumOutputChannelsGivenInputs (int)                      { return 0; }
void MidiModifierPlugin::getChannelNames (StringArray*, StringArray*)              {}
bool MidiModifierPlugin::takesAudioInput()                                         { return false; }
bool MidiModifierPlugin::canBeAddedToClip()                                        { return false; }
bool MidiModifierPlugin::needsConstantBufferSize()                                 { return false; }

void MidiModifierPlugin::applyToBuffer (const AudioRenderContext& fc)
{
    if (fc.bufferForMidiMessages != nullptr)
        fc.bufferForMidiMessages->addToNoteNumbers (roundToInt (semitones->getCurrentValue()));
}

String MidiModifierPlugin::getSelectableDescription()
{
    return TRANS("MIDI Modifier Plugin");
}


void MidiModifierPlugin::restorePluginStateFromValueTree (const juce::ValueTree& v)
{
    CachedValue<float>* cvsFloat[]  = { &semitonesValue, nullptr };
    copyPropertiesToNullTerminatedCachedValues (v, cvsFloat);

    for (auto p : getAutomatableParameters())
        p->updateFromAttachedValue();
}

}
