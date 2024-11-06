#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "resource.helper.h"

TEST(emplace_by_iterator, should_insert_successfully)
{
	const int new_value = 100;
	intlist list{ 1,2,3 };
	list.emplace(list.begin(), new_value);
	EXPECT_EQ(list.front(), new_value);
}

TEST_F(test_resource_list, emplace_by_iterator_should_not_copy)
{
	test_list.emplace(test_list.end(), test_resource());
	EXPECT_EQ(test_resource::instances_created, 1);
}

TEST(emplace_by_iterator, should_update_nelms)
{
	intlist list{ 1,2,3 };
	list.emplace(list.end(), 10);
	EXPECT_EQ(list.size(), 4);
}