#include "GUI.h"

using namespace ci;

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

    gl::lineWidth (10);
    gl::color (m_trackColor);
    Vec2f p1 (x + m_xPos, y + yGap);
    Vec2f p2 (x + m_xPos + m_length, y + yGap);
    gl::drawLine (p1, p2);

    if (m_mouseLock)
    {
        gl::color (m_selectColor);
    }
    else
    {
        gl::color (m_backColor);
    }
    p1.set (x + m_bPos + m_xPos, y + yGap);
    gl::drawSolidCircle (p1, m_bRad);

    gl::lineWidth (2);
    gl::color (m_highColor);
    gl::drawStrokedCircle (p1, m_bRad);
}

void GUISlider::update (float elapsedTime, Vec2i mouseLocation, bool mousePressed)
{
    float xd = mouseLocation[0] - (m_xPos + m_bRad);
    float yd = mouseLocation[1] - (m_width / 2);
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