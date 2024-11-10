#include "gtest/gtest.h"
#include "../Prototype.hpp"
#include <memory>

TEST(ConcretePrototype1, Clone)
{
    ConcretePrototype1 a(12.0f);
    auto b = a.Clone();
    EXPECT_FLOAT_EQ(a.value(), b->value());
}






