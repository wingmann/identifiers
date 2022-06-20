#include "../include/identifier.h"
#include "gtest/gtest.h"

std::string get_next_identifier(const std::string& value) {
    Identifier identifier{value};
    identifier.increase();

    return identifier.get_value();
}

TEST(IdentifierTest, EntryPoint) {
    const auto str = get_next_identifier("A1-B2-C3");
    EXPECT_EQ("A1-B2-C4", str);
}
