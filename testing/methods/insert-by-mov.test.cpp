#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "resource.helper.h"

TEST(insert_by_movement, should_insert_successfully)
{
	int new_value = 100;
	intlist list{ 1,2,3 };
	list.insert(list.begin(), std::move(new_value));
	EXPECT_EQ(list.front(), new_value);
}

TEST_F(test_resource_list, insert_by_mov_should_not_copy)
{
	test_resource res;
	test_list.insert(test_list.end(), std::move(res));
	EXPECT_EQ(test_resource::instances_created, 1);
}

TEST(insert_by_movement, should_update_nelms)
{
	intlist list{ 1,2,3 };
	const std::size_t current_size = list.size();
	list.insert(list.end(), 10);
	EXPECT_EQ(list.size(), current_size + 1);
}