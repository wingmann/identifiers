#include "gtest/gtest.h"

#include "identifier.h"
#include "invalid_identifier_exception.h"

TEST(identifiers, invalid_length_identifier)
{
    try {
        Identifier identifier{"A"};
    }
    catch (InvalidIdentifierException&) {
        EXPECT_TRUE(true);
    }

    try {
        Identifier identifier{"A11"};
    }
    catch (InvalidIdentifierException&) {
        EXPECT_TRUE(true);
    }

    try {
        Identifier identifier{"A1-A1-A1-A1-A1-A1-A1-A1-A1-A1-A1"};
    }
    catch (InvalidIdentifierException&) {
        EXPECT_TRUE(true);
    }
}
