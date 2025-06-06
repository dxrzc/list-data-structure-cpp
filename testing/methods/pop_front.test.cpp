#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"

TEST(pop_front, should_pop_begin)
{
	intlist expected_list{ 2,3 };

	intlist list{ 1,2,3 };

	ASSERT_NO_FATAL_FAILURE(list.pop_front());
	EXPECT_TRUE(compare_list(expected_list, list));
}

TEST(pop_front, should_throw_length_error_if_list_empty)
{
	intlist empty_list;
	EXPECT_THROW(empty_list.pop_front(), std::length_error);
}

TEST(pop_front, should_update_nelms)
{
	intlist list{ 1,2,3 };
	const auto current_size = list.size();
	list.pop_front();
	EXPECT_EQ(list.size(), current_size - 1);
}