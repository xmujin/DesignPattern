#include "gtest/gtest.h"
#include "../Bridge.hpp"


TEST(ExtendedAbstraction, Operation)
{
    Implementation* implementation = new ConcreteImplementationA;
    Abstraction* abstraction = new Abstraction(implementation);
    EXPECT_EQ(abstraction->Operation(), "Abstraction:ConcreteImplementationA");
    implementation = new ConcreteImplementationB;
    abstraction = new ExtendedAbstraction(implementation);
    EXPECT_EQ(abstraction->Operation(), "ExtendedAbstraction:ConcreteImplementationB");
    EXPECT_TRUE(true);
}

