#include "GUI.h"

class GUISlideMenu : public GUIElement
    {
    public:
        GUISlideMenu ();

        ~GUISlideMenu ();
        
        void draw ();

        void draw (float x, float y);

        void update (float elapsedTime, Vec2i mouseLocation);

        float getHeight ();

        void add (const GUIElemPtr &element);

        void remove (const GUIElemPtr &element);

    protected:

        void checkMouse ();

        ElemListPtr m_elemList;

        // Is the mouse over the menu?
        bool m_mouseOver;

        // Is the menu fully extended?
        bool m_extended;

        // Describes the state of extension, strictly [0,1]
        float m_state;

        // Actual position of menu, 0 when exteneded
        float m_translate;

        // Adjusts speed of extension
        float m_speedFactor;

        // How far does the menu tab extend?
        float m_width;

    };