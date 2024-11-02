#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"

TEST(iterator, beginShouldReturnIteratorToBegin)
{
	const int begin = 1;
	intlist list{ begin,2,3 };
	EXPECT_EQ(*(list.begin()), begin);
}

TEST(iterator, endShouldReturnIteratorToEnd)
{
	intlist list{ 1,2,3 };
	EXPECT_ANY_THROW(*(list.end()));
}

TEST(iterator, preincrementOperator)
{
	intlist list{ 1, 2, 3 };
	auto it = list.begin();
	EXPECT_EQ(*(++it), 2);
	EXPECT_EQ(*(++it), 3);
}

TEST(iterator, postincrementOperator)
{
	intlist list{ 1, 2, 3 };
	auto it = list.begin();
	EXPECT_EQ(*(it++), 1);
	EXPECT_EQ(*(it++), 2);
	EXPECT_EQ(*(it++), 3);
}

TEST(iterator, predecrementOperator)
{
	intlist list{ 1, 2, 3 };
	auto it = list.end();
	EXPECT_EQ(*(--it), 3);
	EXPECT_EQ(*(--it), 2);
}

TEST(iterator, postdecrementOperator)
{
	intlist list{ 1,2,3 };
	auto it = list.end();
	it--;
	EXPECT_EQ(*(it--), 3);
	EXPECT_EQ(*(it--), 2);
	EXPECT_EQ(*(it--), 1);
}

TEST(iterator, shouldThrowExceptionIfTriesToGetHeadValue)
{
	intlist list;
	auto it = list.end();
	EXPECT_THROW(*it, std::runtime_error);
}

TEST(iterator, shouldBeAbleToUseStdAdvance)
{
	intlist list{ 1, 2, 3 };
	auto it = list.begin();
	std::advance(it, 2);
	EXPECT_EQ(*it, 3);
}

TEST(iterator, equalityOperator)
{
	intlist list{ 1, 2, 3 };
	auto it1 = list.begin();
	auto it2 = list.begin();
	EXPECT_TRUE(it1 == it2);
}

TEST(iterator, inequalityOperator)
{
	intlist list{ 1, 2, 3 };
	auto it1 = list.begin();
	auto it2 = list.begin();
	++it2;
	EXPECT_FALSE(it1 == it2);
}

TEST(iterator, copyConstructor)
{
	intlist list{ 1, 2, 3, 4, 5 };
	auto it1 = list.begin();
	std::advance(it1, 2);
	auto it2 = it1;
	EXPECT_EQ(*it1, *it2);
}

TEST(iterator, equalOperator)
{
	intlist list{ 1, 2, 3, 4, 5 };
	auto it1 = list.begin();
	std::advance(it1, 2);
	auto it2 = list.begin();
	it2 = it1;
	EXPECT_EQ(*it1, *it2);
}

TEST(iterator, desreferenceShouldReturnTheCorrectValue)
{
	const int expected = 1;
	intlist list{ expected, 2, 3 };
	auto it = list.begin();
	EXPECT_EQ(*it, expected);
}