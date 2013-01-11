#include <gtest/gtest.h>
#include "Xk.h"


TEST(XkCoreTest, testvec2)
{
    Xk::Vec2 v2;
    v2.to_s();

    
}

TEST(XkCoreTest, testmap)
{
    std::cout<<Xk::GC::type2id<Xk::Vec2>::type_name()<<std::endl;
    Xk::Ray ray;

}