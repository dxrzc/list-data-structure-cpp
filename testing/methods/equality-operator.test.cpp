#include <gtest/gtest.h>
#include "list.h"
#include "../helpers/intlist.typealias.helper.h"
#include "../helpers/compare-list.helper.h"

TEST(operatorEquality, shouldReturnTrueifListsEmpty)
{
	intlist list;
	intlist list2;
	EXPECT_TRUE(compare_list(list, list2));
}

TEST(operatorEquality, shouldReturnTrue)
{
	intlist list{ 1, 2, 3, 4, 5 };
	intlist list2{ 1, 2, 3, 4, 5 };
	EXPECT_TRUE(compare_list(list, list2));
}

TEST(operatorEquality, shouldReturnFalseIfSizeDifferent)
{
	intlist list{ 1, 2, 3, 4, 5 };
	intlist list2{ 1, 2, 3, 4, 5, 6 };
	EXPECT_FALSE(compare_list(list, list2));
}

TEST(operatorEquality, shouldReturnFalse)
{
	intlist list{ 1, 2, 3, 4, 5, 7 };
	intlist list2{ 1, 2, 3, 4, 5, 6 };
	EXPECT_FALSE(compare_list(list, list2));
}