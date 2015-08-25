#include "GUI.h"



GUISlider::GUISlider ()
{
    m_mouseLock = false;

    m_backColor = ColorAf (0.5f, 0.5f, 0.05f, 1.0f);
    m_selectColor = ColorAf (0.8f, 0.8f, 0.08f, 1.0f);
    m_highColor = ColorAf (1.0f, 1.0f, 1.0f, 1.0f);
    m_trackColor = ColorAf (0.8f, 0.8f, 0.08f, 1.0f);

    m_handlerList = std::make_unique <sliderHandList> ();
}

GUISlider::~GUISlider ()
{

}

void GUISlider::draw ()
{
    draw (0.0, 0.0);
}

void GUISlider::draw (float x, float y)
{
    float yGap = m_height / 2;

    m_xPos = x;
    m_yPos = y;
    
    gl::lineWidth (10);
    gl::color (m_trackColor);
    Vec2f p1 (m_xPos, m_yPos + yGap);
    Vec2f p2 (m_xPos + m_length, m_yPos + yGap);
    gl::drawLine (p1, p2);

    if (m_mouseLock)
    {
        gl::color (m_selectColor);
    }
    else
    {
        gl::color (m_backColor);
    }
    float xpos = m_bPos + m_xPos;
    float ypos = m_yPos + yGap;
    p1.set (xpos, ypos);
    gl::drawSolidCircle (p1, m_bRad);
    
    gl::lineWidth (2);
    gl::color (m_highColor);
    gl::drawStrokedCircle (p1, m_bRad);
}

void GUISlider::update (float elapsedTime, Vec2i mouseLocation, bool mousePressed)
{
    float xd = mouseLocation[0] - (m_xPos + m_bRad);
    float yd = mouseLocation[1] - (m_yPos + m_width / 2);
    float mouseDist = sqrtf (xd*xd + yd*yd);

    if (m_mouseLock && mousePressed)
    {
        m_bPos = mouseLocation[0] - m_xPos;
        m_bPos = constrain (m_bPos, 0.0f, m_length);
        float t = m_bPos / m_length;
        for (sliderHandPtr handler : *m_handlerList)
        {
            handler->update (t);
        }
    }
    else if (m_mouseLock && !mousePressed)
    {
        m_mouseLock = false;
    }
    else if (mousePressed && mouseDist <= m_bRad)
    {
        m_mouseLock = true;
    }
}

void GUISlider::addHandler (sliderHandPtr &handler)
{
    m_handlerList->push_back (handler);
}