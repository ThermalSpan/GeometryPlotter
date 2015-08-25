#pragma once

#include "stdafx.h"

class Point;

typedef std::shared_ptr <Point> pointPtr;
typedef std::list <pointPtr> pointList;
typedef std::unique_ptr <pointList> pointListPtr;


class Point
{
public:
    Point ();

    ~Point ();

protected:
    
    float coords[3];
};