#include <gtest/gtest.h>
#include "list.h"
#include "../helpers/intlist.typealias.helper.h"
#include "../helpers/compare-list.helper.h"

TEST(operatorEqual, shouldClearAndAssign)
{
	intlist list{ 1, 2, 3 };
	intlist newlist{ 3, 2, 1 };
	newlist = list;
	EXPECT_TRUE(compare_list(newlist, list));
}

TEST(operatorEqual, dontClearifItsTheSameList)
{
	intlist list{ 1, 2, 3 };
	list = list;
	EXPECT_TRUE(compare_list(list, intlist{ 1, 2, 3 }));
}