#include "intlist.typealias.helper.h"
#include "resource.helper.h"
#include <gtest/gtest.h>
#include "list.h"

TEST(mov_assigment_operator, auto_assigment_no_errors)
{
	intlist list{ 1,2,3 };
	const std::size_t current_size = list.size();
	list = std::move(list);
	EXPECT_EQ(list.size(), current_size);
}

TEST(mov_assigment_operator, empy_rhs_list_after_operation)
{
	intlist l{ 1,2,3 };
	intlist rhs{ 1,2,3,4,5 };
	l = std::move(rhs);
	EXPECT_TRUE(rhs.empty());
}

TEST_F(constructor_operations_test, mov_assigm_op_should_clear_existing_elements)
{
	list<test_resource> test_resource_list;	
	test_resource_list.emplace_back(1);
	test_resource_list.emplace_back(2);

	list<test_resource> new_resource_list;
	test_resource_list = std::move(new_resource_list);

	EXPECT_EQ(test_resource::destructor_calls, 2);
}
