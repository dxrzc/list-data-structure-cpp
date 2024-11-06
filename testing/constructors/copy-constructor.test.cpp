#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"

TEST(copy_constructor, should_copy_successfully)
{
	intlist list{ 1,2,3 };
	auto new_list(list);
	EXPECT_TRUE(compare_list(list, new_list));
}

TEST(copy_constructor, should_update_nelms)
{
	intlist list{ 1, 2, 3, 4, 5 };	
	intlist list2 = list;
	EXPECT_EQ(list.size(), list2.size());
}