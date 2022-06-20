#include "gtest/gtest.h"

#include "identifier.h"

TEST(identifiers, digit_identifier)
{
    Identifier identifier{"A1"};

    EXPECT_EQ("A1", identifier.get_value());

    for (int i = 2; i <= 9; ++i) {
        identifier.increase();

        std::ostringstream os;
        os << 'A' << i;

        EXPECT_EQ(os.str(), identifier.get_value());
    }

    EXPECT_EQ("A9", identifier.get_value());

    identifier.increase();

    EXPECT_EQ("B1", identifier.get_value());
}
