#include "GeometryPlotterApp.h"
#include "Resources.h"


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

    Vec2f p1 (0.0f, 0.0f);
    Vec2f p2 (250.0f, 250.0f);
    cinder::Rectf rec (p1, p2);
    gl::color (ColorAf (1.0f, 0.1f, 0.1f, 0.2f));
    gl::drawSolidRect (rec, false);
    
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
