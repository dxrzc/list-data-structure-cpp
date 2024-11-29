#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"

TEST(reverse, should_reverse_list_sucessfully)
{
	intlist list{ 1,3,5,7,9,11 };
	intlist expected{ 11,9,7,5,3,1 };

	ASSERT_NO_FATAL_FAILURE(list.reverse());

	EXPECT_TRUE(compare_list(list, expected));
}

TEST(reverse, should_no_fail_if_list_empty)
{
	intlist list;
	ASSERT_NO_FATAL_FAILURE(list.reverse());
	EXPECT_TRUE(list.empty());
}

TEST(reverse, should_no_fail_if_list_contains_only_one_element)
{
	intlist list{ 1 };
	ASSERT_NO_FATAL_FAILURE(list.reverse());
	EXPECT_TRUE(compare_list(list, intlist{ 1 }));
}

TEST(reverse, should_insert_succesfully_after_reverse)
{
	intlist list{ 1,3,5,7,9,11 };
	const int new_value = 100;
	intlist expected{ 11,9,7,5,3,1,new_value };

	ASSERT_NO_FATAL_FAILURE(list.reverse());
	ASSERT_NO_FATAL_FAILURE(list.insert(list.end(), new_value));
	EXPECT_TRUE(compare_list(list, expected));
}