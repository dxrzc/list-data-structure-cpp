#include <gtest/gtest.h>
#include "list.h"
#include "../helpers/intlist.typealias.helper.h"
#include "../helpers/compare-list.helper.h"

TEST(for_each, shouldforEachSuccefully)
{
	intlist list{ 1,2,3 };
	for (int& i : list)
		i = 0;
	EXPECT_TRUE(compareList(list, intlist({ 0,0,0 })));
}

TEST(for_each, shouldForEachOnConstList)
{
	const intlist list{ 1,2,3 };
	intlist aux;
	for (int i : list)
		aux.push_back(i);
	EXPECT_TRUE(compareList(aux, list));
}