#include <gtest/gtest.h>
#include <type_traits>
#include "intlist.typealias.helper.h"

static_assert(!std::is_constructible<intlist::iterator, intlist::const_iterator>::value, 
    "iterator should not be constructible from const_iterator");

static_assert(!std::is_constructible<intlist::iterator, intlist::const_reverse_iterator>::value,
    "iterator should not be constructible from const_reverse_iterator");

TEST(iterator, successful_construction_based_on_another_iterator)
{
    intlist list{ 1,2,3,4,5 };
    intlist::iterator another_iterator = list.begin();
    std::advance(another_iterator, 2);

    intlist::iterator it = another_iterator;

    EXPECT_EQ(*it, *another_iterator);
}

TEST(iterator, successful_construction_based_on_reverse_iterator)
{
    intlist list{ 1,2,3,4,5 };
    intlist::reverse_iterator revit = list.rbegin();
    std::advance(revit, 2);

    intlist::iterator it = revit;

    EXPECT_EQ(*it , *revit);
}

TEST(iterator, equality_operator_works_with_other_iterators)
{
    intlist list{ 1,2,3,4,5 };

    intlist::iterator another_iterator = list.begin();
    std::advance(another_iterator, 2);

    intlist::iterator it = list.begin();
    std::advance(it, 2);

    EXPECT_TRUE(it == another_iterator);
}


TEST(iterator, equality_operator_works_with_reverse_iterator)
{
    intlist list{ 1,2,3,4,5 };

    intlist::reverse_iterator revit = list.rbegin();
    
    intlist::iterator it = list.begin();
    std::advance(it, 4);

    EXPECT_TRUE(it == revit);
}

TEST(iterator, equality_operator_works_with_const_iterator)
{
    intlist list{ 1,2,3,4,5 };

    intlist::const_iterator cit = list.cbegin();

    intlist::iterator it = list.begin();    

    EXPECT_TRUE(it == cit);
}

TEST(iterator, equality_operator_works_with_const_reverse_iterator)
{
    intlist list{ 1,2,3,4,5 };

    intlist::const_reverse_iterator cit = list.crbegin();

    intlist::iterator it = list.begin();
    std::advance(it, 4);

    EXPECT_TRUE(it == cit);
}

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
