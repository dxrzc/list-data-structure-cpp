#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"
#include "resource.helper.h"

TEST(initializer_list_constructor, should_construct_list_successfully)
{
	intlist list{ 1, 2, 3, 4, 5 };
	EXPECT_TRUE(compare_list(list, intlist{ 1,2,3,4,5 }));
}

TEST_F(test_resource_list, initializer_of_rvalues_should_not_copy)
{
	test_resource res1;
	test_resource res2;
	list<test_resource> list{ std::move(res1), std::move(res2) };

	EXPECT_EQ(test_resource::instances_created, 2);
	EXPECT_EQ(test_resource::movement_constructor, 2);
}
