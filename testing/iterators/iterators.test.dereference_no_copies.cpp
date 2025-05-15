#include <gtest/gtest.h>
#include "resource.helper.h"

using test_list = list<test_resource>;

TEST_F(constructor_operations_test, dereference_does_not_make_copies)
{
	test_list test_resources;
	// rvalue forwarding makes no copies
	test_resources.push_back(test_resource());

	test_list::iterator it = test_resources.begin();
	test_list::reverse_iterator revit = test_resources.rbegin();
	test_list::const_iterator cit = test_resources.cbegin();
	test_list::const_reverse_iterator crevit = test_resources.crbegin();

	const test_resource& r = *it;
	const test_resource& r1 = *revit;
	const test_resource& r2 = *cit;
	const test_resource& r3 = *crevit;

	EXPECT_EQ(test_resource::instances_created, 1);
	EXPECT_EQ(test_resource::copy_constructor, 0);
}