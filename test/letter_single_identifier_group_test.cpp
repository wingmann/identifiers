#include "gtest/gtest.h"

#include "base.h"

#include "identifier.h"
#include "invalid_identifier_exception.h"

TEST(identifiers, letter_single_identifier_group)
{
    const BaseTestInstance base_test_instance{};

    for (char i = 'A'; 'Z' >= i; ++i) {
        std::ostringstream os;
        os << i << '9';

        try {
            IdentifierGroup identifierGroup{(os.str())};
            identifierGroup.increase();

            const std::string& str = identifierGroup.get_value();

            EXPECT_FALSE(base_test_instance.is_unavailable_char(i));
            EXPECT_EQ('1', str[1]);
        }
        catch (InvalidIdentifierException&) {
            EXPECT_TRUE(base_test_instance.is_unavailable_char(i));
        }
    }

    IdentifierGroup identifierGroup{"Z9"};

    EXPECT_EQ("Z9", identifierGroup.get_value());

    identifierGroup.increase();

    EXPECT_EQ("A1", identifierGroup.get_value());
}
