#pragma once

#include "GUI.h"


class GUITabMenu;

typedef std::shared_ptr <GUITabMenu> tabMenuPtr;

typedef std::vector <slideMenuPtr> menuVec;
typedef std::unique_ptr <menuVec> menuVecPtr;

class GUITabMenu: public GUIElement, public Resizable
{
public:

    GUITabMenu (int menuCount, float yOffset, float tabGap, float tabWidth, float tabHeight);

    ~GUITabMenu ();

    void draw ();
    
    void draw (float x, float y);

    void update (float elapsedTime, Vec2i mouseLocation, bool mousePressed);

    void add (const GUIElemPtr &element, int menuId);

    void resize (float windowWidth, float windowHeight);

    void SetBackColor (const ColorAf &backColor, int menuId);

    void SetHighColor (const ColorAf &highColor, int menuId);
    

protected:

    int m_menuCount;

    float m_yOffset;

    float m_tabGab;

    menuVecPtr m_menuVec;
};