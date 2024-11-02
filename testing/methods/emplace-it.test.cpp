#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"
#include "../helpers/resource.helper.h"

TEST(emplaceUsingIterator, shouldInsertBeforeTheIteratorGiven)
{
	const int newvalue = 100;
	intlist list{ 1,2,3 };
	list.emplace(list.begin(), newvalue);
	EXPECT_EQ(list.front(), newvalue);
}

TEST_F(testResourceList, emplaceUsingIteratorShouldNotCopy)
{
	listForTesting.emplace(listForTesting.end(), testResource());
	EXPECT_EQ(testResource::instancesCreated, 1);
}

TEST(emplaceUsingIterator, shouldUpdateNelms)
{
	intlist list{ 1,2,3 };
	list.emplace(list.end(), 10);
	EXPECT_EQ(list.size(), 4);
}