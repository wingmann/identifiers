#include "gtest/gtest.h"

#include "identifier_group.h"
#include "invalid_identifier_exception.h"

TEST(identifiers, invalid_number_identifier_group)
{
    try {
        IdentifierGroup identifierGroup{"B0"};
    }
    catch (InvalidIdentifierException&) {
        EXPECT_TRUE(true);
    }
}
