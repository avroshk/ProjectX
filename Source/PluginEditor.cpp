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
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 400);
    midiState = false;
    lastMidiNote = 0;
    startTimer(10);
    x=0; y=0;
}

ProjectXAudioProcessorEditor::~ProjectXAudioProcessorEditor()
{
}

//==============================================================================
void ProjectXAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    if(midiState) {
        g.fillAll (Colours::blue);
    } else {
        g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    }
    
    
 
    g.setColour (Colours::white);
    g.setFont (25.0f);
    g.drawFittedText (std::to_string(lastMidiNote), getLocalBounds(), Justification::centred, 2);
}

void ProjectXAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void ProjectXAudioProcessorEditor::mouseDown(const MouseEvent &event) {
    repaint();
}


void ProjectXAudioProcessorEditor::timerCallback() {
//    if (midiState != processor.isMidiIncoming()) {
//        midiState = processor.isMidiIncoming();
//        repaint();
//    }
    if (lastMidiNote != processor.getLastMidiNote()) {
        lastMidiNote = processor.getLastMidiNote();
        repaint();
    }
}



