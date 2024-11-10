#include "gtest/gtest.h"
#include "../Builder.hpp"
#include <memory>

TEST(Computer, show)
{
    Computer a;
    a.cpu = "64";
    a.gpu = "12GB";
    a.ram = "16GB";

    EXPECT_EQ(a.show(), "64_12GB_16GB");


    Computer b;
    b.cpu = "32";
    b.gpu = "1GB";
    b.ram = "16GB";
    EXPECT_EQ(b.show(), "32_1GB_16GB");

}


TEST(GamingComputerBuilder, Reset)
{
    GamingComputerBuilder sb;
    std::unique_ptr<Computer> a = sb.GetComputer();
    std::unique_ptr<Computer> b = sb.GetComputer();
    EXPECT_EQ(b, nullptr);
    sb.Reset();
    b = sb.GetComputer();
    EXPECT_NE(b, nullptr);
}


TEST(Director, BuildGamingComputer)
{
    GamingComputerBuilder sb;
    Director d;
    d.SetBuilder(&sb);
    d.BuildGamingComputer();

    EXPECT_EQ(sb.GetComputer()->show(), "64_12GB_16GB");
}










