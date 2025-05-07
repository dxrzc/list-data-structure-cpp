# List Data Structure
Low-level circular doubly linked list data structure with head node in C++.

![Image](https://github.com/user-attachments/assets/3ed9d27e-dde9-4359-acdd-2de750db8fd1)

## Features
- Flexible Header Construction - This data structure can be instantiated even if the template argument does not have a default constructor
- Iterator class  – Standard iterator for list traversal.
- Reverse iterator class – Traverse the list in reverse order.
- Const reverse iterator class – Immutable reverse iteration.
- std::advance and foreach support when working with iterators
- Movement semantic – Efficient resource transfer between lists.
- Emplace elements – Construct elements directly in the list using arguments.
- Reverse the list - Invert the order of the elements.
- Sort the list - Sort elements using the QuickSort algorithm.
- Splice the list into another list - Transfer elements from one list to another.
- Remove elements conditionally – Remove elements based on a condition (remove_if).
- Find element and return iterator to the cell – Locate elements and return an iterator to them.
- And more...

## Build and run tests
```
git clone https://github.com/dxrzc/list-data-structure-cpp.git
cd list-data-structure-cpp
mkdir build
cd build
cmake ..
cmake --build .
```

Run tests with CTest
```
ctest
```

Or run the executable manually
```
cd Debug
./testing
```

## Usage
Copy the list.h file into your project and include it. For example:

```cpp
#include "list.h"

class Resource
{
private:
	std::string test_string;
	int test_int;

public:
	// default constructor deleted
	Resource() = delete;

	Resource(const std::string& test_string, int test_int)
		: test_string(test_string), test_int(test_int) {}

	friend std::ostream& operator<<(std::ostream& os, const Resource& res)
	{
		os << res.test_string << ' ' << res.test_int << '\n';
		return os;
	}
};

int main()
{
	list<Resource> resources_list;

	// create and insert a resource
	Resource test_resource ("test string 0", 0);
	resources_list.push_back(test_resource);

	// create a resource directly in the list
	resources_list.emplace_back("test string 1", 1);

	for (const Resource& res : resources_list)
		std::cout << res;
}
```

Output: 
```
test string 0 0
test string 1 1
```


