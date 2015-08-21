#include "GUISlideMenu.h"

GUISlideMenu::GUISlideMenu ()
    {

    m_speedFactor = 8;
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

    }

void GUISlideMenu::update (float elapsedTime)
    {
    checkMouse ();
    float dif = elapsedTime * m_speedFactor * sin (m_state * M_PI);
    
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
    cinder::constrain (m_state, 0.0f, 1.0f);

    m_translate = -m_width + m_state * m_width;
    if (m_translate == 0)
        {
        for (GUIElemPtr elem : *m_elemList)
            {
            elem->update (elapsedTime);
            }
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