#include "gtest/gtest.h"
#include "../Composite.hpp"


TEST(ExtendedAbstraction, Operation)
{
    Component *simple = new Leaf;
    EXPECT_EQ(simple->Operation(), "Leaf");


    Component *tree = new Composite;
    Component *branch1 = new Composite;
    Component *leaf_1 = new Leaf;
    Component *leaf_2 = new Leaf;
    Component *leaf_3 = new Leaf;
    
    branch1->Add(leaf_1);
    branch1->Add(leaf_2);
    branch1->Add(leaf_3);

    tree->Add(branch1);

    EXPECT_EQ( tree->Operation(), "Branch(Branch(Leaf+Leaf+Leaf))");
   


}

