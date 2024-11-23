#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"
#include "resource.helper.h"

TEST(push_front_by_mov, should_push_at_begin)
{
	int new_value = 0;
	intlist expected_list{ new_value,1,2,3 };

	intlist testlist{ 1,2,3 };

	ASSERT_NO_FATAL_FAILURE(testlist.push_front(std::move(new_value)));
	EXPECT_TRUE(compare_list(testlist, expected_list));
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
