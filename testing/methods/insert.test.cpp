#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"

TEST(insert_by_iterator, should_insert_succesfully)
{
	intlist list{ 1,2,3 };
	const int new_value = 0;
	list.insert(list.begin(), new_value);
	EXPECT_EQ(list.front(), new_value);
}

TEST(insert_by_iterator, should_return_iterator_to_new_value)
{
	intlist list{ 1,2,3 };
	const int new_value = 101;
	auto new_value_it = list.insert(list.begin(), new_value);
	EXPECT_EQ(*new_value_it, new_value);
}

TEST(insert_by_iterator, should_update_nelms)
{
	intlist list{ 1,2,3 };
	const std::size_t current_size = list.size();
	list.insert(list.begin(), 1);
	EXPECT_EQ(list.size(), current_size + 1);
}