#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"
#include "../helpers/resource.helper.h"

TEST(emplace_front, should_insert_sucessfully)
{
	const int new_value = 5;
	intlist list{ 1,2,3 };
	list.emplace_front(new_value);
	EXPECT_EQ(list.front(), new_value);
}

TEST_F(test_resource_list, emplace_front_should_not_copy)
{
	// constructs a test_resource(100)
	test_list.emplace_front(100);
	EXPECT_EQ(test_resource::instances_created, 1);
}

TEST(emplace_front, should_update_nelms)
{
	intlist list{ 1,2,3 };
	const std::size_t current_size = list.size();
	list.emplace_front(1);
	EXPECT_EQ(list.size(), current_size + 1);
}