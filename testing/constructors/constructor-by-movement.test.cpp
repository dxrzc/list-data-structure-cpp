#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"
#include "../helpers/resource.helper.h"

TEST(constructorByMovement, shouldUpdateNelms)
{
	intlist list{ 1,2,3 };
	intlist list2 = std::move(list);
	EXPECT_EQ(list.size(), 0);
	EXPECT_EQ(list2.size(), 3);
}

TEST_F(testResourceList, constructorByMovementshouldNotMakeCopies)
{
	listForTesting.emplace_back(testResource());
	listForTesting.emplace_back(testResource());
	listForTesting.emplace_back(testResource());

	list<testResource> resourceList = std::move(listForTesting);

	EXPECT_EQ(testResource::copyConstructor, 0);
}