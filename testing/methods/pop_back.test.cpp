#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"

TEST(pop_back, should_pop_back)
{
	const int aux = 2;
	intlist list{ aux, 3 };
	list.pop_back();
	EXPECT_EQ(list.back(), aux);
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