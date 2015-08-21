#include "GUI.h"

using namespace ci;

GUI::GUI ()
    {
    m_elemList = std::make_unique <ElemList> ();
    }

GUI::~GUI ()
    {

    }

void GUI::update (float elapsedTime, Vec2i mousePos)
    {
    for (GUIElemPtr elem : *m_elemList)
        {
        elem->update (elapsedTime, mousePos);
        }
    }

void GUI::draw ()
    {
    for (GUIElemPtr elem : *m_elemList)
        {
        elem->draw ();
        }
    }

void GUI::add (const GUIElemPtr &element)
    {
    m_elemList->push_back (element);
    }

void GUI::remove (const GUIElemPtr &element)
    {
    m_elemList->remove (element);
    }
