#include "gtest/gtest.h"

#include "end_of_sequence_exception.h"
#include "identifier.h"

TEST(identifiers, max_identifier_group_count)
{
    try {
        Identifier identifier{"Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z8"};
        identifier.increase();

        EXPECT_EQ(identifier.get_value(), "Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9");

        identifier.increase();
    }
    catch (EndOfSequenceException& e) {
        EXPECT_TRUE(true);
    }
}
