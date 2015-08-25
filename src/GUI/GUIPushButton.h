#pragma once

#include "GUI.h"

using namespace ci;

class GUIPushButton;

typedef std::shared_ptr <GUIPushButton> pushButPtr;

class GUIPushButton : public GUIElement
{
public:
    GUIPushButton ();
    
    ~GUIPushButton ();
    
    void draw ();
    
    void draw (float x, float y);
    
    void update (float elapsedTime, Vec2i mouseLocation, bool mousePressed);
    
protected:
    
    bool m_mouseOver;

};