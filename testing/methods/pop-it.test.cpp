#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"

TEST(pop_by_iterator, should_pop_begin_sucesfully)
{
	intlist expected_list{ 2,3 };

	intlist list{ 1,2,3 };

	ASSERT_NO_FATAL_FAILURE(list.pop(list.begin()));
	EXPECT_TRUE(compare_list(list, expected_list));
}

TEST(pop_by_iterator, should_pop_last_sucesfully)
{
	intlist expected_list{ 1,2 };

	intlist list{ 1,2,3 };
	intlist::iterator it = list.end();
	std::advance(it, -1); // last element

	ASSERT_NO_FATAL_FAILURE(list.pop(it));
	EXPECT_TRUE(compare_list(list, expected_list));
}

TEST(pop_by_iterator, should_pop_random_element_sucesfully)
{
	intlist expected_list{ 1,2,4,5 };

	intlist list{ 1,2,3,4,5 };
	intlist::iterator it = list.begin();
	std::advance(it, 2);

	ASSERT_NO_FATAL_FAILURE(list.pop(it));
	EXPECT_TRUE(compare_list(list, expected_list));
}

TEST(pop_by_iterator, should_return_iterator_to_next_element)
{
	const int aux = 2;
	intlist list{ 1, aux, 3 };
	auto it = list.pop(list.begin());
	EXPECT_EQ(*it, aux);
}

TEST(pop_by_iterator, should_update_nelms)
{
	intlist list{ 1, 2, 3 };
	const std::size_t current_size = list.size();
	list.pop(list.begin());
	EXPECT_EQ(list.size(), current_size - 1);
}

TEST(pop_by_iterator, should_throw_length_error_if_list_empty)
{
	intlist list;
	EXPECT_THROW(list.pop(list.begin()), std::length_error);
}

TEST(pop_by_iterator, should_throw_error_if_iterator_points_to_head)
{
	intlist list{ 1, 2 };
	auto it = list.end(); // pointing to head
	EXPECT_THROW(list.pop(it), std::runtime_error);
}