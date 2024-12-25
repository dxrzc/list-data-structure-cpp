#include <gtest/gtest.h>
#include "list.h"

class NoDefaultConstructorType
{
public:
	NoDefaultConstructorType() = delete;
};

TEST(constructor, should_be_able_to_create_a_list_of_types_with_no_default_constructor)
{
	list<NoDefaultConstructorType> list;
}