#pragma once 

#include "GUI.h"

using namespace ci;

class GUIElement;

typedef std::shared_ptr <GUIElement> GUIElemPtr;
typedef std::shared_ptr <const GUIElement> GUIElemCPtr;

typedef std::list <GUIElemPtr> ElemList;
typedef std::unique_ptr <ElemList> ElemListPtr;


class GUIElement
    {
    public:
        virtual void draw () = 0;
        virtual void draw (float x, float y) = 0;
        virtual void update (float elapsedTime, Vec2i mouseLocation, bool mousePressed) = 0;

        bool isMouseOver () { return m_mouseOver; }
        float GetWidth () { return m_width; };
        float GetHeight() { return m_height; }

        void SetWidth (float width) { m_width = width; }
        
        void SetHeight (float height) { m_height = height;  }
        
    protected:
        bool m_mouseOver;
        float m_height;
        float m_width;
    };