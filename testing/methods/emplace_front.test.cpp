#include <gtest/gtest.h>
#include "resource.helper.h"
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"

TEST(emplace_front, should_insert_sucesfully_at_begin)
{
	int new_value = 0;
	intlist expected_list{ new_value,1,2,3 };

	intlist list{ 1,2,3 };

	ASSERT_NO_FATAL_FAILURE(list.emplace_front(std::move(new_value)));
	EXPECT_TRUE(compare_list(expected_list, list));
}

TEST_F(test_resource_list, emplace_front_should_not_copy)
{
	list<test_resource> test_resource_list;

	test_resource_list.emplace_front(100);

	EXPECT_EQ(test_resource::instances_created, 1);
}

TEST(emplace_front, should_update_nelms)
{
	intlist list{ 1,2,3 };
	const std::size_t current_size = list.size();
	list.emplace_front(1);
	EXPECT_EQ(list.size(), current_size + 1);
}