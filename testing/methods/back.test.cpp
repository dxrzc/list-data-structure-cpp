#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"

TEST(back, should_return_the_back)
{
	const int value_expected = 3;
	intlist list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	EXPECT_EQ(list.back(), value_expected);
}

TEST(back, should_throw_length_error)
{
	intlist empty_list;
	EXPECT_THROW(empty_list.back(), std::length_error);
}

TEST(back_constlist, should_return_the_back)
{
	const int back = 10;
	const intlist list{ 1, 2, back };
	EXPECT_EQ(list.back(), back);
}

TEST(back_constlist, should_throw_length_error)
{
	const intlist empty_list;
	EXPECT_THROW(empty_list.back(), std::length_error);
}