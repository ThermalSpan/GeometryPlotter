#include "PLine.h"

PLine::PLine ()
{
    m_pointList = std::make_unique <pointList> ();
}

PLine::~PLine ()
{

}

void PLine::addPoint (const pointPtr &point)
{
    m_pointList->push_back (point);
}