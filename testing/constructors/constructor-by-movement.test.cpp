#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"
#include "../helpers/resource.helper.h"

TEST(constructorByMovement, shouldUpdateNelms)
{
	intlist list{ 1,2,3 };
	intlist list2 = std::move(list);
	EXPECT_EQ(list.size(), 0);
	EXPECT_EQ(list2.size(), 3);
}

TEST_F(test_resource_list, constructorByMovementshouldNotMakeCopies)
{
	test_list.emplace_back(test_resource());
	test_list.emplace_back(test_resource());
	test_list.emplace_back(test_resource());

	list<test_resource> resource_list = std::move(test_list);

	EXPECT_EQ(test_resource::copy_constructor, 0);
}