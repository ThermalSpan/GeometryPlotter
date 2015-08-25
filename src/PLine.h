#pragma once

#include "stdafx.h"
#include "Point.h"

class PLine;

typedef std::shared_ptr <PLine> linePtr;
typedef std::list <linePtr> lineList;
typedef std::unique_ptr <lineList> lineListPtr;

class PLine
{
public: 
    PLine ();

    ~PLine ();

    void addPoint (const pointPtr &point);

protected:

    pointListPtr m_pointList;

};