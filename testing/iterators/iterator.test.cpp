#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"

TEST(iterator, begin_should_return_iterator_to_begin)
{
    const int begin = 1;
    intlist list{ begin, 2, 3 };
    EXPECT_EQ(*(list.begin()), begin);
}

TEST(iterator, end_should_return_iterator_to_end)
{
    intlist list{ 1, 2, 3 };
    EXPECT_ANY_THROW(*(list.end()));
}

TEST(iterator, pre_increment_operator)
{
    intlist list{ 1, 2, 3 };
    auto it = list.begin();
    EXPECT_EQ(*(++it), 2);
    EXPECT_EQ(*(++it), 3);
}

TEST(iterator, post_increment_operator)
{
    intlist list{ 1, 2, 3 };
    auto it = list.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
}

TEST(iterator, pre_decrement_operator)
{
    intlist list{ 1, 2, 3 };
    auto it = list.end();
    EXPECT_EQ(*(--it), 3);
    EXPECT_EQ(*(--it), 2);
}

TEST(iterator, post_decrement_operator)
{
    intlist list{ 1, 2, 3 };
    auto it = list.end();
    it--;
    EXPECT_EQ(*(it--), 3);
    EXPECT_EQ(*(it--), 2);
    EXPECT_EQ(*(it--), 1);
}

TEST(iterator, should_throw_exception_if_tries_to_get_head_value)
{
    intlist list;
    auto it = list.end();
    EXPECT_THROW(*it, std::runtime_error);
}

TEST(iterator, should_be_able_to_use_std_advance)
{
    intlist list{ 1, 2, 3 };
    auto it = list.begin();
    std::advance(it, 2);
    EXPECT_EQ(*it, 3);
}

TEST(iterator, equality_operator)
{
    intlist list{ 1, 2, 3 };
    auto it1 = list.begin();
    auto it2 = list.begin();
    EXPECT_TRUE(it1 == it2);
}

TEST(iterator, inequality_operator)
{
    intlist list{ 1, 2, 3 };
    auto it1 = list.begin();
    auto it2 = list.begin();
    ++it2;
    EXPECT_FALSE(it1 == it2);
}

TEST(iterator, copy_constructor)
{
    intlist list{ 1, 2, 3, 4, 5 };
    auto it1 = list.begin();
    std::advance(it1, 2);
    auto it2 = it1;
    EXPECT_EQ(*it1, *it2);
}

TEST(iterator, equal_operator)
{
    intlist list{ 1, 2, 3, 4, 5 };
    auto it1 = list.begin();
    std::advance(it1, 2);
    auto it2 = list.begin();
    it2 = it1;
    EXPECT_EQ(*it1, *it2);
}

TEST(iterator, dereference_should_return_the_correct_value)
{
    const int expected = 1;
    intlist list{ expected, 2, 3 };
    auto it = list.begin();
    EXPECT_EQ(*it, expected);
}
