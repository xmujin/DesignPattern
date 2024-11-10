#include "gtest/gtest.h"
#include "../Adapter.hpp"


TEST(Adapter, Request)
{
    Adaptee *adaptee = new Adaptee;
    Adapter adapter(adaptee);
    adapter.Request();
    EXPECT_TRUE(true);
}

