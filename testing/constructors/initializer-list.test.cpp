#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"
#include "resource.helper.h"

TEST(initializer_list_constructor, should_construct_list_successfully)
{
	intlist list{ 1, 2, 3, 4, 5 };
	EXPECT_TRUE(compare_list(list, intlist{ 1,2,3,4,5 }));
}