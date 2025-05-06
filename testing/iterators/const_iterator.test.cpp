#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"

TEST(const_iterator, successful_construction_based_on_another_const_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::const_iterator cit1 = list.begin();
    std::advance(cit1, 1); // Points to 20

    intlist::const_iterator cit2 = cit1;

    EXPECT_EQ(*cit2, *cit1);
}

TEST(const_iterator, successful_construction_based_on_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::iterator it = list.begin();
    std::advance(it, 2); // Points to 30

    intlist::const_iterator cit = it; 

    EXPECT_EQ(*cit, *it);
}

TEST(const_iterator, successful_construction_based_on_reverse_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::reverse_iterator revit = list.rbegin(); // Points to 30

    intlist::const_iterator cit = revit;

    EXPECT_EQ(*cit, *revit);
}

TEST(const_iterator, successful_construction_based_on_const_reverse_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::const_reverse_iterator crevit = list.rbegin();
    std::advance(crevit, 1); // Points to 20

    intlist::const_iterator cit = crevit;

    EXPECT_EQ(*cit, *crevit);
}

TEST(const_iterator, assigment_operator_works_with_other_const_iterators)
{
    intlist list{ 10, 20, 30 };

    intlist::const_iterator cit1 = list.begin();
    std::advance(cit1, 2); // Points to 30

    intlist::const_iterator cit2 = list.cend();;
    cit2 = cit1;

    EXPECT_EQ(*cit2, *cit1);
}

TEST(const_iterator, assigment_operator_works_with_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::iterator it = list.begin();
    std::advance(it, 1); // Points to 20

    intlist::const_iterator cit = list.cend();;
    cit = it;

    EXPECT_EQ(*cit, *it);
}

TEST(const_iterator, assigment_operator_works_with_reverse_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::reverse_iterator revit = list.rbegin(); // Points to 30

    intlist::const_iterator cit = list.cend();;
    cit = revit;

    EXPECT_EQ(*cit, *revit);
}

TEST(const_iterator, assigment_operator_works_with_const_reverse_iterator)
{
    intlist list{ 10, 20, 30 };

    intlist::const_reverse_iterator crevit = list.rbegin(); // Points to 30

    intlist::const_iterator cit = list.cend();
    cit = crevit;

    EXPECT_EQ(*cit, *crevit);
}

TEST(const_iterator, assigment_operator_no_fatal_failure_if_pimpl_is_null)
{
    intlist list{ 1,2,3,4,5 };

    intlist::const_iterator another_cit = list.begin();
    intlist::const_iterator cit; // null pimpl;

    EXPECT_NO_FATAL_FAILURE(cit = another_cit);
}

TEST(const_iterator, equality_operator_works_with_other_const_iterators)
{
    intlist list{ 100, 200, 300 };

    intlist::const_iterator cit1 = list.begin();
    std::advance(cit1, 1); // Points to 200

    intlist::const_iterator cit2 = list.begin();
    std::advance(cit2, 1); // Points to 200

    EXPECT_TRUE(cit1 == cit2);
}

TEST(const_iterator, equality_operator_works_with_iterator)
{
    intlist list{ 100, 200, 300 };

    intlist::iterator it = list.begin();
    std::advance(it, 2); // Points to 300

    intlist::const_iterator cit = list.begin();
    std::advance(cit, 2); // Points to 300

    EXPECT_TRUE(cit == it);
}

TEST(const_iterator, equality_operator_works_with_reverse_iterator)
{
    intlist list{ 100, 200, 300 };

    intlist::reverse_iterator revit = list.rbegin(); // Points to 300
    intlist::const_iterator cit(revit);

    EXPECT_TRUE(cit == revit);
}

TEST(const_iterator, equality_operator_works_with_const_reverse_iterator)
{
    intlist list{ 100, 200, 300 };

    intlist::const_reverse_iterator crevit = list.rbegin(); // Points to 300
    intlist::const_iterator cit(crevit);

    EXPECT_TRUE(cit == crevit);
}

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

TEST(const_iterator, dereference_should_return_the_correct_value)
{
    intlist list{ 1, 2, 3 };
    auto it = list.cbegin();
    std::advance(it, 2);
    EXPECT_EQ(*it, 3);
}

TEST(const_iterator, equality_operator_with_iterator)
{
    intlist list{ 1, 2, 3 };
    auto normal_iterator = list.begin();
    auto const_iterator = list.cbegin();
    EXPECT_TRUE(normal_iterator == const_iterator);
}