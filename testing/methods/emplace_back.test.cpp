#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"
#include "../helpers/resource.helper.h"

TEST(emplace_back, should_insert_succesfully)
{
	const int newvalue = 4;
	intlist testlist{ 1,2,3 };
	testlist.emplace_back(newvalue);
	EXPECT_EQ(testlist.back(), newvalue);
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