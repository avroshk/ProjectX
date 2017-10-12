/*
  ==============================================================================

    DrawSpace.h
    Created: 11 Oct 2017 11:14:38pm
    Author:  Avrosh Kumar

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"

class DrawSpace : public Component, public OpenGLRenderer
{
public:
    DrawSpace();
    ~DrawSpace();
    
    void openGLContextClosing() override;
    void renderOpenGL() override;
    void newOpenGLContextCreated() override;

private:
    OpenGLContext openGLContext;    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DrawSpace)
};

#pragma once
