#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"
#include "resource.helper.h"

TEST(emplace_by_iterator, should_insert_succesfully_at_begin)
{
	const int new_value = 0;
	intlist expected_list{ new_value, 1,2,3 };

	intlist list{ 1,2,3 };	

	ASSERT_NO_FATAL_FAILURE(list.emplace(list.begin(), new_value));
	EXPECT_TRUE(compare_list(list, expected_list));
}

TEST(emplace_by_iterator, should_insert_sucesfully_at_end)
{
	const int new_value = 4;
	intlist expected_list{ 1,2,3,4 };

	intlist list{ 1,2,3 };

	ASSERT_NO_FATAL_FAILURE(list.emplace(list.end(), new_value));
	EXPECT_TRUE(compare_list(list, expected_list));
}

TEST(emplace_by_iterator, should_insert_sucesfully_at_random_pos)
{
	const int new_value = 3;
	intlist expected_list{ 1,2,new_value,4,5 };

	intlist list{ 1,2,4,5 };
	intlist::iterator it = list.begin();
	std::advance(it, 2);

	ASSERT_NO_FATAL_FAILURE(list.emplace(it, new_value));
	EXPECT_TRUE(compare_list(list, expected_list));
}

TEST_F(constructor_operations_test, emplace_by_iterator_should_not_copy)
{
	list<test_resource> test_resource_list;

	test_resource_list.emplace(test_resource_list.end(), test_resource());

	EXPECT_EQ(test_resource::instances_created, 1);
}

TEST(emplace_by_iterator, should_return_iterator_to_new_value)
{
	intlist list{ 1,2,3 };
	const int new_value = 101;
	auto new_value_it = list.emplace(list.begin(), new_value);
	EXPECT_EQ(*new_value_it, new_value);
}

TEST(emplace_by_iterator, should_update_nelms)
{
	intlist list{ 1,2,3 };
	const std::size_t current_size = list.size();
	list.emplace(list.end(), 10);
	EXPECT_EQ(list.size(), current_size + 1);
}