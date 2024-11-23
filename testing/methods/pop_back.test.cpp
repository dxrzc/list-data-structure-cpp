#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"

TEST(pop_back, should_pop_last_element)
{
	intlist expected_list{ 1,2,3 };

	intlist list{ 1,2,3,4 };	

	ASSERT_NO_FATAL_FAILURE(list.pop_back());
	EXPECT_TRUE(compare_list(list, expected_list));
}

TEST(pop_back, should_throw_length_error_if_list_empty)
{
	intlist empty_list;
	EXPECT_THROW(empty_list.pop_back(), std::length_error);
}

TEST(pop_back, should_update_nelms)
{
	intlist list{ 1,2,3 };
	const auto current_size = list.size();
	list.pop_back();
	EXPECT_EQ(list.size(), current_size - 1);
}