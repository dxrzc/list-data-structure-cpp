#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"

TEST(size, shouldReturnTheCorrectSize)
{
	intlist list;
	list.push_back(1);
	list.push_back(1);
	list.push_back(1);
	EXPECT_EQ(list.size(), 3);
}

TEST(size, sizeShouldBe0ifListEmpty)
{
	intlist list;
	EXPECT_EQ(list.size(), 0);
}
