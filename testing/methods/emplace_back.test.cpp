#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"
#include "../helpers/resource.helper.h"

TEST(emplace_back, shouldInsertInTheBack)
{
	const int newvalue = 4;
	intlist testlist{ 1,2,3 };
	testlist.emplace_back(newvalue);
	EXPECT_EQ(testlist.back(), newvalue);
}

TEST_F(test_resource_list, dontCopyUsingEmplaceBack)
{
	test_list.emplace_back(100);
	EXPECT_EQ(test_resource::instances_created, 1);
}

TEST_F(test_resource_list, updateNelmsUsingEmplaceBack)
{
	test_list.emplace_back(100);
	EXPECT_EQ(test_list.size(), 1);
}