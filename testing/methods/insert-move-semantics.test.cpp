#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"
#include "resource.helper.h"

TEST(insert_mov_semantics, should_insert_succesfully_at_begin)
{
	int new_value = 0;
	intlist expected_list = { new_value ,1,2,3 };

	intlist list{ 1,2,3 };

	ASSERT_NO_FATAL_FAILURE(list.insert(list.begin(), std::move(new_value)));
	EXPECT_TRUE(compare_list(list, expected_list));
}

TEST(insert_mov_semantics, should_insert_succesfully_at_end)
{
	int new_value = 4;
	intlist expected_list = { 1,2,3, new_value };

	intlist list{ 1,2,3 };

	ASSERT_NO_FATAL_FAILURE(list.insert(list.end(), std::move(new_value)));
	EXPECT_TRUE(compare_list(list, expected_list));
}

TEST(insert_mov_semantics, should_insert_succesfully_at_random_pos)
{
	int new_value = 100;
	intlist expected_list = { 1,2,100,3 };

	intlist list{ 1,2,3 };
	intlist::iterator it = list.begin();
	std::advance(it, 2);

	ASSERT_NO_FATAL_FAILURE(list.insert(it, std::move(new_value)));
	EXPECT_TRUE(compare_list(list, expected_list));
}

TEST_F(constructor_operations_test, insert_mov_semantics_should_not_copy)
{
	list<test_resource> test_resource_list;
	test_resource res;

	test_resource_list.insert(test_resource_list.end(), std::move(res));

	EXPECT_EQ(test_resource::instances_created, 1);
}

TEST(insert_mov_semantics, should_update_nelms)
{
	intlist list{ 1,2,3 };
	const std::size_t current_size = list.size();
	list.insert(list.end(), 10);
	EXPECT_EQ(list.size(), current_size + 1);
}