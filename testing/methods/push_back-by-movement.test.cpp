#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"
#include "resource.helper.h"

TEST(push_back_by_mov, should_push_at_end)
{
	int new_value = 4;
	intlist expected_list{ 1,2,3,new_value };

	intlist list{ 1,2,3 };

	ASSERT_NO_FATAL_FAILURE(list.push_back(std::move(new_value)));
	EXPECT_TRUE(compare_list(expected_list, list));
}

TEST_F(test_resource_list, push_back_by_mov_should_not_copy)
{
	test_resource resource;
	list<test_resource> test_resource_list;

	test_resource_list.push_back(std::move(resource));
	EXPECT_EQ(test_resource::instances_created, 1);
	EXPECT_EQ(test_resource::movement_constructor, 1);
}

TEST(push_back_by_mov, should_update_nelms)
{
	intlist list{ 1,2,3 };
	const std::size_t current_size = list.size();
	list.push_back(std::move(4));
	EXPECT_EQ(list.size(), current_size + 1);
}
