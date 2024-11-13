#include <gtest/gtest.h>
#include "list.h"
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"
#include "is-even.helper.h"

TEST(remove_if, should_remove_successfully)
{
	intlist list{ 1,2,3,4,5 };
	list.remove_if(is_even);
	auto it = list.cbegin();
	EXPECT_TRUE(compare_list(list, intlist{ 1,3,5 }));
}

TEST(remove_if, should_n_elements_removed)
{
	intlist list{ 2,4,9,6,8,1 };
	auto removed = list.remove_if(is_even);
	EXPECT_EQ(removed, 4);
}

TEST(remove_if, should_return_0_if_no_element_match_condition)
{
	intlist list{ 1,2,3 };
	auto removed = list.remove_if([](int x) {return x == 5; });
	EXPECT_EQ(removed, 0);
}

TEST(remove_if, should_not_cause_fatal_failure_on_empty_list)
{
	intlist emptylist;
	EXPECT_NO_FATAL_FAILURE(emptylist.remove_if(is_even));
}