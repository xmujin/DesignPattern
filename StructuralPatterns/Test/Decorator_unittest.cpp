#include "gtest/gtest.h"
#include "../Decorator.hpp"


TEST(Component, Operation)
{
    Component* simple = new ConcreteComponent;
    EXPECT_EQ(simple->Operation(), "ConcreteComponent");

    Component* decorator1 = new ConcreteDecoratorA(simple);
    Component* decorator2 = new ConcreteDecoratorB(decorator1);

    EXPECT_EQ(decorator2->Operation(), "ConcreteDecoratorB(ConcreteDecoratorA(ConcreteComponent))");
}

