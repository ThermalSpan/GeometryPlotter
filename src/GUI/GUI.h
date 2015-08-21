#pragma once

#include <list>
#include <memory>
#include <math.h>

#include "cinder/Vector.h"
#include "cinder/Cinder.h"
#include "cinder/Color.h"
#include "cinder/Rect.h"
#include "cinder/gl/gl.h"


#include "Resizable.h"
#include "GUIElement.h"
#include "GUIBoxPanel.h"
#include "GUIElement.h"
#include "GUIPushButton.h"
#include "GUIPushHandler.h"
#include "GUIRadioGroup.h"
#include "GUISlideMenu.h"
#include "GUITabMenu.h"
#include "GUISliderHandler.h"
#include "GUISlider.h"
#include "GUIText.h"
#include "GUIToggleButton.h"
#include "GUIToggleHandler.h"

using namespace ci;

class GUI
    {
    public:
        GUI ();

        ~GUI ();
    
        void update (float elapsedTime, Vec2i mousePos, bool mousePressed);

        void draw (Vec2i windowSize);

        void add (const GUIElemPtr &element);

        void addResize (const ResizablePtr &resizable);

        void remove (const GUIElemPtr &element);

        void resize (float windowWidth, float windowHeight);

        bool isMouseOver ();

    protected:

       bool m_mouseOver;

       ElemListPtr m_elemList;

       ResizeListPtr m_resizeList;
    };