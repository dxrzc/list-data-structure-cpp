#pragma once

#include "iterators_test_setup.utils.h"

using namespace iterators_test_setup_utils;

template <typename T>
struct iterators_test_traits;

template <>
struct iterators_test_traits<list<int>::iterator> : public iterator_style {
	static auto begin(list<int>& l) { return l.begin(); }
	static auto end(list<int>& l) { return l.end(); }
};

template <>
struct iterators_test_traits<list<int>::const_iterator> : public iterator_style {
	static auto begin(const list<int>& l) { return l.cbegin(); }
	static auto end(const list<int>& l) { return l.cend(); }
};

template <>
struct iterators_test_traits<list<int>::reverse_iterator> : public reverse_iterator_style {
	static auto begin(list<int>& l) { return l.rbegin(); }
	static auto end(list<int>& l) { return l.rend(); }
};

template <>
struct iterators_test_traits<list<int>::const_reverse_iterator> : public reverse_iterator_style {
	static auto begin(const list<int>& l) { return l.crbegin(); }
	static auto end(const list<int>& l) { return l.crend(); }
};
