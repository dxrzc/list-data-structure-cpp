#include <gtest/gtest.h>
#include "list.h"
#include "../helpers/intlist.typealias.helper.h"
#include "../helpers/compare-list.helper.h"
#include "../helpers/is-even.helper.h"

TEST(remove_if, shouldRemoveSucefully)
{
	intlist list{ 1,2,3,4,5 };
	list.remove_if(isEven);
	auto it = list.cbegin();
	EXPECT_EQ(*it, 1);
	++it;
	EXPECT_EQ(*it, 3);
	++it;
	EXPECT_EQ(*it, 5);
}

TEST(remove_if, noProblemIfListEmpty)
{
	intlist emptylist;
	auto removed = emptylist.remove_if(isEven);
	EXPECT_EQ(removed, 0);
}

TEST(remove_if, returnTheNumberOfElementsRemoved)
{
	intlist list{ 2,4,9,6,8,1 };
	auto removed = list.remove_if(isEven);
	EXPECT_EQ(removed, 4);
}

TEST(remove_if, shouldUpdateListSize)
{
	intlist list{ 1,2,3,4,5 };
	auto removed = list.remove_if(isEven);
	EXPECT_EQ(list.size(), 3);
}