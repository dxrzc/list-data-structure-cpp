#include <gtest/gtest.h>
#include "list.h"
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"

TEST(sort, should_sort_list_successfully)
{
	intlist list{ 0,6,2,3,9,7,1,4,5,8 };
	list.sort();
	EXPECT_TRUE(compare_list(list, intlist{ 0,1,2,3,4,5,6,7,8,9 }));	
}

TEST(sort, should_not_cause_fatal_failure_on_empty_list)
{
	intlist emptylist;
	EXPECT_NO_FATAL_FAILURE(emptylist.sort());	
}

TEST(sort, should_not_throw_error_if_list_has_one_elm)
{
	intlist list{ 1 };
	ASSERT_NO_THROW(list.sort());
	EXPECT_TRUE(compare_list(list, intlist{ 1 }));
}