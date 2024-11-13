#include <gtest/gtest.h>
#include "list.h"
#include "intlist.typealias.helper.h"

TEST(contains, should_return_true_if_list_contains_the_value)
{
	const int val = 3;
	intlist list{ 1,2,val };
	EXPECT_TRUE(list.contains(val));
}

TEST(contains, should_return_true_if_list_not_contains_the_value)
{
	const int val = 4;
	intlist list{ 1,2,3 };
	EXPECT_FALSE(list.contains(val));
}

TEST(contains, should_not_cause_fatal_failure_on_empty_list)
{
	intlist list;
	EXPECT_NO_FATAL_FAILURE(list.contains(100));
}

TEST(contains, should_return_false_on_empty_list)
{
	intlist list;
	EXPECT_FALSE(list.contains(1));
}