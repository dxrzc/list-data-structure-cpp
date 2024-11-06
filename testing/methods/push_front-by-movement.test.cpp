#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "resource.helper.h"

TEST(push_front_by_mov, should_push_front)
{
	int newvalue = 4;
	intlist testlist{ 1,2,3 };
	testlist.push_front(std::move(newvalue));
	EXPECT_EQ(testlist.front(), newvalue);
}

TEST_F(test_resource_list, push_front_by_mov_should_not_copy_but_move)
{
	test_resource resource;
	test_list.push_front(std::move(resource));
	EXPECT_EQ(test_resource::instances_created, 1);
	EXPECT_EQ(test_resource::movement_constructor, 1);
}

TEST(push_front_by_mov, should_update_nelms)
{
	intlist list{ 1,2,3 };
	const std::size_t current_size = list.size();
	list.push_front(std::move(4));
	EXPECT_EQ(list.size(), current_size + 1);
}
