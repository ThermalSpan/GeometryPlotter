#include "GUI.h"

GUITabMenu::GUITabMenu (int menuCount, float yOffset, float tabGap, float tabWidth, float tabHeight)
{
    m_menuCount = menuCount;

    m_menuVec = std::make_unique <menuVec> (m_menuCount);
    for (int i = 0; i < m_menuCount; i++)
    {
        float offset = yOffset + (float)(i) * (tabHeight + tabGap);

        m_menuVec->at (i) = std::make_shared <GUISlideMenu> ();
        m_menuVec->at (i)->SetTabWidth (tabWidth);
        m_menuVec->at (i)->SetTabHeight (tabHeight);
        m_menuVec->at (i)->SetTabOffset (offset);
    }
}

GUITabMenu::~GUITabMenu ()
{

}

void GUITabMenu::draw ()
{   
    draw (0.0f, 0.0f);
}

void GUITabMenu::draw (float x, float y)
{
    bool drawAll = true;
    slideMenuPtr menuToDraw;

    for (slideMenuPtr menu : *m_menuVec)
    {
        if (menu->isMouseOver ())
        {
            menuToDraw = menu;
            drawAll = false;
        }
    }

    if (drawAll)
    {
        for (slideMenuPtr menu : *m_menuVec)
        {
            menu->draw (x, y);
        }
    }
    else
    {
        menuToDraw->draw (x, y);
    }
}

void GUITabMenu::update (float elapsedTime, Vec2i mouseLocation, bool mousePressed)
{
    m_mouseOver = false;

    for (slideMenuPtr menu : *m_menuVec)
    {
        menu->update (elapsedTime, mouseLocation, mousePressed);
        if (menu->isMouseOver ()) {
            m_mouseOver = true;
            break;
        }
    }
}

void GUITabMenu::add (const GUIElemPtr &element, int menuId)
{
    m_menuVec->at (menuId)->add (element);
}

void GUITabMenu::resize (float windowWidth, float windowHeight)
{
    for (slideMenuPtr menu : *m_menuVec)
    {
        menu->resize (windowWidth, windowHeight);
    }
}

void GUITabMenu::SetBackColor (const ColorAf &backColor, int menuId)
{
    m_menuVec->at (menuId)->SetBackColor (backColor);
}

void GUITabMenu::SetHighColor (const ColorAf &highColor, int menuId)
{
    m_menuVec->at (menuId)->SetHighColor (highColor);
}