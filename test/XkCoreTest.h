#include <gtest/gtest.h>
#include "Xk.h"

TEST(XkCoreTest, testvec2)
{
    Xk::Vec2 v2;
    v2.set(1, 2);
    v2.to_s();
    Xk::Vec2 vRet = v2.mid(v2);
}

TEST(XkCoreTest, testvec3)
{
    Xk::Vec3 v3;
    v3.set(1, 2, 3);
    v3.to_s();
    std::cout<<v3.to_s()<<std::endl;

    xk_fatal("test");
}

TEST(XkCoreTest, testAllocator)
{
    void* p = Xk::MallocAllocator::allocateBytes(100);
    ASSERT_NE(p, (void*)NULL);
    Xk::MallocAllocator::deallocateBytes(p);
}

TEST(XkCoreTest, testFormat)
{
    std::string strFormat;
    strFormat = Xk::format( "100 %d", 100);
    std::cout<<strFormat<<std::endl;
}

TEST(XkCoreTest, testLog)
{
    std::string strMsg = "test";

    xk_fatal("fatal");
    xk_fatal_f1("tes %d", 100);
    xk_fatal_f2("test %d %s", 100, strMsg);
    xk_fatal_f3("%d, %d, %s", 100, 101, strMsg);
    xk_fatal_f4("%d, %d, %s %s", 100, 101, strMsg, strMsg);

    xk_critical("critical");
    xk_critical_f1("%d", 100);
    xk_critical_f2("%d %s", 100, strMsg);
    xk_critical_f3("%d %d %d", 100, 101, 102);
    xk_critical_f4("%d %d %d %s", 100, 101, 102, strMsg);

    xk_error("error");
    xk_error_f1("%d", 100);
    xk_error_f2("%d %s", 100, strMsg);
    xk_error_f3("%d %s %d", 100, strMsg, 101);
    xk_error_f4("%d %d %d %s", 100, 101, 102, strMsg);
}