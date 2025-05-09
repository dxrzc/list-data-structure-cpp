#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "list.h"
#include "intlist.typealias.helper.h"

#define ASSERT_INTEROP(From, To)							\
    static_assert(std::is_assignable_v<From, To>);			\
    static_assert(std::is_constructible_v<From, To>);		\
	static_assert(std::is_convertible_v<To, From>);

#define ASSERT_NO_INTEROP(From, To)                         \
    static_assert(!std::is_assignable_v<From, To>);			\
    static_assert(!std::is_constructible_v<From, To>);		\
	static_assert(!std::is_convertible_v<To, From>);

namespace
{
	namespace iterators_setup_values
	{
		inline const std::vector<int> list_values{ 1,3,5,7,9 };
	}	

	struct iterator_style
	{
		static const std::vector<int>& values() { return iterators_setup_values::list_values; }
	};

	struct reverse_iterator_style
	{
		static const std::vector<int> values()
		{
			std::vector<int> vector_copy = iterators_setup_values::list_values;
			std::ranges::reverse(vector_copy);
			return vector_copy;
		}
	};

	using iterators_type = ::testing::Types<
		intlist::iterator,
		intlist::const_iterator,
		intlist::reverse_iterator,
		intlist::const_reverse_iterator
	>;
}

template<typename T>
class iterators_test_fixture : public testing::Test
{
protected:
	list<int> test_list;

	void SetUp() override
	{
		for (int value : iterators_setup_values::list_values)
			test_list.push_back(value);
	}
};

template <typename T>
struct IteratorsTestTraits;

template <>
struct IteratorsTestTraits<list<int>::iterator> : public iterator_style {
	static auto begin(list<int>& l) { return l.begin(); }
	static auto end(list<int>& l) { return l.end(); }
};

template <>
struct IteratorsTestTraits<list<int>::const_iterator> : public iterator_style {
	static auto begin(const list<int>& l) { return l.cbegin(); }
	static auto end(const list<int>& l) { return l.cend(); }
};

template <>
struct IteratorsTestTraits<list<int>::reverse_iterator> : public reverse_iterator_style {
	static auto begin(list<int>& l) { return l.rbegin(); }
	static auto end(list<int>& l) { return l.rend(); }
};

template <>
struct IteratorsTestTraits<list<int>::const_reverse_iterator> : public reverse_iterator_style {
	static auto begin(const list<int>& l) { return l.crbegin(); }
	static auto end(const list<int>& l) { return l.crend(); }
};

TYPED_TEST_SUITE(iterators_test_fixture, iterators_type);