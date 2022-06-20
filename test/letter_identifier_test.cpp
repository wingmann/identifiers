#include "gtest/gtest.h"

#include "base.h"

#include "identifier.h"
#include "invalid_identifier_exception.h"

TEST(identifiers, letter_identifier)
{
    const BaseTestInstance base_test_instance{};

    for (char i = 'A'; i <= 'Z'; ++i) {
        std::ostringstream os;
        os << i << '9';

        try {
            Identifier identifier{(os.str())};
            identifier.increase();

            const std::string& value = identifier.get_value();

            EXPECT_FALSE(base_test_instance.is_unavailable_char(i));
            EXPECT_EQ('1', value[1]);
        }
        catch (InvalidIdentifierException&) {
            EXPECT_TRUE(base_test_instance.is_unavailable_char(i));
        }
    }
}
