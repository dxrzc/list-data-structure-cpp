#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"

TEST(iterator_constructor, should_create_list_successfully)
{
	intlist list{ 1,2,3,4,5 };
	intlist::iterator begin = ++(list.begin()); // 2
	intlist::iterator end = --(list.end()); // 5

	intlist test_list(begin, end);

	EXPECT_TRUE(compare_list(test_list, intlist{ 2,3,4 }));
}

TEST(iterator_constructor, should_create_list_successfully_using_begin_and_end_iterators)
{
	intlist list{ 1,2,3,4,5 };	
	intlist test_list(list.begin(), list.end());

	EXPECT_TRUE(compare_list(test_list, list));
}

TEST(iterator_constructor, should_success_if_rhs_list_empty)
{
	intlist rhs_list;
	intlist newlist(rhs_list.begin(), rhs_list.end());

	EXPECT_TRUE(compare_list(rhs_list, newlist));
}

TEST(iterator_constructor, should_not_make_changes_on_rhs_list)
{
	intlist rhs_list{ 1,2,3 };
	intlist test_list(++rhs_list.begin(), rhs_list.end());

	EXPECT_TRUE(compare_list(rhs_list, intlist{ 1,2,3 }));
}