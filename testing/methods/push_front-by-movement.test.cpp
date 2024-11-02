#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"
#include "../helpers/resource.helper.h"

TEST_F(testResourceList, updateNelmsUsingPushFrontbyMovement)
{
	testResource resource;
	listForTesting.push_front(std::move(resource));
	EXPECT_EQ(listForTesting.size(), 1);
	EXPECT_EQ(testResource::movementConstructor, 1);
}

TEST_F(testResourceList, pushFrontDontCopyUsingStdMove)
{
	testResource resource;
	listForTesting.push_front(std::move(resource));
	EXPECT_EQ(testResource::instancesCreated, 1);
}

TEST_F(testResourceList, updateNelmsUsingPushFrontByMovement)
{
	intlist list{ 1,2,3 };
	const auto currentsize = list.size();
	list.push_front(std::move(1));
	EXPECT_EQ(list.size(), currentsize + 1);
}