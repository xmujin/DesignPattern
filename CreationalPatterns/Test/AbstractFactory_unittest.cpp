#include "gtest/gtest.h"
#include "../AbstractFactory.hpp"


TEST(ConcreteProductA1, UsefulFunctionA)
{
    ConcreteProductA1 a;
    EXPECT_EQ(a.UsefulFunctionA(), "ConcreteProductA1");
}


TEST(ConcreteFactory1, CreateProductA)
{
    AbstractFactory* a = new ConcreteFactory1();
    EXPECT_EQ(a->CreateProductA()->UsefulFunctionA(), "ConcreteProductA1");
}

