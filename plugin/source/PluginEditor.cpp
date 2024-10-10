#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor
(AudioPluginAudioProcessor &p)
    : AudioProcessorEditor(&p), processorRef(p)
{
    juce::ignoreUnused(processorRef);
    // Make sure to set size before the constructor finishes
    setSize(400, 300);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint(juce::Graphics &g)
{
    auto colorId = juce::ResizableWindow::backgroundColourId;
    g.fillAll(getLookAndFeel().findColour(colorId));

    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    auto justify = juce::Justification::centred;
    g.drawFittedText("Hello World!", getLocalBounds(), justify, 1);
}

void AudioPluginAudioProcessorEditor::resized()
{
    // Generally where you'll lay out any subcomponents in your editor
}