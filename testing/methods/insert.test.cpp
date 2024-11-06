#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"

TEST(insertUsingIterator, shouldInsertBeforeTheIteratorGiven)
{
	intlist list{ 1, 2, 3 };
	auto it = list.begin();

	const int newNumber = 100;
	list.insert(it, newNumber);

	EXPECT_EQ(*(list.begin()), newNumber);
}

TEST(insertUsingIterator, shouldReturnIteratorToNewValue)
{
	intlist list{ 1, 2, 3 };
	auto it = list.begin();
	auto newIt = list.insert(it, 100);
	EXPECT_EQ(*(newIt), 100);
}

TEST(insertUsingIterator, shouldIncrementNelms)
{
	intlist list;
	list.insert(list.end(), 1);
	list.insert(list.end(), 1);
	list.insert(list.end(), 1);
	EXPECT_EQ(list.size(), 3);
}