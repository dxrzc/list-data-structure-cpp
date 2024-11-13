#include <gtest/gtest.h>
#include "list.h"
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"

TEST(splice, should_splice_succefully)
{
	intlist list{ 1,2,3 };
	intlist spliced_list{ 9,8,7 };

	auto begin = list.begin();
	list.splice(begin, spliced_list);

	EXPECT_TRUE(compare_list(list, intlist{ 1,9,8,7,2,3 }));
}

TEST(splice, should_update_nelms_in_both_lists)
{
	intlist list{ 1,2,3 };
	const std::size_t list_current_size = list.size();

	intlist spliced_list{ 9,8,7 };
	const std::size_t spliced_list_size = spliced_list.size();
	
	list.splice(list.begin(), spliced_list);

	EXPECT_EQ(list.size(), list_current_size + spliced_list_size);
	EXPECT_EQ(spliced_list.size(), 0);
}

TEST(splice, should_not_cause_fatal_failure_if_rhs_is_empty)
{
	intlist list{ 1,2,3 };
	intlist empty;

	EXPECT_NO_FATAL_FAILURE(list.splice(list.begin(), empty));	
}

TEST(splice, should_not_cause_fatal_failure_if_current_list_empty)
{
	intlist list;
	intlist new_list{ 1,2,3 };

	EXPECT_NO_FATAL_FAILURE(list.splice(list.begin(), new_list));	
}