#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"

TEST(const_reverse_iterator, successful_construction_based_on_another_const_reverse_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::const_reverse_iterator crevit1 = list.rbegin();
    std::advance(crevit1, 1); // Points to 20

    intlist::const_reverse_iterator crevit2 = crevit1;

    EXPECT_EQ(*crevit2, *crevit1);
}

TEST(const_reverse_iterator, successful_construction_based_on_reverse_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::reverse_iterator revit = list.rbegin();
    std::advance(revit, 2); // Points to 10

    intlist::const_reverse_iterator crevit = revit;

    EXPECT_EQ(*crevit, *revit);
}

TEST(const_reverse_iterator, successful_construction_based_on_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::iterator it = list.end();
    std::advance(it, -1); // Points to 30

    intlist::const_reverse_iterator crevit = it;

    EXPECT_EQ(*crevit, *it);
}

TEST(const_reverse_iterator, successful_construction_based_on_const_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::const_iterator cit = list.end();
    std::advance(cit, -2); // Points to 20

    intlist::const_reverse_iterator crevit = cit;

    EXPECT_EQ(*crevit, *cit);
}

TEST(const_reverse_iterator, assignment_operator_works_with_other_const_reverse_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::const_reverse_iterator crevit1 = list.rbegin();
    std::advance(crevit1, 2); // Points to 10

    intlist::const_reverse_iterator crevit2;
    crevit2 = crevit1;

    EXPECT_EQ(*crevit2, *crevit1);
}

TEST(const_reverse_iterator, assignment_operator_works_with_reverse_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::reverse_iterator revit = list.rbegin();
    std::advance(revit, 1); // Points to 20

    intlist::const_reverse_iterator crevit;
    crevit = revit;

    EXPECT_EQ(*crevit, *revit);
}

TEST(const_reverse_iterator, assignment_operator_works_with_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::iterator it = list.end();
    std::advance(it, -3); // Points to 10

    intlist::const_reverse_iterator crevit;
    crevit = it;

    EXPECT_EQ(*crevit, *it);
}

TEST(const_reverse_iterator, assignment_operator_works_with_const_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::const_iterator cit = list.end();
    std::advance(cit, -1); // Points to 30

    intlist::const_reverse_iterator crevit;
    crevit = cit;

    EXPECT_EQ(*crevit, *cit);
}

TEST(const_reverse_iterator, assignment_operator_no_fatal_failure_if_pimpl_is_null)
{
    intlist list{ 10, 20, 30 };

    intlist::const_reverse_iterator valid = list.rbegin();
    intlist::const_reverse_iterator empty;

    EXPECT_NO_FATAL_FAILURE(empty = valid);
}

TEST(const_reverse_iterator, equality_operator_works_with_other_const_reverse_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::const_reverse_iterator a = list.rbegin();
    std::advance(a, 1);

    intlist::const_reverse_iterator b = list.rbegin();
    std::advance(b, 1);

    EXPECT_TRUE(a == b);
}

TEST(const_reverse_iterator, equality_operator_works_with_reverse_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::reverse_iterator rev = list.rbegin();
    std::advance(rev, 2); // Points to 10

    intlist::const_reverse_iterator crev = list.rbegin();
    std::advance(crev, 2); // Points to 10

    EXPECT_TRUE(crev == rev);
}

TEST(const_reverse_iterator, equality_operator_works_with_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::iterator it = list.end();
    std::advance(it, -1); // Points to 30

    intlist::const_reverse_iterator crev = it;

    EXPECT_TRUE(crev == it);
}

TEST(const_reverse_iterator, equality_operator_works_with_const_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::const_iterator cit = list.end();
    std::advance(cit, -2); // Points to 20

    intlist::const_reverse_iterator crev = cit;

    EXPECT_TRUE(crev == cit);
}

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

TEST(const_reverse_iterator, dereference_should_return_the_correct_value)
{
    const int target = 3;
    intlist list{ 1, 2, target };
    auto crevit = list.crbegin();
    EXPECT_EQ(*crevit, target);
}
