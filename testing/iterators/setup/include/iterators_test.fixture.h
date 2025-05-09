#pragma once

#include <gtest/gtest.h>
#include "iterators_test_setup.utils.h"
#include "list.h"

template<typename T>
class iterators_test_fixture : public testing::Test
{
protected:
	list<int> test_list;

	void SetUp() override
	{
		for (int value : iterators_test_setup_utils::list_values)
			test_list.push_back(value);
	}
};

TYPED_TEST_SUITE(iterators_test_fixture, iterators_test_setup_utils::iterators_type);

