#pragma once

#include <list>
#include <memory>
#include <math.h>

#include "cinder/Vector.h"
#include "cinder/Cinder.h"
#include "cinder/Color.h"

#include "GUIElement.h"
#include "GUIBoxPanel.h"
#include "GUIElement.h"
#include "GUIPushButton.h"
#include "GUIPushHandler.h"
#include "GUIRadioGroup.h"
#include "GUISlideMenu.h"
#include "GUISlider.h"
#include "GUISliderHandler.h"
#include "GUIText.h"
#include "GUIToggleButton.h"
#include "GUIToggleHandler.h"

using namespace ci;

class GUI
    {
    public:
        GUI ();

        ~GUI ();
    
        void update (float elapsedTime);

        void draw ();

        void add (const GUIElemPtr &element);

        void remove (const GUIElemPtr &element);

    protected:
       ElemListPtr m_elemList;
    };