#include "gtest/gtest.h"
#include "../FactoryMethod.hpp"


TEST(ConcreteProduct1, Operation)
{
    ConcreteProduct1 a;
    EXPECT_EQ(a.Operation(), "{ConcreteProduct1}");
}


TEST(ConcreteCreator1, SomeOperation)
{
    Creator* creator = new ConcreteCreator1();
    EXPECT_EQ(creator->SomeOperation(), "{ConcreteProduct1}");
}

