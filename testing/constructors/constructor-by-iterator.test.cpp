#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"
#include "../helpers/compare-list.helper.h"

TEST(constructorUsingIterator, shouldCreateTheListSuccefully)
{
	intlist list{ 1,2,3,4,5 };
	intlist::iterator begin = ++(list.begin());
	intlist::iterator end = --(list.end());

	intlist newlist(begin, end);
	EXPECT_TRUE(compare_list(newlist, intlist{ 2,3,4 }));
	EXPECT_EQ(newlist.size(), 3);
}

TEST(constructorUsingConst_Iterator, shouldCreateTheListSuccefully)
{
	intlist list{ 1,2,3,4,5 };
	intlist::const_iterator cbegin = ++(list.cbegin());
	intlist::const_iterator cend = --(list.cend());

	intlist newlist(cbegin, cend);
	EXPECT_TRUE(compare_list(newlist, intlist{ 2,3,4 }));
	EXPECT_EQ(newlist.size(), 3);
}

TEST(constructorUsingIterator, ifListIsEmpty)
{
	intlist emptylist;
	intlist newlist(emptylist.begin(), emptylist.end());
	EXPECT_TRUE(compare_list(emptylist, newlist));
}