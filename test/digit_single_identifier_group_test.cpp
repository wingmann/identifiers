#include "gtest/gtest.h"

#include "identifier.h"
#include "invalid_identifier_exception.h"

TEST(IdentifierTest, DigitSingleIdentifierGroup) {
    IdentifierGroup identifierGroup{"A1"};

    EXPECT_EQ("A1", identifierGroup.get_value());

    for (int i = 2; 9 >= i; ++i) {
        identifierGroup.increase();

        std::ostringstream os;
        os << 'A' << i;

        EXPECT_EQ(os.str(), identifierGroup.get_value());
    }

    EXPECT_EQ("A9", identifierGroup.get_value());

    identifierGroup.increase();

    EXPECT_EQ("B1", identifierGroup.get_value());
}
