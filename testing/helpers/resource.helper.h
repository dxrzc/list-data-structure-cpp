#pragma once

#include <gtest/gtest.h>
#include <cassert>
#include "list.h"

class test_resource
{
private:
	uint16_t testvalue;

public:
	test_resource() :testvalue(0) { ++instances_created; }
	static unsigned copy_constructor;
	static unsigned movement_constructor;
	static unsigned instances_created;

	test_resource(uint16_t testvalue_) : testvalue(testvalue_) { ++instances_created; }
	test_resource(const test_resource& rhs) :testvalue(rhs.testvalue) { ++copy_constructor; }
	test_resource(test_resource&& rhs) noexcept : testvalue(std::move(rhs.testvalue)) { ++movement_constructor; }
};

class test_resource_list : public ::testing::Test
{
protected:
	list<test_resource> test_list;
	void SetUp() override
	{
		test_resource::copy_constructor = 0;
		test_resource::movement_constructor = 0;
		test_resource::instances_created = 0;
		test_list.clear();
		assert(test_list.size() == 0);
	}
};