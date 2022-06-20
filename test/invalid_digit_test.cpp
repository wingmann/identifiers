#include "gtest/gtest.h"

#include "identifier.h"
#include "invalid_identifier_exception.h"

TEST(identifiers, invalid_digit)
{
    try {
        Identifier identifier{"A0"};
    }
    catch (InvalidIdentifierException&) {
        EXPECT_TRUE(true);
    }
}
