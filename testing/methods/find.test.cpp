#include <gtest/gtest.h>
#include "list.h"
#include "intlist.typealias.helper.h"

TEST(find, should_return_iterator_to_value)
{
	const int number_to_find = 4;
	intlist list{ 1,2,3,number_to_find,5 };
	intlist::iterator it = list.find(number_to_find);
	EXPECT_EQ(*it, number_to_find);
}

TEST(find, should_return_iterator_to_end_if_value_not_found)
{
	const int number_to_find = 4;
	intlist list{ 1,2,3 };
	intlist::iterator it = list.find(number_to_find);
	EXPECT_EQ(it, list.end());
}

TEST(find, should_not_cause_fatal_failure_on_empty_list)
{	
	intlist list;
	EXPECT_NO_FATAL_FAILURE(list.find(100));
}