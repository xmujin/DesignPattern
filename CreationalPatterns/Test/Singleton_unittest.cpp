#include "gtest/gtest.h"
#include "../Singleton.hpp"

class SingletonTest : public testing::Test
{
protected:
    SingletonTest()
    {
        ins = Singleton::GetInstance("sb");
    }

    // ~SingletonTest() override = default;
    Singleton* ins;

};




TEST_F(SingletonTest, GetInstanceWorks)
{

    Singleton* other = Singleton::GetInstance("sdfsdf");
    ASSERT_NE(other, nullptr);
    EXPECT_EQ(ins, other);
}

TEST_F(SingletonTest, valueWorks)
{
    EXPECT_EQ(ins->value(), "sb");
}

