#include "GeometryPlotterApp.h"
#include "Resources.h"

#include <iostream>

void GeometryPlotterApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 800, 600 );
    settings->setFrameRate(30.0f);
}

void GeometryPlotterApp::setup()
{
    CameraPersp cam;
    cam.setEyePoint (Vec3f (5.0f, 10.0f, 10.0f));
    cam.setCenterOfInterestPoint (Vec3f (0.0f, 2.5f, 0.0f));
    cam.setPerspective (60.0f, getWindowAspectRatio (), 1.0f, 1000.0f);
    m_mayaCam.setCurrentCam (cam);

    buildGUI ();
}

void GeometryPlotterApp::update()
{
    double curTime = app::getElapsedSeconds();
    float elapsedTime = (float)(curTime - m_lastUpdateTime);
    m_lastUpdateTime = curTime;
        
    m_gui.update (elapsedTime, m_mousePos, m_mousePressed);
}

void GeometryPlotterApp::draw()
{
	// clear out the window with black
	gl::clear( Color(0.5f, 0.5f, 0.5f) ); 

    gl::enableDepthRead ();

    // Setup the camera
    gl::pushMatrices ();
    gl::setMatricesWindowPersp (getWindowWidth (), getWindowHeight ());
    gl::setMatrices (m_mayaCam.getCamera ());

    // Enable depth buffer
    gl::enableDepthRead ();
    gl::enableDepthWrite ();

    gl::enableAlphaBlending ();

    float size = 100;
    float step = 1.0;
    gl::color( ColorAf(0.2f, 0.2f, 0.2f, 0.5f) );
	for(float i=-size;i<=size;i+=step) 
    {
		gl::drawLine( Vec3f(i, 0.0f, -size), Vec3f(i, 0.0f, size) );
		gl::drawLine( Vec3f(-size, 0.0f, i), Vec3f(size, 0.0f, i) );
    }

    gl::popMatrices ();


    m_gui.draw (getWindowSize ());

    
}

void GeometryPlotterApp::mouseMove (MouseEvent event)
{
    m_mousePos = event.getPos ();
}

void GeometryPlotterApp::mouseDown (MouseEvent event)
{
    if (event.isLeftDown ())
    {
        m_mousePressed = true;
    }

    std::cout << "Mouse Down" << std::endl;
    
    m_mayaCam.mouseDown (event.getPos ());
}

void GeometryPlotterApp::mouseUp (MouseEvent event)
{
    m_mousePressed = false;
    std::cout << "Mouse Up" << std::endl;
}


void GeometryPlotterApp::mouseDrag (MouseEvent event)
{
    m_mousePos = event.getPos ();

    if (!m_gui.isMouseOver ())
    {
        m_mayaCam.mouseDrag (event.getPos (), event.isLeftDown (), event.isMiddleDown (), event.isRightDown ());
    }
}

void GeometryPlotterApp::resize ()
{
    // Adjust the camera
    CameraPersp cam = m_mayaCam.getCamera ();
    cam.setAspectRatio (getWindowAspectRatio ());
    m_mayaCam.setCurrentCam (cam);

    m_gui.resize ((float)getWindowWidth (), (float)getWindowHeight ());
}

void GeometryPlotterApp::buildGUI ()
{
    tabMenuPtr menu = std::make_shared <GUITabMenu> (3, 50.0f, 10.0f, 20.0f, 50.0f);
    ColorAf bc = ColorAf (0.5f, 0.0f, 0.5f, 0.3f);
    ColorAf bc2 = ColorAf (1.0f, 1.0f, 1.0f, 0.3f);
    ColorAf hc = ColorAf (0.0f, 0.0f, 0.0f, 1.0f);

    for (int i = 0; i < 3; i++)
    {
        menu->SetBackColor (bc, i);
        menu->SetHighColor (hc, i);
    }

    menu->SetBackColor (bc2, 2);

    sliderPtr s1 = std::make_shared <GUISlider> ();
    s1->SetXPos (30);
    s1->SetBPos(0.0f);
    s1->SetLength (200);
    s1->SetbRad (15);
    s1->SetHeight (50.0f);

    menu->add (s1, 0);

    m_gui.add (menu);
    m_gui.addResize (menu);
}

CINDER_APP_NATIVE( GeometryPlotterApp, RendererGl )
