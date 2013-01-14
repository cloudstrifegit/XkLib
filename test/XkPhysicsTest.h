#include <gtest/gtest.h>
#include "XkPhysicsWorld.h"

TEST(XkPhysicsTest, testWorld)
{
    Xk::World::instance().initialize();
    Xk::World::instance().uninitialize();
}