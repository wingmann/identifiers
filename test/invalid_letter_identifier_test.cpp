#include "gtest/gtest.h"

#include "identifier.h"
#include "invalid_identifier_exception.h"

TEST(IdentifierTest, InvalidLetterIdentifier) {
    try {
        Identifier identifier{"V1"};
    } catch (InvalidIdentifierException&) {
        EXPECT_TRUE(true);
    }
}
