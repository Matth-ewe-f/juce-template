#pragma once
#include "PluginProcessor.h"
#include "CtmLookAndFeel.h"
#include "ParameterControl.h"
#include "ComboBoxControl.h"

class PluginEditor final : public juce::AudioProcessorEditor
{
public:
    // === Lifecycle ==========================================================
    explicit PluginEditor(PluginProcessor&);
    ~PluginEditor() override;

    // === Graphics ===========================================================
    void paint(juce::Graphics&) override;
    void resized() override;

private:
    PluginProcessor& processorRef;
    CtmLookAndFeel lookAndFeel;
    
    // === Helper Functions ===================================================
    void addParameterControl(ParameterControl*);
    void addComboBoxControl(ComboBoxControl*);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
