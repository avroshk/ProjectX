/*
  ==============================================================================

    DrawSpace.cpp
    Created: 11 Oct 2017 11:14:38pm
    Author:  Avrosh Kumar

  ==============================================================================
*/

#include "DrawSpace.h"

DrawSpace::DrawSpace() {
    setSize(200,200);
    
    openGLContext.setComponentPaintingEnabled (true);
    openGLContext.attachTo (*this);
}

DrawSpace::~DrawSpace() {
    openGLContext.detach();
}

void DrawSpace::openGLContextClosing() {
    
}

void DrawSpace::newOpenGLContextCreated() {
    
}

void DrawSpace::renderOpenGL() {
    jassert (OpenGLHelpers::isContextActive());
    
    OpenGLHelpers::clear (Colours::white);

    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


