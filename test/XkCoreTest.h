#include <gtest/gtest.h>
#include "Xk.h"

TEST(XkCoreTest, testvec2)
{
    Xk::Vec2 v2;
    v2.to_s();

    std::cout<<Xk::to_s(v2)<<std::endl;
}

TEST(XkCoreTest, testmap)
{
    Xk::map<int, int> mymap;
    mymap.remove_all();
}