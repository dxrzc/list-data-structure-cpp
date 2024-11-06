#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"

TEST(size, should_retunr_the_size_successfully_when_list_not_empty)
{
	intlist list;
	list.push_back(1);
	list.push_back(1);
	list.push_back(1);
	EXPECT_EQ(list.size(), 3);
}

TEST(size, should_return_0_if_list_empty)
{
	intlist empty_list;
	EXPECT_EQ(empty_list.size(), 0);
}
