#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"

TEST(reverse_iterator, rbegin_should_return_iterator_to_last_element)
{
    const int revbegin = 3;
    intlist list{ 1, 2, revbegin };
    EXPECT_EQ(*(list.rbegin()), revbegin);
}

TEST(reverse_iterator, rend_should_return_iterator_to_head)
{
    intlist list{ 1, 2, 3 };
    EXPECT_ANY_THROW(*(list.rend()));
}

TEST(reverse_iterator, pre_increment_operator)
{
    intlist list{ 1, 2, 3 };
    auto revit = list.rbegin();
    EXPECT_EQ(*(++revit), 2);
    EXPECT_EQ(*(++revit), 1);
}

TEST(reverse_iterator, post_increment_operator)
{
    intlist list{ 1, 2, 3 };
    auto revit = list.rbegin();
    EXPECT_EQ(*(revit++), 3);
    EXPECT_EQ(*(revit++), 2);
    EXPECT_EQ(*(revit++), 1);
}

TEST(reverse_iterator, pre_decrement_operator)
{
    intlist list{ 1, 2, 3 };
    auto revit = list.rend();
    EXPECT_EQ(*(--revit), 1);
    EXPECT_EQ(*(--revit), 2);
    EXPECT_EQ(*(--revit), 3);
}

TEST(reverse_iterator, post_decrement_operator)
{
    intlist list{ 1, 2, 3 };
    auto revit = list.rend();
    revit--;
    EXPECT_EQ(*(revit--), 1);
    EXPECT_EQ(*(revit--), 2);
    EXPECT_EQ(*(revit--), 3);
}

TEST(reverse_iterator, should_throw_exception_if_tries_to_get_head_value)
{
    intlist list;
    auto revit = list.rend();
    EXPECT_ANY_THROW(*revit);
}

TEST(reverse_iterator, should_be_able_to_use_std_advance)
{
    const int target = 100;
    intlist list{ target, 2, 3 };
    auto revit = list.rbegin();
    std::advance(revit, 2);
    EXPECT_EQ(*revit, target);
}

TEST(reverse_iterator, equality_operator)
{
    const int target = 100;
    intlist list{ 1, 2, target };
    auto revit1 = list.rbegin();
    auto revit2 = list.rbegin();
    EXPECT_TRUE(revit1 == revit2);
}

TEST(reverse_iterator, inequality_operator)
{
    const int target = 100;
    intlist list{ 1, 2, target };
    auto revit1 = list.rbegin();
    auto revit2 = list.rbegin();
    ++revit2;
    EXPECT_TRUE(revit1 != revit2);
}

TEST(reverse_iterator, copy_constructor)
{
    intlist list{ 1, 2, 3 };
    intlist::reverse_iterator revit = list.rbegin();
    intlist::reverse_iterator revit2 = revit;
    EXPECT_TRUE(revit == revit2);
}

TEST(reverse_iterator, equal_operator)
{
    intlist list{ 1, 2, 3 };
    auto revit1 = list.rbegin();
    auto revit2 = list.rbegin();
    ++revit1;
    revit2 = revit1;
    EXPECT_TRUE(revit2 == revit1);
}

TEST(reverse_iterator, dereference_should_return_the_correct_value)
{
    const int target = 3;
    intlist list{ 1, 2, target };
    auto revit = list.rbegin();
    EXPECT_EQ(*revit, target);
}

TEST(reverse_iterator, should_be_constructed_using_an_iterator_successfully)
{
    intlist list{ 1, 2, 3 };
    auto it = list.begin();
    intlist::reverse_iterator revit = it;
    EXPECT_EQ(*revit, *it);
}

TEST(reverse_iterator, equality_operator_with_iterator)
{
    intlist list{ 1, 2, 3 };
    intlist::reverse_iterator revit = list.rbegin();
    intlist::iterator it = --(list.end());
    EXPECT_TRUE(revit == it);
}
