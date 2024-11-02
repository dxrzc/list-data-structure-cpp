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

TEST_F(testResourceList, dontCopyUsingEmplaceBack)
{
	listForTesting.emplace_back(100);
	EXPECT_EQ(testResource::instancesCreated, 1);
}

TEST_F(testResourceList, updateNelmsUsingEmplaceBack)
{
	listForTesting.emplace_back(100);
	EXPECT_EQ(listForTesting.size(), 1);
}