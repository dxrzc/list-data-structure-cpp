#include <gtest/gtest.h>
#include <array>
#include "list.h"
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"
#include "resource.helper.h"

TEST(assigment_operator, should_create_and_assign)
{
	intlist list{ 1, 2, 3 };
	intlist newlist{ 3, 2, 1 };
	newlist = list;
	EXPECT_TRUE(compare_list(newlist, list));
}

TEST_F(constructor_operations_test, assigment_operator_should_delete_its_elements_before_assign)
{
	list<test_resource> test_resource_list;

	// constructs two test_resources with no copies 
	test_resource_list.emplace_back(1);
	test_resource_list.emplace_back(2);
	
	const list<test_resource> new_resource_list; 
	test_resource_list = new_resource_list;

	EXPECT_EQ(test_resource::destructor_calls, 2);
}

TEST(assigment_operator, should_work_successfully_if_is_used_with_itself)
{
	intlist list{ 1,2,3 };
	const std::size_t current_size = list.size();
	list = list;
	EXPECT_EQ(list.size(), current_size);
}