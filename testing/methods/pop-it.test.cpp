#include <gtest/gtest.h>
#include "../helpers/intlist.typealias.helper.h"

TEST(popUsingIterator, shouldDeleteTheElementAtIterator)
{
	intlist list{ 1, 2, 3 };
	list.pop(list.begin());
	EXPECT_EQ(list.front(), 2);
}

TEST(popUsingIterator, shouldReturnIteratorToNextElement)
{
	intlist list{ 1, 2, 3 };
	auto it = list.begin();
	auto nextElement = list.pop(it);
	EXPECT_EQ(*nextElement, 2);
}

TEST(popUsingIterator, shouldDecrementNelms)
{
	intlist list{ 1, 2, 3 };
	list.pop(list.begin());
	EXPECT_EQ(list.size(), 2);
}

TEST(popUsingIterator, shouldThrowLengthErrorIfListEmpty)
{
	intlist list;
	EXPECT_THROW(list.pop(list.begin()), std::length_error);
}

TEST(popUsingIterator, shouldThrowExceptionIfIteratorPointsToHead)
{
	intlist list{ 1, 2 };
	auto it = list.end();
	EXPECT_THROW(list.pop(it), std::runtime_error);
}