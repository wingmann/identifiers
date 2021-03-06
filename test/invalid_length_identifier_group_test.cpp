#include "gtest/gtest.h"

#include "identifier_group.h"
#include "invalid_identifier_exception.h"

TEST(identifiers, invalid_length_identifier_group)
{
    try {
        IdentifierGroup identifierGroup{"A"};
    }
    catch (InvalidIdentifierException&) {
        EXPECT_TRUE(true);
    }

    try {
        IdentifierGroup identifierGroup{"A11"};
    }
    catch (InvalidIdentifierException&) {
        EXPECT_TRUE(true);
    }
}
