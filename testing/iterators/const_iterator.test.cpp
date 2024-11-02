#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"

TEST(const_iterator, cbeginShouldReturnIteratorToBegin)
{
	const int begin = 1;
	intlist list{ begin,2,3 };
	EXPECT_EQ(*(list.cbegin()), begin);
}

TEST(const_iterator, cendShouldReturnIteratorToEnd)
{
	intlist list{ 1,2,3 };
	EXPECT_ANY_THROW(*(list.cend()));
}

TEST(const_iterator, preIncrementOperator)
{
	intlist list{ 1,2,3 };
	auto cit = list.cend();
	EXPECT_EQ(*(++cit), 1);
	EXPECT_EQ(*(++cit), 2);
	EXPECT_EQ(*(++cit), 3);
}

TEST(const_iterator, postincrementOperator)
{
	intlist list{ 1,2,3 };
	auto cit = list.cbegin();
	EXPECT_EQ(*(cit++), 1);
	EXPECT_EQ(*(cit++), 2);
	EXPECT_EQ(*(cit++), 3);
}

TEST(const_iterator, preDecrementIterator)
{
	intlist list{ 1,2,3 };
	auto cit = list.cend();
	EXPECT_EQ(*(--cit), 3);
	EXPECT_EQ(*(--cit), 2);
	EXPECT_EQ(*(--cit), 1);
}

TEST(const_iterator, postDecrementIterator)
{
	intlist list{ 1,2,3 };
	auto cit = list.cend();
	cit--;
	EXPECT_EQ(*(cit--), 3);
	EXPECT_EQ(*(cit--), 2);
	EXPECT_EQ(*(cit--), 1);
}

TEST(const_iterator, shouldThrowExceptionIfTriesToGetHeadValue)
{
	intlist list;
	auto head = list.cbegin();
	EXPECT_THROW(*head, std::runtime_error);
}

TEST(const_iterator, shouldBeAbleToUseStdAdvance)
{
	intlist list{ 1,2,3 };
	auto it = list.cbegin();
	std::advance(it, 1);
	EXPECT_EQ(*it, 2);
	std::advance(it, 1);
	EXPECT_EQ(*it, 3);
}

TEST(const_iterator, equalityOperator)
{
	intlist list{ 1,2,3 };
	auto it1 = list.cbegin();
	auto it2 = list.cbegin();
	EXPECT_TRUE(it1 == it2);
}

TEST(const_iterator, inequalityOperator)
{
	intlist list{ 1,2,3 };
	auto it1 = list.cbegin();
	auto it2 = list.cbegin();
	std::advance(it2, 1);
	EXPECT_TRUE(it1 != it2);
}

TEST(const_iterator, copyConstructor)
{
	intlist list{ 1,2,3 };
	auto it1 = list.cbegin();
	intlist::const_iterator it2 = it1;
	EXPECT_TRUE(it2 == it1);
}

TEST(const_iterator, equalOperator)
{
	intlist list{ 1,2,3 };
	auto it1 = list.cbegin();
	auto it2 = list.cbegin();
	std::advance(it1, 2);
	it2 = it1;
	EXPECT_TRUE(it2 == it1);
}

TEST(const_iterator, desreferenceShouldReturnTheCorrectValue)
{
	intlist list{ 1,2,3 };
	auto it = list.cbegin();
	std::advance(it, 2);
	EXPECT_EQ(*it, 3);
}

TEST(const_iterator, shouldBeConstructedUsingAnIterator)
{
	intlist list{ 1,2,3 };
	intlist::iterator normalIterator = list.begin();
	intlist::const_iterator constIterator = normalIterator;
	EXPECT_EQ(*constIterator, *normalIterator);
}

TEST(const_iterator, equalityOperatorWithIterator)
{
	intlist list{ 1,2,3 };
	auto normalIterator = list.begin();
	auto constIterator = list.cbegin();
	EXPECT_TRUE(normalIterator == constIterator);
}