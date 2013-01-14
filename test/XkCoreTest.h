#include <gtest/gtest.h>
#include "Xk.h"

TEST(XkCoreTest, testvec2)
{
    Xk::Vec2 v2;
    v2.set(1, 2);

    Xk::Vec2 vRet = v2.mid(v2);
}

TEST(XkCoreTest, testvec3)
{
    Xk::Vec3 v3;
    v3.set(1, 2, 3);
}

TEST(XkCoreTest, testAllocator)
{
    void* p = Xk::MallocAllocator::allocateBytes(100);
    ASSERT_NE(p, (void*)NULL);
    Xk::MallocAllocator::deallocateBytes(p);
}