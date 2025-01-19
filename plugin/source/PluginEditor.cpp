#include "PluginEditor.h"

const int PluginEditor::width = 400;
const int PluginEditor::height = 300;

// === Lifecycle ==============================================================
PluginEditor::PluginEditor (PluginProcessor &p)
    : AudioProcessorEditor(&p), processorRef(p)
{
    setLookAndFeel(&lookAndFeel);
    setSize(width, height); // make sure setSize is the last function called
}

PluginEditor::~PluginEditor() { }

// === Graphics ===============================================================
void PluginEditor::paint(juce::Graphics &g)
{
    g.fillAll(findColour(CtmColourIds::normalBgColourId));
    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    auto justify = juce::Justification::centred;
    g.drawFittedText("Hello World!", getLocalBounds(), justify, 1);
}

void PluginEditor::resized()
{
    // control layout here
}

// === Helper Functions =======================================================
void PluginEditor::addParameterControl(ParameterControl* control)
{
    addAndMakeVisible(control->slider);
    addAndMakeVisible(control->label);
}

void PluginEditor::addComboBoxControl(ComboBoxControl* control)
{
    addAndMakeVisible(control->comboBox);
    addAndMakeVisible(control->title);
}