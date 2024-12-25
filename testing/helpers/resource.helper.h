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
	static unsigned destructor_calls;

	test_resource(uint16_t testvalue_) : testvalue(testvalue_) { ++instances_created; }
	test_resource(const test_resource& rhs) :testvalue(rhs.testvalue) { ++copy_constructor; }
	test_resource(test_resource&& rhs) noexcept : testvalue(std::move(rhs.testvalue)) { ++movement_constructor; }
	~test_resource() { ++destructor_calls; }
};

class test_resource_list : public ::testing::Test
{
protected:
	void SetUp() override
	{
		test_resource::copy_constructor = 0;
		test_resource::movement_constructor = 0;
		test_resource::instances_created = 0;
		test_resource::destructor_calls = 0;		
	}
};