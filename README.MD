# List Data Structure (C++20)

This repository implements a generic circular doubly-linked list in C++20 from scratch.

![Image](https://github.com/user-attachments/assets/3ed9d27e-dde9-4359-acdd-2de750db8fd1)

## Features
- Flexible Head Construction - This data structure can be instantiated even if the template argument does not have a default constructor
- Iterator class  – Standard iterator for list traversal.
- Const iterator class - Immutabe standard iterator for list traversal
- Reverse iterator class – Traverse the list in reverse order.
- Const reverse iterator class – Immutable reverse iteration.
- std::advance and foreach support when working with iterators
- Move semantics – Efficient resource transfer between lists.
- Emplace elements – Construct elements directly in the list using arguments.
- Reverse the list - Invert the order of the elements.
- Sort the list - Sort elements using the QuickSort algorithm.
- Splice the list into another list - Transfer elements from one list to another.
- Remove elements conditionally – Remove elements based on a condition (remove_if).
- Find element and return iterator to the cell – Locate elements and return an iterator to them.
- Testing
- Etc.

## Build and test
```
git clone https://github.com/dxrzc/list-data-structure-cpp.git
cd list-data-structure-cpp
cmake -S . -B build -G Ninja && cmake --build build
cd build
ctest
```

## Example usage
Include the list.h file in a c++20 project. For example

```cpp
#include "list.h"
#include <assert.h>
#include <vector>
#include <ranges>

class User
{
public:
	static unsigned short copies;

private:
	std::string id;
	std::vector<std::string> items;

public:
	// No default constructor
	User() = delete;
	User(std::string&& id_, std::vector<std::string>&& items_) noexcept : id(std::move(id_)), items(std::move(items_)) {}
	User(const User& user) : id(user.id), items(user.items) { ++User::copies; }
	friend std::ostream& operator<<(std::ostream& os, const User& usr)
	{
		os << "User{id=\"" << usr.id << "\", items=[";
		for (std::size_t i = 0; i < usr.items.size(); ++i) {
			os << "\"" << usr.items[i] << "\"";
			if (i + 1 < usr.items.size()) os << ", ";
		}
		os << "]}";
		return os;
	}
};

unsigned short User::copies = 0;

int main()
{
	try
	{
		list<User> users;

		// Create and insert
		User user("user1ABC", { "item1", "item2", "item3" });
		users.push_back(user);

		// Create directly in the list
		users.emplace_back("user2CDE", std::vector<std::string>({ "item2", "item3", "item4" }));

		assert(User::copies == 1);
		std::ranges::copy(users, std::ostream_iterator<User>(std::cout, "\n"));
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
```

Output: 
```
User{id="user1ABC", items=["item1", "item2", "item3"]}
User{id="user2CDE", items=["item2", "item3", "item4"]}
```


