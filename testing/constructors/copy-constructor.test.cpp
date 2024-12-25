#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"

TEST(copy_constructor, should_copy_successfully)
{
	intlist list{ 1,2,3 };
	intlist test_list(list);

	EXPECT_TRUE(compare_list(test_list, list));
}

TEST(copy_constructor, should_update_nelms)
{
	intlist list{ 1,2,3 };
	intlist test_list(list);

	EXPECT_EQ(list.size(), test_list.size());
}

TEST(copy_constructor, should_not_make_changes_on_rhs_list)
{
	intlist list{ 1,2,3 };
	intlist test_list(list);

	EXPECT_TRUE(compare_list(list, intlist{ 1,2,3 }));
}