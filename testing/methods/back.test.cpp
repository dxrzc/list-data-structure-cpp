#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"

TEST(front, shoudlReturnTheBack)
{
	const int valueExpected = 3;
	intlist list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	EXPECT_EQ(list.back(), valueExpected);
}

TEST(back, shouldThrowLengthError)
{
	intlist emptylist;
	EXPECT_THROW(emptylist.back(), std::length_error);
}

TEST(back_constlist, shouldReturnTheBack)
{
	const int back = 10;
	const intlist list{ 1,2,back };
	EXPECT_EQ(list.back(), back);
}

TEST(back_constlist, shouldThrowLengthError)
{
	const intlist emptylist;
	EXPECT_THROW(emptylist.back(), std::length_error);
}