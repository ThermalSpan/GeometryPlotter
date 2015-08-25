#include "GUI.h"

using namespace ci;

GUISlideMenu::GUISlideMenu ()
{
    m_mouseOver = false;
    m_state = 0.0f;
    m_width = 250.0f;
    m_translate = -m_width;
    m_height = 500;
    m_speedFactor = 8.0f;
    m_xOffset = 50;
    m_yOffset = 100.0f;
    m_tabHeight = 100;
    m_tabWidth = 50;
    m_tabYOffset = 50;
    
    m_elemList = std::make_unique <ElemList> ();
    
    m_backColor = ColorAf (0.5f, 0.0f, 0.5f, 0.3f);
    m_highColor = ColorAf (0.0f, 0.0f, 0.0f, 1.0f);
    
    Vec2f p1 (0.0f, 0.0f);
    Vec2f p2 (m_width, m_height);
    m_mainRec = Rectf (p1, p2);
    
    p1.set (m_width, m_tabYOffset);
    p2.set (m_width + m_tabWidth, m_tabYOffset + m_tabHeight);
    m_tabRec = Rectf (p1, p2);
    
}

GUISlideMenu::~GUISlideMenu ()
{

}

void GUISlideMenu::draw ()
{
    draw (0.0, 0.0);
}

void GUISlideMenu::draw (float tranX, float tranY)
{
    float curY = m_yOffset;
    
    
    gl::color (m_backColor);
    gl::drawSolidRect (m_tabRec, false);
    if (m_state > 0) gl::drawSolidRect (m_mainRec, false);
    
    gl::color (m_highColor);
    gl::lineWidth (3);
    gl::drawStrokedRoundedRect (m_tabRec, 1, 10);
    if (m_state > 0)gl::drawStrokedRoundedRect (m_mainRec, 1, 10);

    if (m_state > 0)
    {
        for (GUIElemPtr elem: *m_elemList)
        {
            elem->draw (m_translate + m_xOffset, curY);
            curY += elem->GetHeight();
        }
    }
    
}

void GUISlideMenu::update (float elapsedTime, Vec2i mousePos, bool mousePressed)
{
    m_mouseOver = m_mainRec.contains (mousePos) || m_tabRec.contains (mousePos);
    float dif = elapsedTime * m_speedFactor * sinf (m_state * (float)M_PI);
    
    // Mouse over, not fully extended
    if (m_mouseOver && m_state < 1.0f)
    {
        m_state += fmax (dif, 0.01f);
    }
    
    // Mouse isn't over, not fully retracted
    else if (!m_mouseOver && m_state > 0)
    {
        m_state -= fmax (dif, 0.01f);
    }

    // Constrain state to [0,1]
    m_state = constrain (m_state, 0.0f, 1.0f);

    m_translate = -m_width + m_state * m_width;
    if (m_translate == 0)
    {
        for (GUIElemPtr elem : *m_elemList)
        {
            elem->update (elapsedTime, mousePos, mousePressed);
        }
    }
    
   // update the rectangles
    float x1, x2, y1, y2;
    
    x1 = m_translate;
    x2 = m_translate + m_width;
    y1 = 0.0f;
    y2 = m_height;
    m_mainRec.set (x1, y1, x2, y2);
    
    x1 = m_translate + m_width;
    x2 = m_translate + m_width + m_tabWidth;
    y1 = m_tabYOffset;
    y2 = m_tabYOffset + m_tabHeight;
    m_tabRec.set (x1, y1, x2, y2);


    for (GUIElemPtr elem : *m_elemList) {
        elem->update (elapsedTime, mousePos, mousePressed);
    }
}

void GUISlideMenu::add (const GUIElemPtr &element)
{
    m_elemList->push_back (element);
}

void GUISlideMenu::remove (const GUIElemPtr &element)
{
    m_elemList->remove (element);
}

void GUISlideMenu::resize (float windowWidth, float windowHeight)
{
    m_height = windowHeight;
}