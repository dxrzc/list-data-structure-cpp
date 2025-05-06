#include <gtest/gtest.h>
#include "intlist.typealias.helper.h"

static_assert(!std::is_constructible<intlist::reverse_iterator, intlist::const_iterator>::value,
	"reverse_iterator should not be constructible from const_iterator");

static_assert(!std::is_constructible<intlist::reverse_iterator, intlist::const_reverse_iterator>::value,
	"reverse_iterator should not be constructible from const_reverse_iterator");

TEST(reverse_iterator, successful_construction_based_on_another_reverse_iterator)
{
	intlist list{ 1,2,3,4,5 };

	intlist::reverse_iterator another_revit = list.rbegin();
	std::advance(another_revit, 2);

	intlist::reverse_iterator revit = another_revit;

	EXPECT_EQ(*revit, *another_revit);
}

TEST(reverse_iterator, successful_construction_based_on_iterator)
{
	intlist list{ 1,2,3,4,5 };

	intlist::iterator it = list.begin();
	std::advance(it, 2);

	intlist::reverse_iterator revit = it;

	EXPECT_EQ(*revit, *it);
}

TEST(reverse_iterator, equality_operator_works_with_other_reverse_iterators)
{
	intlist list{ 1,2,3,4,5 };

	intlist::reverse_iterator another_revit = list.rbegin();
	std::advance(another_revit, 1);

	intlist::reverse_iterator revit = list.rbegin();
	std::advance(revit, 1);

	EXPECT_TRUE(another_revit == revit);
}

TEST(reverse_iterator, equality_operator_works_with_iterator)
{
	intlist list{ 1,2,3,4,5 };

	intlist::iterator it = list.end();
	std::advance(it, -2); // 4

	intlist::reverse_iterator revit = list.rbegin();
	std::advance(revit, 1); // 4

	EXPECT_TRUE(revit == it);	
}

TEST(reverse_iterator, equality_operator_works_with_const_iterator)
{
	intlist list{ 1,2,3,4,5 };

	intlist::const_iterator cit = list.end();
	std::advance(cit, -2); // 4

	intlist::reverse_iterator revit = list.rbegin();
	std::advance(revit, 1); // 4

	EXPECT_TRUE(revit == cit);	
}

TEST(reverse_iterator, equality_operator_works_with_const_reverse_iterator)
{
	intlist list{ 1,2,3,4,5 };

	intlist::const_reverse_iterator crevit = list.rbegin();
	std::advance(crevit, 2); // 3

	intlist::reverse_iterator revit = list.rbegin();
	std::advance(revit, 2); // 3

	EXPECT_TRUE(revit == crevit);	
}

TEST(reverse_iterator, assigment_operator_works_with_another_reverse_iterator)
{
	intlist list{ 1,2,3,4,5 };

	intlist::reverse_iterator another_revit = list.rbegin();
	std::advance(another_revit, 2);

	intlist::reverse_iterator revit = list.rbegin();

	revit = another_revit;

	EXPECT_EQ(*revit, *another_revit);
}

TEST(reverse_iterator, assigment_operator_works_with_iterators)
{
	intlist list{ 1,2,3,4,5 };

	intlist::iterator it = list.end();
	std::advance(it, -2);

	intlist::reverse_iterator revit;
	revit = it;

	EXPECT_EQ(*revit, *it);
}

TEST(reverse_iterator, assigment_operator_no_fatal_failure_if_pimpl_is_null)
{
	intlist list{ 1,2,3,4,5 };

	intlist::iterator another_it = list.end();
	intlist::iterator it; // null pimpl

	EXPECT_NO_FATAL_FAILURE(it = another_it);
}

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

TEST(reverse_iterator, dereference_should_return_the_correct_value)
{
	const int target = 3;
	intlist list{ 1, 2, target };

	auto revit = list.rbegin();

	EXPECT_EQ(*revit, target);
}