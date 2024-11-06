#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"

TEST(pop_by_iterator, should_pop_element_succesfully)
{
	const int aux = 2;
	intlist list{ 1, aux, 3 };
	list.pop(list.begin());
	EXPECT_EQ(list.front(), aux);
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