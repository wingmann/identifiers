#include "../include/identifier.h"
#include "gtest/gtest.h"

auto get_next_identifier = [](const std::string& value)
{
    Identifier identifier{value};
    identifier.increase();

    return identifier.get_value();
};

TEST(identifiers, entry_point)
{
    const auto str = get_next_identifier("A1-B2-C3");
    EXPECT_EQ("A1-B2-C4", str);
}
