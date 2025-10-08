#include "intlist.typealias.helper.h"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(subscript_operator, return_expected_value)
{
    intlist list{1, 2, 3, 4, 5};
    EXPECT_EQ(list[2], 3);
}

TEST(subscript_operator, throw_error_length_error_if_list_empty)
{
    intlist list;
    EXPECT_THROW(list[1], std::length_error);
}

TEST(subscript_operator, throw_out_of_range_error_if_index_is_out_of_bounds)
{
    intlist list {1,2,3};
    EXPECT_THROW(list[10], std::out_of_range);
}
