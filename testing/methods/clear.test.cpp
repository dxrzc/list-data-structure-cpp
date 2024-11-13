#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"

TEST(clear, should_clear_the_list_succesfully)
{
	intlist list{ 1,2,3,4,5 };
	ASSERT_NO_THROW(list.clear());
	EXPECT_TRUE(list.empty());
}

TEST(clear, should_not_cause_fatal_failure_if_its_called_two_times)
{
	intlist list{ 1,2,3 };
	list.clear();
	EXPECT_NO_FATAL_FAILURE(list.clear());	
}

TEST(clear, nelms_should_be_zero_after_call)
{
	intlist list{ 1, 2, 3 };
	list.clear();
	EXPECT_EQ(list.size(), 0);
}

TEST(clear, should_not_cause_fatal_failure_on_empty_list)
{
	intlist list;
	EXPECT_NO_FATAL_FAILURE(list.clear());
}

TEST(clear, should_be_able_to_add_elements_after_call)
{
	intlist list{ 1, 2, 3 };
	list.clear();
	EXPECT_NO_FATAL_FAILURE(list.push_back(0));
	EXPECT_NO_FATAL_FAILURE(list.push_back(1));
	EXPECT_NO_FATAL_FAILURE(list.push_back(0));
	EXPECT_TRUE(compare_list(list, { 0, 1, 0 }));
}