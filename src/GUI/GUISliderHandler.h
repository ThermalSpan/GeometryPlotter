#include "GUI.h"

class GUISliderHandler;

typedef std::shared_ptr <GUISliderHandler> sliderHandPtr;
typedef std::list <sliderHandPtr> sliderHandList;
typedef std::unique_ptr <sliderHandList> sliderHandListPtr;

class GUISliderHandler
    {
    public:
        virtual void update (float t);
    };