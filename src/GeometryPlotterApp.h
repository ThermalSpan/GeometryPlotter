#include "stdafx.h"

using namespace ci;
using namespace ci::app;

class GeometryPlotterApp : public AppNative
{
public:
    typedef AppNative base;

    void prepareSettings (Settings *settings );

    void setup ();

    void update ();

    void draw ();

    void mouseMove (MouseEvent event);

    void mouseDown (MouseEvent event);

    void mouseUp (MouseEvent event);

    void mouseDrag (MouseEvent event);

    void resize ();

    void buildGUI ();

protected:
    bool m_mousePressed;

    // For keeping track of elapsed time;
    double m_lastUpdateTime;
    
    // The Fancy Camera 
    MayaCamUI m_mayaCam;

    // Mouse Position
    Vec2i m_mousePos;

    GUI m_gui;

};