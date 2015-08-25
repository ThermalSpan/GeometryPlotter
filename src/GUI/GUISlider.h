#pragma once

#include "GUI.h"

class GUISlider;

typedef std::shared_ptr <GUISlider> sliderPtr;

class GUISlider : public GUIElement
{
public:
    GUISlider ();

    ~GUISlider ();

    void draw ();

    void draw (float x, float y);

    void update (float elapsedTime, Vec2i mouseLocation, bool mousePressed);

    void addHandler (sliderHandPtr &handler);

    void SetbRad (float bRad) { m_bRad = bRad; }

    void SetXPos (float xPos) { m_xPos = xPos; }

    void SetBPos (float bPos) { m_bPos = bPos; }

    void SetLength (float length) { m_length = length; }

    void SetBackColor (const ColorAf &backColor) { m_backColor = backColor; }

    void SetSelectColor (const ColorAf &selectColor) { m_selectColor = selectColor; }

    void SetHighColor (const ColorAf &highColor) { m_highColor = highColor; }

    void SetTrackColor (const ColorAf &trackColor) { m_trackColor = trackColor; }

protected:
    
    bool m_mouseLock;

    float m_bRad;
    
    float m_xPos;
    
    float m_yPos;

    float m_bPos;

    float m_length; 

    ColorAf m_backColor;

    ColorAf m_selectColor;

    ColorAf m_highColor;

    ColorAf m_trackColor;

    sliderHandListPtr m_handlerList;

};