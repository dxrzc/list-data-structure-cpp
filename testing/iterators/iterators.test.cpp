#include <type_traits>
#include "macros/INTEROP.MACRO.H"
#include "macros/DEREFERENCE.MACRO.H"
#include "macros/ASSERT_ITERATOR_STL_COMPAT.MACRO.H"
#include "iterators_test_traits.h"
#include "iterators_test.fixture.h"

ASSERT_ITERATOR_STL_COMPAT(intlist::const_reverse_iterator);
ASSERT_ITERATOR_STL_COMPAT(intlist::const_iterator);
ASSERT_ITERATOR_STL_COMPAT(intlist::reverse_iterator);
ASSERT_ITERATOR_STL_COMPAT(intlist::iterator);

ASSERT_DEREFERENCE_RETURNS_CONST_REFERENCE(intlist::const_iterator);
ASSERT_DEREFERENCE_RETURNS_CONST_REFERENCE(intlist::const_reverse_iterator);

ASSERT_DEREFERENCE_RETURNS_NONCONST_REFERENCE(intlist::iterator);
ASSERT_DEREFERENCE_RETURNS_NONCONST_REFERENCE(intlist::reverse_iterator);

ASSERT_INTEROP(intlist::iterator, intlist::reverse_iterator);
ASSERT_NO_INTEROP(intlist::iterator, intlist::const_reverse_iterator);
ASSERT_NO_INTEROP(intlist::iterator, intlist::const_iterator);

ASSERT_INTEROP(intlist::reverse_iterator, intlist::iterator);
ASSERT_NO_INTEROP(intlist::reverse_iterator, intlist::const_iterator);
ASSERT_NO_INTEROP(intlist::reverse_iterator, intlist::const_reverse_iterator);

ASSERT_INTEROP(intlist::const_reverse_iterator, intlist::const_iterator);
ASSERT_INTEROP(intlist::const_reverse_iterator, intlist::iterator);

ASSERT_INTEROP(intlist::const_iterator, intlist::const_reverse_iterator)
ASSERT_INTEROP(intlist::const_iterator, intlist::iterator)
ASSERT_INTEROP(intlist::const_iterator, intlist::reverse_iterator)

TYPED_TEST(iterators_test_fixture, constructor_no_fatal_failure_if_rhs_iterator_is_not_initialized)
{
	TypeParam uninitialized_iterator{};
	EXPECT_NO_FATAL_FAILURE(TypeParam it = uninitialized_iterator);
}

TYPED_TEST(iterators_test_fixture, assigment_operator_no_fatal_failure_if_rhs_iterator_is_not_initialized)
{
	TypeParam it = iterators_test_traits<TypeParam>::begin(this->test_list);
	TypeParam uninitialized_iterator{};

	EXPECT_NO_FATAL_FAILURE(it = uninitialized_iterator);
}

TYPED_TEST(iterators_test_fixture, assigment_operator_no_fatal_failure_if_lhs_iterator_is_not_initialized)
{
	TypeParam it = iterators_test_traits<TypeParam>::begin(this->test_list);
	TypeParam uninitialized_iterator{};

	EXPECT_NO_FATAL_FAILURE(uninitialized_iterator = it);
}

TYPED_TEST(iterators_test_fixture, dereference_operator)
{
	TypeParam it = iterators_test_traits<TypeParam>::begin(this->test_list);
	auto begin_value = iterators_test_traits<TypeParam>::values().at(0);

	EXPECT_EQ(*it, begin_value);
}

TYPED_TEST(iterators_test_fixture, dereferencing_the_head_node_throws_a_runtime_error)
{
	TypeParam it = iterators_test_traits<TypeParam>::end(this->test_list);
	EXPECT_THROW(*it, std::runtime_error);
}

TYPED_TEST(iterators_test_fixture, pre_increment_operator)
{
	const int expected_final_pointed_value = iterators_test_traits<TypeParam>::values().at(1);
	TypeParam it = iterators_test_traits<TypeParam>::begin(this->test_list);

	++it;

	EXPECT_EQ(*it, expected_final_pointed_value);
}

TYPED_TEST(iterators_test_fixture, post_increment_operator)
{
	const int expected_final_pointed_value = iterators_test_traits<TypeParam>::values().at(1);
	TypeParam it = iterators_test_traits<TypeParam>::begin(this->test_list);

	it++;

	EXPECT_EQ(*it, expected_final_pointed_value);
}

TYPED_TEST(iterators_test_fixture, pre_decrement_operator)
{
	const int expected_final_pointed_value = iterators_test_traits<TypeParam>::values()
		.at(iterators_test_traits<TypeParam>::values().size() - 1);

	TypeParam it = iterators_test_traits<TypeParam>::end(this->test_list);

	--it;

	EXPECT_EQ(*it, expected_final_pointed_value);
}

TYPED_TEST(iterators_test_fixture, post_decrement_operator)
{
	const int expected_final_pointed_value = iterators_test_traits<TypeParam>::values()
		.at(iterators_test_traits<TypeParam>::values().size() - 1);

	TypeParam it = iterators_test_traits<TypeParam>::end(this->test_list);

	it--;

	EXPECT_EQ(*it, expected_final_pointed_value);
}

TYPED_TEST(iterators_test_fixture, equality_operator_returns_true_if_iterators_point_to_the_same_node)
{
	TypeParam it = iterators_test_traits<TypeParam>::begin(this->test_list);
	std::advance(it, 1);

	TypeParam it2 = iterators_test_traits<TypeParam>::begin(this->test_list);
	std::advance(it2, 1);

	EXPECT_TRUE(it == it2);
	EXPECT_TRUE(it2 == it);
}

TYPED_TEST(iterators_test_fixture, equality_operator_returns_false_if_iterators_point_to_different_nodes)
{
	this->test_list = intlist{ 1,1,1,1,1 };

	TypeParam it = iterators_test_traits<TypeParam>::begin(this->test_list);
	TypeParam it2 = iterators_test_traits<TypeParam>::begin(this->test_list);

	std::advance(it2, 1);

	EXPECT_FALSE(it == it2);
}

TYPED_TEST(iterators_test_fixture, begin_should_return_iterator_to_begin_of_the_list)
{
	TypeParam it = iterators_test_traits<TypeParam>::begin(this->test_list);
	EXPECT_EQ(*it, iterators_test_traits<TypeParam>::values().at(0));
}

TYPED_TEST(iterators_test_fixture, end_should_return_iterator_to_head)
{
	TypeParam it = iterators_test_traits<TypeParam>::end(this->test_list);
	EXPECT_ANY_THROW(*it); // throws exception when dereferecing head
}
