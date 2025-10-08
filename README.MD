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
# Configure
cmake -S . -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
# Build
cmake --build build
cd build
ctest
```

## Usage
Include the list.h file in a c++20 project. For example:

```cpp
#include "list.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ostream>

class User
{
private:
    std::string m_username;
    std::string m_id;
    list<std::string> m_items;

public:
    User() = delete;
    User(const User &rhs) = default;
    User(User &&rhs) = default;

    User(const std::string &username, const std::string &id, const list<std::string> &items = {})
        : m_username(username),
          m_id(id),
          m_items(items)
    {}

    std::size_t add_item(const std::string &item_id)
    {
        m_items.push_back(item_id);
        return m_items.size();
    }

    auto operator<=>(const User &user) const
    {
        return m_username <=> user.m_username;
    }

    friend std::ostream &operator<<(std::ostream &os, const User &user)
    {
        os << "User { name:\"" << user.m_username << "\", id:\"" << user.m_id << "\", items:[";
        for (std::size_t i = 0; i < user.m_items.size(); ++i)
        {
            os << "\"" << user.m_items[i] << "\"";
            if (i + 1 < user.m_items.size())
                os << ", ";
        }
        os << "]}";
        return os;
    }
};

int main()
{
    try
    {
        list<User> users;

        // Create and copy
        User user1{"Lance", "1457"};
        user1.add_item("item1");
        user1.add_item("item2");
        users.push_back(user1);

        // Create and "move"
        User user2{"Conor", "54321"};
        user2.add_item("itemA");
        user2.add_item("itemB");
        users.push_back(std::move(user2));

        // Create in list
        users.emplace_back("Ryley", "12345", list<std::string>{"itemX", "itemY"});

        // Sort by name
        users.sort();

        // Print
        std::ranges::copy(users, std::ostream_iterator<User>(std::cout, "\n"));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
```

Output: 
```
User { name:"Conor", id:"54321", items:["itemA", "itemB"]}
User { name:"Lance", id:"1457", items:["item1", "item2"]}
User { name:"Ryley", id:"12345", items:["itemX", "itemY"]}
```


