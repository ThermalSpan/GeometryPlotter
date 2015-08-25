#include "stdafx.h"
#include "Point.h"

class Plane;

typedef std::shared_ptr <Plane> planePtr;
typedef std::list <planePtr> planeList;
typedef std::unique_ptr <planeList> planeListPtr;

class Plane
{
public:

    Plane ();

    ~Plane ();

protected:

    Point m_origin;

    Point m_norm;
};