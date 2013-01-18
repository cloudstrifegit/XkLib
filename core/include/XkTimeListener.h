#ifndef XK_TIME_LISTENER_H
#define XK_TIME_LISTENER_H

#include "XkStable.h"

namespace Xk
{

class XkTimeListener
{
public:
    virtual bool advance(float deltaTime, const Enums::Priority&, const Enums::SceneFunction&) = 0;
};

}

#endif