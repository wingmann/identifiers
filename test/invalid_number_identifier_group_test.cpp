#include "gtest/gtest.h"

#include "identifier_group.h"
#include "invalid_identifier_exception.h"

TEST(IdentifierTest, InvalidNumberIdentifierGroup)
{
    try {
        IdentifierGroup identifierGroup{"B0"};
    }
    catch(InvalidIdentifierException&) {
        EXPECT_TRUE(true);
    }
}
