#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"

TEST(front, should_return_the_front)
{
	const int front_expected = 1;
	intlist list;
	list.push_back(front_expected);
	list.push_back(2);
	list.push_back(3);
	EXPECT_EQ(list.front(), front_expected);
}

TEST(front, should_throw_length_error)
{
	intlist empty_list;
	EXPECT_THROW(empty_list.front(), std::length_error);
}

TEST(front_constlist, should_return_the_front)
{
	const int front = 10;
	const intlist list{ front, 2, 3 };
	EXPECT_EQ(list.front(), front);
}

TEST(front_constlist, should_throw_length_error)
{
	const intlist empty_list;
	EXPECT_THROW(empty_list.front(), std::length_error);
}