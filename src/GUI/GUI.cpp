#include "GUI.h"

using namespace ci;

GUI::GUI ()
{
    m_elemList = std::make_unique <ElemList> ();
    m_resizeList = std::make_unique <ResizeList> (); 
}

GUI::~GUI ()
{

}

void GUI::update (float elapsedTime, Vec2i mousePos, bool mousePressed)
{
    m_mouseOver = false;

    for (GUIElemPtr elem : *m_elemList)
    {
        elem->update (elapsedTime, mousePos, mousePressed);
        if (elem->isMouseOver ())
        {
            m_mouseOver = true;
        }
    }
}

void GUI::draw (Vec2i windowSize)
{
    gl::disableDepthRead ();

    for (GUIElemPtr elem : *m_elemList)
    {
        elem->draw ();
    }
}

void GUI::add (const GUIElemPtr &element)
{
    m_elemList->push_back (element);
}

void GUI::addResize (const ResizablePtr &resizable)
{
    m_resizeList->push_back (resizable);
}

void GUI::remove (const GUIElemPtr &element)
{
    m_elemList->remove (element);
}

void GUI::resize (float windowWidth, float windowHeight)
{
    for (ResizablePtr resizable : *m_resizeList)
    {
        resizable->resize (windowWidth, windowHeight);
    }
}

bool GUI::isMouseOver ()
{
    return m_mouseOver;
}
