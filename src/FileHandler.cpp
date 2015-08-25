#include "FileHandler.h"

using namespace ci;

FileHandler::FileHandler ()
{
    m_lineList = std::make_unique <lineList> ();
    m_pointList = std::make_unique <pointList> ();
    m_planeList = std::make_unique <planeList> ();
}

void FileHandler::draw ()
{

}

void FileHandler::draw (float x, float y)
{

}

void FileHandler::update (float elapsedTime, Vec2i mouseLocation, bool mousePressed)
{

}

void FileHandler::plotDraw ()
{

}