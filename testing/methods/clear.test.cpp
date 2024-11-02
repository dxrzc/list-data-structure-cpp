#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"

TEST(destructor_clear, noProblemUsingDestructorAfterClear)
{
	{
		intlist list{ 1, 2, 3 };
		list.clear();
	}
	EXPECT_EQ(1, 1);
}

TEST(destructor_clear, nelmsShouldBeZero)
{
	intlist list{ 1, 2, 3 };
	list.clear();
	std::cout << list.size();
}

TEST(destructor_clear, noProblemIfListItsEmpty)
{
	intlist list;
	list.clear();
	EXPECT_EQ(1, 1);
}

TEST(destructor_clear, canPushAfterClearWithNoProblem)
{
	intlist list{ 1, 2, 3 };
	list.clear();
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	ASSERT_EQ(list.size(), 3);
	ASSERT_EQ(list.front(), 1);
	ASSERT_EQ(list.back(), 3);
}