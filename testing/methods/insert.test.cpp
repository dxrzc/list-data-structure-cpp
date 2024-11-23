#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"

TEST(insert_by_iterator, should_insert_succesfully_at_begin)
{
	const int new_value = 0;
	intlist expected_list = { new_value ,1,2,3 };

	intlist list{ 1,2,3 };
	EXPECT_NO_FATAL_FAILURE(list.insert(list.begin(), new_value));	

	EXPECT_TRUE(compare_list(list, expected_list));
}

TEST(insert_by_iterator, should_insert_succesfully_at_end)
{
	const int new_value = 4;
	intlist expected_list = { 1,2,3, new_value };

	intlist list{ 1,2,3 };
	EXPECT_NO_FATAL_FAILURE(list.insert(list.end(), new_value));

	EXPECT_TRUE(compare_list(list, expected_list));
}

TEST(insert_by_iterator, should_insert_succesfully_at_random_pos)
{
	const int new_value = 100;
	intlist expected_list = { 1,2,100,3 };

	intlist list{ 1,2,3 };
	intlist::iterator it = list.begin();
	std::advance(it, 2);
	list.insert(it, new_value);

	EXPECT_TRUE(compare_list(list, expected_list));
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