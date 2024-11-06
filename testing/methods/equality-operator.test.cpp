#include <gtest/gtest.h>
#include "list.h"
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"

// "compare_list" helper uses the equality_operator
// so we used it here. It also allows to receive a more
// readable message when the comparition fails.

TEST(equality_operator, should_return_true_if_both_empty)
{
	intlist list;
	intlist list2;
	EXPECT_TRUE(compare_list(list, list2));
}

TEST(equality_operator, should_return_true_if_both_equal)
{
	intlist list{ 1, 2, 3, 4, 5 };
	intlist list2{ 1, 2, 3, 4, 5 };
	EXPECT_TRUE(compare_list(list, list2));
}

TEST(equality_operator, should_return_false_if_size_different)
{
	intlist list{ 1, 2, 3, 4, 5 };
	intlist list2{ 1, 2, 3, 4, 5, 6 };
	EXPECT_FALSE(compare_list(list, list2));
}

TEST(equality_operator, should_return_true_if_same_size_but_differents)
{
	intlist list{ 1, 2, 3, 4, 5, 7 };
	intlist list2{ 1, 2, 3, 4, 5, 6 };
	EXPECT_FALSE(compare_list(list, list2));
}