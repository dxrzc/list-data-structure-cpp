#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"
#include "../helpers/resource.helper.h"

TEST_F(test_resource_list, updateNelmsUsingPushFrontbyMovement)
{
	test_resource resource;
	test_list.push_front(std::move(resource));
	EXPECT_EQ(test_list.size(), 1);
	EXPECT_EQ(test_resource::movement_constructor, 1);
}

TEST_F(test_resource_list, pushFrontDontCopyUsingStdMove)
{
	test_resource resource;
	test_list.push_front(std::move(resource));
	EXPECT_EQ(test_resource::instances_created, 1);
}

TEST_F(test_resource_list, updateNelmsUsingPushFrontByMovement)
{
	intlist list{ 1,2,3 };
	const auto currentsize = list.size();
	list.push_front(std::move(1));
	EXPECT_EQ(list.size(), currentsize + 1);
}