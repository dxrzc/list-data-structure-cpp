#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"

TEST(const_iterator, cbegin_should_return_iterator_to_begin)
{
    const int begin = 1;
    intlist list{ begin, 2, 3 };
    EXPECT_EQ(*(list.cbegin()), begin);
}

TEST(const_iterator, cend_should_return_iterator_to_end)
{
    intlist list{ 1, 2, 3 };
    EXPECT_ANY_THROW(*(list.cend()));
}

TEST(const_iterator, pre_increment_operator)
{
    intlist list{ 1, 2, 3 };
    auto cit = list.cbegin();
    EXPECT_EQ(*(cit), 1);
    EXPECT_EQ(*(++cit), 2);
    EXPECT_EQ(*(++cit), 3);
}

TEST(const_iterator, post_increment_operator)
{
    intlist list{ 1, 2, 3 };
    auto cit = list.cbegin();
    EXPECT_EQ(*(cit++), 1);
    EXPECT_EQ(*(cit++), 2);
    EXPECT_EQ(*(cit++), 3);
}

TEST(const_iterator, pre_decrement_operator)
{
    intlist list{ 1, 2, 3 };
    auto cit = list.cend();
    EXPECT_EQ(*(--cit), 3);
    EXPECT_EQ(*(--cit), 2);
    EXPECT_EQ(*(--cit), 1);
}

TEST(const_iterator, post_decrement_operator)
{
    intlist list{ 1, 2, 3 };
    auto cit = list.cend();
    cit--;
    EXPECT_EQ(*(cit--), 3);
    EXPECT_EQ(*(cit--), 2);
    EXPECT_EQ(*(cit--), 1);
}

TEST(const_iterator, should_throw_exception_if_tries_to_get_head_value)
{
    intlist list;
    auto head = list.cbegin();
    EXPECT_THROW(*head, std::runtime_error);
}

TEST(const_iterator, should_be_able_to_use_std_advance)
{
    intlist list{ 1, 2, 3 };
    auto it = list.cbegin();
    std::advance(it, 1);
    EXPECT_EQ(*it, 2);
    std::advance(it, 1);
    EXPECT_EQ(*it, 3);
}

TEST(const_iterator, equality_operator)
{
    intlist list{ 1, 2, 3 };
    auto it1 = list.cbegin();
    auto it2 = list.cbegin();
    EXPECT_TRUE(it1 == it2);
}

TEST(const_iterator, inequality_operator)
{
    intlist list{ 1, 2, 3 };
    auto it1 = list.cbegin();
    auto it2 = list.cbegin();
    std::advance(it2, 1);
    EXPECT_TRUE(it1 != it2);
}

TEST(const_iterator, copy_constructor)
{
    intlist list{ 1, 2, 3 };
    auto it1 = list.cbegin();
    intlist::const_iterator it2 = it1;
    EXPECT_TRUE(it2 == it1);
}

TEST(const_iterator, equal_operator)
{
    intlist list{ 1, 2, 3 };
    auto it1 = list.cbegin();
    auto it2 = list.cbegin();
    std::advance(it1, 2);
    it2 = it1;
    EXPECT_TRUE(it2 == it1);
}

TEST(const_iterator, dereference_should_return_the_correct_value)
{
    intlist list{ 1, 2, 3 };
    auto it = list.cbegin();
    std::advance(it, 2);
    EXPECT_EQ(*it, 3);
}

TEST(const_iterator, should_be_constructed_using_an_iterator_successfully)
{
    intlist list{ 1, 2, 3 };
    intlist::iterator normal_iterator = list.begin();
    intlist::const_iterator const_iterator = normal_iterator;
    EXPECT_EQ(*const_iterator, *normal_iterator);
}

TEST(const_iterator, equality_operator_with_iterator)
{
    intlist list{ 1, 2, 3 };
    auto normal_iterator = list.begin();
    auto const_iterator = list.cbegin();
    EXPECT_TRUE(normal_iterator == const_iterator);
}