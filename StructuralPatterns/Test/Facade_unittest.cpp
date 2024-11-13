#include "gtest/gtest.h"
#include "../Facade.hpp"


TEST(Facade, Operation)
{
    Subsystem1 *subsystem1 = new Subsystem1;
    Subsystem2 *subsystem2 = new Subsystem2;
    Facade *facade = new Facade(subsystem1, subsystem2);
    EXPECT_EQ(facade->Operation(), "Facade initializes subsystems:\n\
Subsystem1: Ready!\nSubsystem2: Get ready!\n\
Facade orders subsystems to perform the action:\n\
Subsystem1: Go!\nSubsystem2: Fire!\n");

}

