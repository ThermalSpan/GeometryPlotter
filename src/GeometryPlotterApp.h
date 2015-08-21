#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/MayaCamUI.h"

#include "GUI.h"

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

    void mouseDrag (MouseEvent event);

    void resize ();

protected:
    // For keeping track of elapsed time;
    float m_lastUpdateTime;
    
    // The Fancy Camera 
    MayaCamUI m_mayaCam;

    // Mouse Position
    Vec2i m_mousePos;
    
    GUISlideMenu menu;
    
};