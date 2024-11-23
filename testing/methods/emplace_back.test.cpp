#include <gtest/gtest.h>
#include "resource.helper.h"
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"

TEST(emplace_back, should_insert_sucesfully_at_end)
{
	int new_value = 4;
	intlist expected_list = {1,2,3,new_value };

	intlist list = { 1,2,3 };

	ASSERT_NO_FATAL_FAILURE(list.emplace_back(std::move(new_value)));
	EXPECT_TRUE(compare_list(expected_list, list));
}

TEST_F(test_resource_list, emplace_back_should_not_copy)
{
	// constructs a test_resource(100)
	test_list.emplace_back(100);
	EXPECT_EQ(test_resource::instances_created, 1);
}

TEST(emplace_back, should_update_nelms)
{
	intlist list{ 1,2,3 };
	const std::size_t current_size = list.size();
	list.emplace_back(4);
	EXPECT_EQ(list.size(), current_size + 1);
}