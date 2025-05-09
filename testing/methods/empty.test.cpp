#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"

TEST(empty, should_return_false_if_list_not_empty)
{
	intlist list{ 1,2,3 };
	EXPECT_FALSE(list.empty());
}

TEST(empty, should_return_true_if_list_empty)
{
	intlist list;
	EXPECT_TRUE(list.empty());
}
