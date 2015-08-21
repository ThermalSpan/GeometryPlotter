#include "GeometryPlotterApp.h"
#include "Resources.h"

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
    

}

void GeometryPlotterApp::update()
{
        float curTime = app::getElapsedSeconds();
        float elapsedTime = curTime - m_lastUpdateTime;
        m_lastUpdateTime = curTime;
        
        menu.update (elapsedTime, m_mousePos);
}

void GeometryPlotterApp::draw()
    {
	// clear out the window with black
	gl::clear( Color(0.5f, 0.5f, 0.5f) ); 

    // Setup the camera
    gl::pushMatrices ();
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

    menu.draw();
    
    }

void GeometryPlotterApp::mouseMove (MouseEvent event)
{
    m_mousePos = event.getPos ();
}

void GeometryPlotterApp::mouseDown (MouseEvent event)
{
    m_mayaCam.mouseDown (event.getPos ());
}


void GeometryPlotterApp::mouseDrag (MouseEvent event)
{
    m_mousePos = event.getPos ();
    m_mayaCam.mouseDrag (event.getPos (), event.isLeftDown (), event.isMiddleDown (), event.isRightDown ());
}

void GeometryPlotterApp::resize ()
{
    // Adjust the camera
    CameraPersp cam = m_mayaCam.getCamera ();
    cam.setAspectRatio (getWindowAspectRatio ());
    m_mayaCam.setCurrentCam (cam);
}

CINDER_APP_NATIVE( GeometryPlotterApp, RendererGl )
