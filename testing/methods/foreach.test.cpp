#include <gtest/gtest.h>
#include "list.h"
#include "intlist.typealias.helper.h"
#include "compare-list.helper.h"

TEST(for_each, should_work_successfully)
{
	const int new_value = 0;
	intlist list{ 1,2,3 };
	for (int& i : list)
		i = new_value;
	EXPECT_TRUE(compare_list(list, intlist({ new_value,new_value,new_value })));
}

TEST(for_each, should_work_successfully_on_const_list)
{
	const intlist list{ 1,2,3 };
	intlist aux;
	for (int i : list)
		aux.push_back(i);
	EXPECT_TRUE(compare_list(aux, list));
}