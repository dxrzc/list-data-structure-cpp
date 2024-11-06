#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"
#include "../helpers/resource.helper.h"

TEST(emplace_front, shouldInsertInTheFront)
{
	const int newvalue = 4;
	intlist testlist{ 1,2,3 };
	testlist.emplace_front(newvalue);
	EXPECT_EQ(testlist.front(), newvalue);
}

TEST_F(test_resource_list, dontCopyUsingEmplaceFront)
{
	test_list.emplace_front(100);
	EXPECT_EQ(test_resource::instances_created, 1);
}

TEST_F(test_resource_list, updateNelmsUsingEmplaceFront)
{
	test_list.emplace_front(100);
	EXPECT_EQ(test_list.size(), 1);
}