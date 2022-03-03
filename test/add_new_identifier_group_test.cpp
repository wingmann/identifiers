#include "gtest/gtest.h"

#include "identifier.h"

TEST(IdentifierTest, AddNewIdentifierGroup_1)
{
    Identifier identifier{"Z9"};
    identifier.increase();

    EXPECT_EQ(identifier.get_value(), "A1-A1");
}

TEST(IdentifierTest, AddNewIdentifierGroup_2)
{
    Identifier identifier{"A1-Z9"};
    identifier.increase();

    EXPECT_EQ(identifier.get_value(), "A2-A1");
}

TEST(IdentifierTest, AddNewIdentifierGroup_3)
{
    Identifier identifier{"A1-B1-Z9"};
    identifier.increase();

    EXPECT_EQ(identifier.get_value(), "A1-B2-A1");
}

TEST(IdentifierTest, AddNewIdentifierGroup_4)
{
    Identifier identifier{"A1-Z9-Z9"};
    identifier.increase();

    EXPECT_EQ(identifier.get_value(), "A2-A1-A1");
}

TEST(IdentifierTest, AddNewIdentifierGroup_5)
{
    Identifier identifier{"Z9-Z9"};
    identifier.increase();

    EXPECT_EQ(identifier.get_value(), "A1-A1-A1");
}

TEST(IdentifierTest, AddNewIdentifierGroup_6)
{
    Identifier identifier{"Z9-Z9-Z9"};
    identifier.increase();

    EXPECT_EQ(identifier.get_value(), "A1-A1-A1-A1");
}
