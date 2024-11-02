#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"

TEST(const_reverse_iterator, crbeginShouldReturnIteratorToLastElement)
{
	const int target = 3;
	intlist list{ 1,2,target };
	intlist::const_reverse_iterator crevit = list.crbegin();
	EXPECT_EQ(target, *crevit);
}

TEST(const_reverse_iterator, crendShouldReturnIteratorToHead)
{
	intlist list;
	EXPECT_ANY_THROW(*(list.crend()));
}

TEST(const_reverse_iterator, preIncrementOperator)
{
	intlist list{ 1,2,3 };
	auto crevit = list.crbegin();
	EXPECT_EQ(*(++crevit), 2);
	EXPECT_EQ(*(++crevit), 1);
}

TEST(const_reverse_iterator, postIncrementOperator)
{
	intlist list{ 1,2,3 };
	auto crevit = list.crbegin();
	EXPECT_EQ(*(crevit++), 3);
	EXPECT_EQ(*(crevit++), 2);
	EXPECT_EQ(*(crevit++), 1);
}

TEST(const_reverse_iterator, preDecrementOperator)
{
	intlist list{ 1,2,3 };
	auto crevit = list.crend();
	EXPECT_EQ(*(--crevit), 1);
	EXPECT_EQ(*(--crevit), 2);
	EXPECT_EQ(*(--crevit), 3);
}

TEST(const_reverse_iterator, postDecrementOperator)
{
	intlist list{ 1,2,3 };
	auto crevit = list.crend();
	crevit--;
	EXPECT_EQ(*(crevit--), 1);
	EXPECT_EQ(*(crevit--), 2);
	EXPECT_EQ(*(crevit--), 3);
}


TEST(const_reverse_iterator, shouldThrowExceptionIfTriesToGetHeadValue)
{
	intlist list;
	auto crevit = list.rend();
	EXPECT_ANY_THROW(*crevit);
}

TEST(const_reverse_iterator, shouldBeAbleToUseStdAdvance)
{
	const int target = 100;
	intlist list{ target,2,3 };
	auto crevit = list.crbegin();
	std::advance(crevit, 2);
	EXPECT_EQ(*crevit, target);
}

TEST(const_reverse_iterator, equalityOperator)
{
	const int target = 100;
	intlist list{ 1,2,target };
	auto crevit1 = list.crbegin();
	auto crevit2 = list.crbegin();
	EXPECT_TRUE(crevit1 == crevit2);
}

TEST(const_reverse_iterator, inequalityOperator)
{
	const int target = 100;
	intlist list{ 1,2,target };
	auto crevit1 = list.crbegin();
	auto crevit2 = list.crbegin();
	++crevit2;
	EXPECT_TRUE(crevit1 != crevit2);
}

TEST(const_reverse_iterator, copyConstructor)
{
	intlist list{ 1,2,3 };
	intlist::const_reverse_iterator crevit = list.crbegin();
	intlist::const_reverse_iterator crevit2 = crevit;
	EXPECT_TRUE(crevit == crevit2);
}

TEST(const_reverse_iterator, equalOperator)
{
	intlist list{ 1,2,3 };
	auto crevit1 = list.crbegin();
	auto crevit2 = list.crbegin();
	++crevit1;
	crevit2 = crevit1;
	EXPECT_TRUE(crevit2 == crevit1);
}

TEST(const_reverse_iterator, desreferenceShouldReturnTheCorrectValue)
{
	const int target = 3;
	intlist list{ 1,2,target };
	auto crevit = list.crbegin();
	EXPECT_EQ(*crevit, target);
}

TEST(const_reverse_iterator, shouldBeConstructedUsingAnIterator)
{
	intlist list{ 1,2,3 };
	auto it = list.begin();
	intlist::const_reverse_iterator crevit = it;
	EXPECT_EQ(*crevit, *it);
}

TEST(const_reverse_iterator, shouldBeConstructedUsingAConstIterator)
{
	intlist list{ 1,2,3 };
	auto it = list.cbegin();
	intlist::const_reverse_iterator crevit = it;
	EXPECT_EQ(*crevit, *it);
}

TEST(const_reverse_iterator, shouldBeConstructedUsingAReverseIterator)
{
	intlist list{ 1,2,3 };
	auto it = list.rbegin();
	intlist::const_reverse_iterator crevit = it;
	EXPECT_EQ(*crevit, *it);
}

TEST(const_reverse_iterator, equalityOperatorWithIterator)
{
	intlist list{ 1,2,3 };
	intlist::const_reverse_iterator crevit = list.crbegin();
	intlist::iterator it = --(list.end());
	EXPECT_TRUE(crevit == it);
}

TEST(const_reverse_iterator, equalityOperatorWithConstIterator)
{
	intlist list{ 1,2,3 };
	intlist::const_reverse_iterator crevit = list.crbegin();
	intlist::const_iterator cit = --(list.cend());
	EXPECT_TRUE(crevit == cit);
}

TEST(const_reverse_iterator, equalityOperatorWithReverseIterator)
{
	intlist list{ 1,2,3 };
	intlist::const_reverse_iterator crevit = list.crbegin();
	intlist::reverse_iterator revit = list.rbegin();
	EXPECT_TRUE(crevit == revit);
}