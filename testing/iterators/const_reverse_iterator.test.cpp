#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"

TEST(const_reverse_iterator, crbegin_should_return_iterator_to_last_element)
{
    const int target = 3;
    intlist list{ 1, 2, target };
    intlist::const_reverse_iterator crevit = list.crbegin();
    EXPECT_EQ(target, *crevit);
}

TEST(const_reverse_iterator, crend_should_return_iterator_to_head)
{
    intlist list;
    EXPECT_ANY_THROW(*(list.crend()));
}

TEST(const_reverse_iterator, pre_increment_operator)
{
    intlist list{ 1, 2, 3 };
    auto crevit = list.crbegin();
    EXPECT_EQ(*(++crevit), 2);
    EXPECT_EQ(*(++crevit), 1);
}

TEST(const_reverse_iterator, post_increment_operator)
{
    intlist list{ 1, 2, 3 };
    auto crevit = list.crbegin();
    EXPECT_EQ(*(crevit++), 3);
    EXPECT_EQ(*(crevit++), 2);
    EXPECT_EQ(*(crevit++), 1);
}

TEST(const_reverse_iterator, pre_decrement_operator)
{
    intlist list{ 1, 2, 3 };
    auto crevit = list.crend();
    EXPECT_EQ(*(--crevit), 1);
    EXPECT_EQ(*(--crevit), 2);
    EXPECT_EQ(*(--crevit), 3);
}

TEST(const_reverse_iterator, post_decrement_operator)
{
    intlist list{ 1, 2, 3 };
    auto crevit = list.crend();
    crevit--;
    EXPECT_EQ(*(crevit--), 1);
    EXPECT_EQ(*(crevit--), 2);
    EXPECT_EQ(*(crevit--), 3);
}

TEST(const_reverse_iterator, should_throw_exception_if_tries_to_get_head_value)
{
    intlist list;
    auto crevit = list.rend();
    EXPECT_ANY_THROW(*crevit);
}

TEST(const_reverse_iterator, should_be_able_to_use_std_advance)
{
    const int target = 100;
    intlist list{ target, 2, 3 };
    auto crevit = list.crbegin();
    std::advance(crevit, 2);
    EXPECT_EQ(*crevit, target);
}

TEST(const_reverse_iterator, equality_operator)
{
    const int target = 100;
    intlist list{ 1, 2, target };
    auto crevit1 = list.crbegin();
    auto crevit2 = list.crbegin();
    EXPECT_TRUE(crevit1 == crevit2);
}

TEST(const_reverse_iterator, inequality_operator)
{
    const int target = 100;
    intlist list{ 1, 2, target };
    auto crevit1 = list.crbegin();
    auto crevit2 = list.crbegin();
    ++crevit2;
    EXPECT_TRUE(crevit1 != crevit2);
}

TEST(const_reverse_iterator, copy_constructor)
{
    intlist list{ 1, 2, 3 };
    intlist::const_reverse_iterator crevit = list.crbegin();
    intlist::const_reverse_iterator crevit2 = crevit;
    EXPECT_TRUE(crevit == crevit2);
}

TEST(const_reverse_iterator, equal_operator)
{
    intlist list{ 1, 2, 3 };
    auto crevit1 = list.crbegin();
    auto crevit2 = list.crbegin();
    ++crevit1;
    crevit2 = crevit1;
    EXPECT_TRUE(crevit2 == crevit1);
}

TEST(const_reverse_iterator, dereference_should_return_the_correct_value)
{
    const int target = 3;
    intlist list{ 1, 2, target };
    auto crevit = list.crbegin();
    EXPECT_EQ(*crevit, target);
}

TEST(const_reverse_iterator, should_be_constructed_using_an_iterator_successfully)
{
    intlist list{ 1, 2, 3 };
    auto it = list.begin();
    intlist::const_reverse_iterator crevit = it;
    EXPECT_EQ(*crevit, *it);
}

TEST(const_reverse_iterator, should_be_constructed_using_a_const_iterator_successfully)
{
    intlist list{ 1, 2, 3 };
    auto it = list.cbegin();
    intlist::const_reverse_iterator crevit = it;
    EXPECT_EQ(*crevit, *it);
}

TEST(const_reverse_iterator, should_be_constructed_using_a_reverse_iterator_successfully)
{
    intlist list{ 1, 2, 3 };
    auto it = list.rbegin();
    intlist::const_reverse_iterator crevit = it;
    EXPECT_EQ(*crevit, *it);
}

TEST(const_reverse_iterator, equality_operator_with_iterator)
{
    intlist list{ 1, 2, 3 };
    intlist::const_reverse_iterator crevit = list.crbegin();
    intlist::iterator it = --(list.end());
    EXPECT_TRUE(crevit == it);
}

TEST(const_reverse_iterator, equality_operator_with_const_iterator)
{
    intlist list{ 1, 2, 3 };
    intlist::const_reverse_iterator crevit = list.crbegin();
    intlist::const_iterator cit = --(list.cend());
    EXPECT_TRUE(crevit == cit);
}

TEST(const_reverse_iterator, equality_operator_with_reverse_iterator)
{
    intlist list{ 1, 2, 3 };
    intlist::const_reverse_iterator crevit = list.crbegin();
    intlist::reverse_iterator revit = list.rbegin();
    EXPECT_TRUE(crevit == revit);
}
