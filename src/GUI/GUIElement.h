#include "GUI.h"

class GUIElement;

typedef std::shared_ptr <GUIElement> GUIElemPtr;
typedef std::shared_ptr <const GUIElement> GUIElemCPtr;

typedef std::list <GUIElemPtr> ElemList;
typedef std::unique_ptr <ElemList> ElemListPtr;


class GUIElement
    {
    public:
        virtual void draw () = 0;
        virtual void draw (float x, float y) = 0;
        virtual void update (float elapsedTime, Vec2i mouseLocation) = 0;
        virtual float getHeight () = 0;
    };