#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"

TEST(front, shouldReturnTheFront)
{
	const int frontExpected = 1;
	intlist list;
	list.push_back(frontExpected);
	list.push_back(2);
	list.push_back(3);
	EXPECT_EQ(list.front(), frontExpected);
}

TEST(front, shouldThrowLengthError)
{
	intlist emptylist;
	EXPECT_THROW(emptylist.front(), std::length_error);
}

TEST(front_constlist, shouldReturnTheFront)
{
	const int front = 10;
	const intlist list{ front,2,3 };
	EXPECT_EQ(list.front(), front);
}

TEST(front_constlist, shouldThrowLengthError)
{
	const intlist emptylist;
	EXPECT_THROW(emptylist.front(), std::length_error);
}