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

TEST_F(test_resource_list, pushBackDontCopyUsingStdMove)
{
	test_resource resource;
	test_list.push_back(std::move(resource));
	EXPECT_EQ(test_resource::instances_created, 1);
	EXPECT_EQ(test_resource::movement_constructor, 1);
}

TEST_F(test_resource_list, updateNelmsUsingPushBackbyMovement)
{
	test_resource resource;
	test_list.push_back(std::move(resource));
	EXPECT_EQ(test_list.size(), 1);
}
