#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"

TEST(copyConstructor, shouldCopySuccefully)
{
	intlist list{ 1, 2, 3 };
	intlist list2 = list;
	ASSERT_EQ(list.front(), 1);
	list.pop_front();
	ASSERT_EQ(list.front(), 2);
	list.pop_front();
	ASSERT_EQ(list.front(), 3);
}

TEST(copyConstructor, shouldsetNelms)
{
	intlist list{ 1, 2, 3, 4, 5 };
	intlist list2 = list;
	EXPECT_EQ(list.size(), list2.size());
}