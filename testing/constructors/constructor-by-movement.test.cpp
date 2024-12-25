#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "resource.helper.h"

TEST_F(test_resource_list, constructor_by_mov_should_not_copy)
{	
	list<test_resource> test_resource_list;
	// rvalue forwarding makes no copies
	test_resource_list.push_back(test_resource());
	test_resource_list.push_back(test_resource());
	test_resource_list.push_back(test_resource());

	list<test_resource> tested_list(std::move(test_resource_list));

	EXPECT_EQ(test_resource::copy_constructor, 0);
	EXPECT_EQ(test_resource::instances_created, 3);
}

TEST(constructor_by_mov, rhs_list_should_be_empty)
{
	intlist test_list{ 1,2,3 };
	intlist tested_list (std::move(test_list));

	EXPECT_TRUE(test_list.empty());
}

TEST(constructor_by_mov, should_update_nelms)
{
	intlist list{ 1,2,3 };
	const std::size_t list_current_size = list.size();

	intlist list2 = std::move(list);;

	EXPECT_EQ(list.size(), 0);
	EXPECT_EQ(list2.size(), list_current_size);
}