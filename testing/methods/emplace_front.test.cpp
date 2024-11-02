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

TEST_F(testResourceList, dontCopyUsingEmplaceFront)
{
	listForTesting.emplace_front(100);
	EXPECT_EQ(testResource::instancesCreated, 1);
}

TEST_F(testResourceList, updateNelmsUsingEmplaceFront)
{
	listForTesting.emplace_front(100);
	EXPECT_EQ(listForTesting.size(), 1);
}