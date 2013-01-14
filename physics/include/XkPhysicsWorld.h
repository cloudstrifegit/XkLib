#ifndef XK_PHYSICS_WORLD_H
#define XK_PHYSICS_WORLD_H

#include "XkStable.h"
#include "XkSingleton.h"

#if XkPhysicsLib == XkPhysicsLibHavok
#include "XkPhysicsWorld_Havok.h"
#elif XkPhysicsLib == XkPhysicsLibPhysX
#include "XkPhysicsWorld_PhysX.h"
#endif

namespace Xk
{

class XkPublicClass XkPhysicsWorld : public XkPhysicsWorldImpl
{
public:
    XkPhysicsWorld();
    ~XkPhysicsWorld();

public:
    bool initialize();
    void uninitialize();
    bool step(Xk::Real fTime);
};

typedef Xk::Singleton<XkPhysicsWorld> World;

} //namespace Xk

#endif