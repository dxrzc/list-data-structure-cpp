#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"

TEST(reverse_iterator, rbeginShouldReturnIteratorToLastElement)
{
	const int revbegin = 3;
	intlist list{ 1,2, revbegin };
	EXPECT_EQ(*(list.rbegin()), revbegin);
}

TEST(reverse_iterator, rendShouldReturnIteratorToHead)
{
	intlist list{ 1,2,3 };
	EXPECT_ANY_THROW(*(list.rend()));
}

TEST(reverse_iterator, preIncrementOperator)
{
	intlist list{ 1,2,3 };
	auto revit = list.rbegin();
	EXPECT_EQ(*(++revit), 2);
	EXPECT_EQ(*(++revit), 1);
}

TEST(reverse_iterator, postIncrementOperator)
{
	intlist list{ 1,2,3 };
	auto revit = list.rbegin();
	EXPECT_EQ(*(revit++), 3);
	EXPECT_EQ(*(revit++), 2);
	EXPECT_EQ(*(revit++), 1);
}

TEST(reverse_iterator, preDecrementOperator)
{
	intlist list{ 1,2,3 };
	auto revit = list.rend();
	EXPECT_EQ(*(--revit), 1);
	EXPECT_EQ(*(--revit), 2);
	EXPECT_EQ(*(--revit), 3);
}

TEST(reverse_iterator, postDecrementOperator)
{
	intlist list{ 1,2,3 };
	auto revit = list.rend();
	revit--;
	EXPECT_EQ(*(revit--), 1);
	EXPECT_EQ(*(revit--), 2);
	EXPECT_EQ(*(revit--), 3);
}

TEST(reverse_iterator, shouldThrowExceptionIfTriesToGetHeadValue)
{
	intlist list;
	auto revit = list.rend();
	EXPECT_ANY_THROW(*revit);
}

TEST(reverse_iterator, shouldBeAbleToUseStdAdvance)
{
	const int target = 100;
	intlist list{ target,2,3 };
	auto revit = list.rbegin();
	std::advance(revit, 2);
	EXPECT_EQ(*revit, target);
}

TEST(reverse_iterator, equalityOperator)
{
	const int target = 100;
	intlist list{ 1,2,target };
	auto revit1 = list.rbegin();
	auto revit2 = list.rbegin();
	EXPECT_TRUE(revit1 == revit2);
}

TEST(reverse_iterator, inequalityOperator)
{
	const int target = 100;
	intlist list{ 1,2,target };
	auto revit1 = list.rbegin();
	auto revit2 = list.rbegin();
	++revit2;
	EXPECT_TRUE(revit1 != revit2);
}

TEST(reverse_iterator, copyConstructor)
{
	intlist list{ 1,2,3 };
	intlist::reverse_iterator revit = list.rbegin();
	intlist::reverse_iterator revit2 = revit;
	EXPECT_TRUE(revit == revit2);
}

TEST(reverse_iterator, equalOperator)
{
	intlist list{ 1,2,3 };
	auto revit1 = list.rbegin();
	auto revit2 = list.rbegin();
	++revit1;
	revit2 = revit1;
	EXPECT_TRUE(revit2 == revit1);
}

TEST(reverse_iterator, desreferenceShouldReturnTheCorrectValue)
{
	const int target = 3;
	intlist list{ 1,2,target };
	auto revit = list.rbegin();
	EXPECT_EQ(*revit, target);
}

TEST(reverse_iterator, shouldBeConstructedUsingAnIterator)
{
	intlist list{ 1,2,3 };
	auto it = list.begin();
	intlist::reverse_iterator revit = it;
	EXPECT_EQ(*revit, *it);
}

TEST(reverse_iterator, equalityOperatorWithIterator)
{
	intlist list{ 1,2,3 };
	intlist::reverse_iterator revit = list.rbegin();
	intlist::iterator it = --(list.end());
	EXPECT_TRUE(revit == it);
}