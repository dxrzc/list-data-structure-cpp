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

TEST_F(test_resource_list, insertByMovementUsingIteratorShouldNotCopy)
{
	test_list.insert(test_list.end(), test_resource());
	EXPECT_EQ(test_resource::instances_created, 1);
}

TEST(insertUsingIteratorByMovement, shouldUpdateNelms)
{
	intlist list{ 1,2,3 };
	list.insert(list.end(), 10);
	EXPECT_EQ(list.size(), 4);
}