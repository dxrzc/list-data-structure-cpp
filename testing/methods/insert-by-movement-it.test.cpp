#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"
#include "../helpers/resource.helper.h"

TEST(insertUsingIteratorByMovement, shouldInsertBeforeTheIteratorGiven)
{
	int newvalue = 100;
	intlist list{ 1,2,3 };
	list.insert(list.begin(), std::move(newvalue));
	EXPECT_EQ(list.front(), newvalue);
}

TEST_F(testResourceList, insertByMovementUsingIteratorShouldNotCopy)
{
	listForTesting.insert(listForTesting.end(), testResource());
	EXPECT_EQ(testResource::instancesCreated, 1);
}

TEST(insertUsingIteratorByMovement, shouldUpdateNelms)
{
	intlist list{ 1,2,3 };
	list.insert(list.end(), 10);
	EXPECT_EQ(list.size(), 4);
}