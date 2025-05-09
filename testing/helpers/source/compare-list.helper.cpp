#include "compare-list.helper.h"

// In order to get a error message with both lists printed in console
// use this helper instead of just "==" operator
testing::AssertionResult compare_list(const intlist& list, const intlist& list2)
{
	if (list == list2)
		return testing::AssertionSuccess();
	else
	{
		auto fillStringWithList = [](std::string& str, const intlist& target)
		{
			for (int e : target)
				str.append(std::to_string(e) + " ");
		};

		std::string list1String;
		std::string list2String;

		fillStringWithList(list1String, list);
		fillStringWithList(list2String, list2);

		return testing::AssertionFailure() << "List 1: " << list1String
			<< " List2: " << list2String;
	}
}