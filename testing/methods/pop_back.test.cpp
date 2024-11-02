#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"

TEST(pop_back, shouldPoptheBack)
{
	intlist list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	list.pop_back();

	EXPECT_EQ(list.back(), 2);
}

TEST(pop_back, ifListEmptyShouldThrowException)
{
	intlist emptylist;
	EXPECT_THROW(emptylist.pop_back(), std::length_error);
}

TEST(pop_back, shouldChangeSize)
{
	intlist list{ 1,2,3 };
	const auto currentSize = list.size();
	list.pop_back();
	EXPECT_EQ(list.size(), currentSize - 1);
}