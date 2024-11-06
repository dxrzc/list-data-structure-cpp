#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"

TEST(pop_front, should_pop_front)
{
	const int aux = 2;
	intlist list{ 1,aux };
	list.pop_front();
	EXPECT_EQ(list.front(), aux);
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