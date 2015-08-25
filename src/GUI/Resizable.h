#pragma once

#include "GUI.h"

class Resizable;

typedef std::shared_ptr <Resizable> ResizablePtr;
typedef std::shared_ptr <const Resizable> ResizableCPtr;

typedef std::list <ResizablePtr> ResizeList;
typedef std::unique_ptr <ResizeList> ResizeListPtr;

class Resizable
{
public:
    virtual void resize (float windowWidth, float windowHeight) = 0;
};