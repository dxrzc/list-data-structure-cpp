#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"

TEST(push_back, should_push_at_end)
{
	int new_value = 4;
	intlist expected_list{ 1,2,3,new_value };

	intlist list{ 1,2,3 };

	ASSERT_NO_FATAL_FAILURE(list.push_back(new_value));
	EXPECT_TRUE(compare_list(expected_list, list));
}

TEST(push_back, should_update_size)
{
	intlist list{ 1,2,3 };
	const std::size_t current_size = list.size();

	list.push_back(4);

	EXPECT_EQ(list.size(), current_size + 1);
}