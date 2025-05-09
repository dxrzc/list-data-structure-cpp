#pragma once

#include <vector>
#include <gtest/gtest.h>
#include <algorithm>
#include "intlist.typealias.helper.h"

namespace iterators_test_setup_utils
{
	inline const std::vector<int> list_values{ 1,3,5,7,9 };

	struct iterator_style
	{
		static const std::vector<int>& values() { return list_values; }
	};

	struct reverse_iterator_style
	{
		static const std::vector<int> values()
		{
			std::vector<int> vector_copy = list_values;
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