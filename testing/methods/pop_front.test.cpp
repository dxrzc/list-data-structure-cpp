#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"

TEST(pop_front, shouldPopTheFront)
{
	intlist list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	list.pop_front();
	EXPECT_EQ(list.front(), 2);
}

TEST(pop_front, ifListEmptyShouldThrowException)
{
	intlist emptylist;
	EXPECT_THROW(emptylist.pop_front(), std::length_error);
}

TEST(pop_front, shouldChangeSize)
{
	intlist list{ 1,2,3 };
	const auto currentSize = list.size();
	list.pop_front();
	EXPECT_EQ(list.size(), currentSize - 1);
}