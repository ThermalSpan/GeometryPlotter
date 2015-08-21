#pragma once

#include "GUI.h"

using namespace ci;

class GUISlideMenu : public GUIElement
    {
    public:
        GUISlideMenu ();

        ~GUISlideMenu ();
        
        void draw ();

        void draw (float x, float y);

        void update (float elapsedTime, Vec2i mouseLocation);

        void add (const GUIElemPtr &element);

        void remove (const GUIElemPtr &element);
        
        void SetBackColor (const ColorAf backColor) { m_backColor = backColor; }
        
        void SetYOffset (float yOffset) { m_yOffset = yOffset; }
            
        void SetWidth (float width) { m_width = width; }

    protected:

        // Is the mouse over the menu?
        bool m_mouseOver;

        // Describes the state of extension, strictly [0,1]
        float m_state;

        // Actual position of menu, 0 when exteneded
        float m_translate;

        // Adjusts speed of extension
        float m_speedFactor;
        
        // How far down is the first menu item?
        float m_yOffset;
        
        float m_tabHeight;
        
        float m_tabWidth;
        
        float m_tabYOffset;
        
        // List of sub elements
        ElemListPtr m_elemList;
        
        // Background color for main rectangle
        ColorAf m_backColor;
        
        // Rectangle for main menu
        Rectf m_mainRec;
        
        //Rectangle for menu tab
        Rectf m_tabRec;

    };