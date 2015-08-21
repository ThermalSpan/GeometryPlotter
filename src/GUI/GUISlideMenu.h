#pragma once

#include "GUI.h"

using namespace ci;

class GUISlideMenu;

typedef std::shared_ptr <GUISlideMenu> slideMenuPtr;

class GUISlideMenu : public GUIElement, public Resizable
    {
    public:
        GUISlideMenu ();

        ~GUISlideMenu ();
        
        void draw ();

        void draw (float x, float y);

        void update (float elapsedTime, Vec2i mouseLocation, bool mousePressed);

        void add (const GUIElemPtr &element);

        void remove (const GUIElemPtr &element);

        void resize (float windowWidth, float windowHeight);
        
        void SetYOffset (float yOffset) { m_yOffset = yOffset; }
            
        void SetWidth (float width) { m_width = width; }

        void SetHeight (float height) { m_height = height; }

        void SetTabHeight (float tabHeight) { m_tabHeight = tabHeight; }

        void SetTabWidth (float tabWidth) { m_tabWidth = tabWidth;  }

        void SetTabOffset (float yOffset) { m_tabYOffset = yOffset;  }

        void SetBackColor (const ColorAf &backColor) { m_backColor = backColor; }

        void SetHighColor (const ColorAf &highColor) { m_highColor = highColor; }

        bool isMouseOver () { return m_mouseOver;  }

    protected:

        // Describes the state of extension, strictly [0,1]
        float m_state;

        // Actual position of menu, 0 when exteneded
        float m_translate;

        // Adjusts speed of extension
        float m_speedFactor;
        
        // How far down is the first menu item?
        float m_yOffset;
        
        // How tall is the tab?
        float m_tabHeight;
        
        // How wide is the tab?
        float m_tabWidth;
        
        // How far from the top of the window is the top of the tab?
        float m_tabYOffset;
        
        // List of sub elements
        ElemListPtr m_elemList;
        
        // Background color for main rectangle
        ColorAf m_backColor;

        // Highlight color for rectangle edges
        ColorAf m_highColor;

        // Rectangle for main menu
        Rectf m_mainRec;
        
        //Rectangle for menu tab
        Rectf m_tabRec;

    };