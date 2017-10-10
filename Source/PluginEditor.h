/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/

//class DrawArea : public Component {
//public:
//    DrawArea();
//    ~DrawArea();
//    void paint(Graphics& g) override;
//    void mouseDown(const MouseEvent& event) override;
//};


class ProjectXAudioProcessorEditor  : public AudioProcessorEditor, private Timer
{
public:
    ProjectXAudioProcessorEditor (ProjectXAudioProcessor&);
    ~ProjectXAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void mouseDown(const MouseEvent& event) override;
    void timerCallback() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ProjectXAudioProcessor& processor;
    bool midiState;
    int lastMidiNote;
    int x,y;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ProjectXAudioProcessorEditor)
};


