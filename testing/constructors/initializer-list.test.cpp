#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"

TEST(initializerListConstructor, shouldConstructTheList)
{
	intlist list{ 1, 2, 3, 4, 5 };
	EXPECT_EQ(list.size(), 5);
}
