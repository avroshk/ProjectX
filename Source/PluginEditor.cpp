/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
ProjectXAudioProcessorEditor::ProjectXAudioProcessorEditor (ProjectXAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (600, 400);
    midiState = false;
    lastMidiNote = 0;
    startTimer(10);
    x=0; y=0;
    
    drawSpace = new DrawSpace();
}

ProjectXAudioProcessorEditor::~ProjectXAudioProcessorEditor()
{

}

//==============================================================================
void ProjectXAudioProcessorEditor::paint (Graphics& g)
{
    if(midiState) {
        g.fillAll (Colours::blue);
    } else {
        g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    }
    
    g.setColour (Colours::white);
    g.setFont (25.0f);
    g.drawFittedText (std::to_string(lastMidiNote), getLocalBounds(), Justification::centred, 2);
    
    drawSpace->renderOpenGL();
}

void ProjectXAudioProcessorEditor::resized()
{

}

void ProjectXAudioProcessorEditor::mouseDown(const MouseEvent &event) {
    repaint();
}

void ProjectXAudioProcessorEditor::timerCallback() {
    if (lastMidiNote != processor.getLastMidiNote()) {
        lastMidiNote = processor.getLastMidiNote();
        repaint();
    }
}



