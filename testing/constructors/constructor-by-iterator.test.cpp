#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"

TEST(constructor_by_iterators, should_create_list_successfully)
{
	intlist list{ 1,2,3,4,5 };
	intlist::iterator begin = ++(list.begin()); // 2
	intlist::iterator end = --(list.end()); // 5

	intlist newlist(begin, end);
	EXPECT_TRUE(compare_list(newlist, intlist{ 2,3,4 }));
	EXPECT_EQ(newlist.size(), 3);
}

TEST(constructor_by_iterators, should_success_if_list_empty)
{
	intlist emptylist;
	intlist newlist(emptylist.begin(), emptylist.end());
	EXPECT_TRUE(compare_list(emptylist, newlist));
}