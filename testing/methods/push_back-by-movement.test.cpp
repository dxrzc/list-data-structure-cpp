#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"
#include "../helpers/resource.helper.h"

TEST(push_backByMovement, shouldInsertInTheBack)
{
	int newvalue = 4;
	intlist testlist{ 1,2,3 };
	testlist.push_back(std::move(newvalue));
	EXPECT_EQ(testlist.back(), newvalue);
}

TEST_F(testResourceList, pushBackDontCopyUsingStdMove)
{
	testResource resource;
	listForTesting.push_back(std::move(resource));
	EXPECT_EQ(testResource::instancesCreated, 1);
	EXPECT_EQ(testResource::movementConstructor, 1);
}

TEST_F(testResourceList, updateNelmsUsingPushBackbyMovement)
{
	testResource resource;
	listForTesting.push_back(std::move(resource));
	EXPECT_EQ(listForTesting.size(), 1);
}
