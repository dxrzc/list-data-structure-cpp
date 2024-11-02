#include <gtest/gtest.h>
#include "list.h"
#include "../helpers/intlist.typealias.helper.h"
#include "../helpers/compare-list.helper.h"

TEST(splice, shouldSpliceSuccefully)
{
	intlist list{ 1,2,3 };
	intlist splicedlist{ 9,8,7 };
	auto begin = list.begin();

	list.splice(begin, splicedlist);

	EXPECT_TRUE(compareList(list, intlist{ 1,9,8,7,2,3 }));
}

TEST(splice, shouldUpdateNelms)
{
	intlist list{ 1,2,3 };
	intlist splicedlist{ 9,8,7 };
	auto begin = list.begin();

	list.splice(begin, splicedlist);

	EXPECT_EQ(list.size(), 6);
	EXPECT_EQ(splicedlist.size(), 0);
}

TEST(splice, rightListShouldBeEmtpyAfterSplice)
{

	intlist list{ 1,2,3 };
	intlist splicedlist{ 9,8,7 };
	auto begin = list.begin();

	list.splice(begin, splicedlist);

	EXPECT_TRUE(splicedlist.empty());
}

TEST(splice, ifRightIsEmpty)
{
	intlist list{ 1,2,3 };
	intlist empty;

	list.splice(list.begin(), empty);

	EXPECT_TRUE(compareList(list, intlist{ 1,2,3 }));
	EXPECT_TRUE(empty.empty());
}

TEST(splice, ifCurrentListIsEmpty)
{
	intlist list;
	intlist newlist{ 1,2,3 };

	list.splice(list.end(), newlist);

	EXPECT_TRUE(compareList(list, intlist{ 1,2,3 }));
	EXPECT_TRUE(newlist.empty());
}

TEST(splice, shouldAcceptDifferentTypesOfIterator)
{
	intlist list;
	intlist testlist;

	list.splice(list.cbegin(), testlist);
	list.splice(list.rbegin(), testlist);
	list.splice(list.crbegin(), testlist);
}