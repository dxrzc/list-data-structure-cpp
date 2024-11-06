#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"

TEST(clear, should_clear_the_list_succesfully)
{
	intlist list{ 1,2,3,4,5 };
	ASSERT_NO_THROW(list.clear());
	EXPECT_TRUE(list.empty());
}

TEST(clear, should_not_throw_an_error_if_clear_is_called_two_times)
{
	intlist list{ 1,2,3 };
	ASSERT_NO_THROW(list.clear());
	ASSERT_NO_THROW(list.clear());
	EXPECT_TRUE(true);
}

TEST(clear, nelms_should_be_zero_after_call)
{
	intlist list{ 1, 2, 3 };
	list.clear();
	EXPECT_EQ(list.size(), 0);
}

TEST(clear, should_not_throw_error_if_list_empty)
{
	intlist list;
	ASSERT_NO_THROW(list.clear());
}

TEST(clear, should_be_able_to_add_elements_after_call)
{
	intlist list{ 1, 2, 3 };
	list.clear();
	ASSERT_NO_THROW(list.push_back(0));
	ASSERT_NO_THROW(list.push_back(1));
	ASSERT_NO_THROW(list.push_back(0));
	EXPECT_TRUE(compare_list(list, { 0, 1, 0 }));
}