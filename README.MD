# List Data Structure (C++20)

This repository provides a templated circular doubly linked list implemented in modern C++ (C++20), focusing on iterator support, move semantics, and correctness.

![Image](https://github.com/user-attachments/assets/3ed9d27e-dde9-4359-acdd-2de750db8fd1)

## Features

### Core design
- Templated circular doubly linked list
- Head node design that does not require a default-constructible type
- Strong ownership and memory management guarantees

### Iterators
- Forward iterator
- Const forward iterator
- Reverse iterator
- Const reverse iterator
- Compatible with `std::advance`, range-based for loops, and standard algorithms

### Operations
- Copy and move semantics
- In-place element construction (`emplace`)
- Element access and traversal
- Conditional removal (`remove_if`)
- Element lookup returning iterators
- List reversal
- In-place sorting (QuickSort-based implementation)
- Splicing elements between lists

### Testing
- Unit tests implemented using Google Test

## Build and test

### Requirements
- C++20 compatible compiler
- CMake
- Ninja (recommended)
```bash
git clone https://github.com/dxrzc/list-data-structure-cpp.git
cd list-data-structure-cpp

cmake -S . -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build

cd build
ctest
```

## Usage
The following example demonstrates usage of the list with custom types, move semantics, sorting, and standard library interoperability.

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


