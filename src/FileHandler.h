#pragma once

#include "stdafx.h"

#include "point.h"
#include "PLine.h"
#include "Plane.h"

#define FILE_NAME_SIZE 300

class FileHandler;

typedef std::shared_ptr <FileHandler> fileHandPtr;
typedef std::list <fileHandPtr> fileHandList;
typedef std::unique_ptr <fileHandList> fileHandListPtr;

class FileHandler : public GUIElement
{
public:

    FileHandler ();

    ~FileHandler ();

    void draw ();
    
    void draw (float x, float y);
    
    void update (float elapsedTime, Vec2i mouseLocation, bool mousePressed);

    void plotDraw ();

    void loadFile ();

protected:

    char m_fileName [FILE_NAME_SIZE];

    lineListPtr m_lineList; 

    pointListPtr m_pointList;

    planeListPtr m_planeList;
};