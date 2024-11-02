#include <gtest/gtest.h>
#include "list.h"
#include "../helpers/intlist.typealias.helper.h"
#include "../helpers/compare-list.helper.h"

TEST(sort, shouldSortListSuccefully)
{
	intlist list{ 0,6,2,3,9,7,1,4,5,8 };
	list.sort();
	EXPECT_TRUE(compareList(list, intlist{ 0,1,2,3,4,5,6,7,8,9 }));
	EXPECT_EQ(list.size(), 10);
}

TEST(sort, shouldSortListSuccefully2)
{
	intlist list{ 3,2 };
	list.sort();
	EXPECT_TRUE(compareList(list, intlist{ 2,3 }));
}

TEST(sort, ifListEmpty)
{
	intlist emptylist;
	emptylist.sort();
	EXPECT_TRUE(emptylist.empty());
}

TEST(sort, ifSizeIsOne)
{
	intlist list{ 1 };
	list.sort();
	EXPECT_TRUE(compareList(list, intlist{ 1 }));
}