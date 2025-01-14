# List Data Structure
Low-level circular doubly linked list data structure with a header node in C++.

## Features
- Flexible Header Construction - This data structure can be instantiated even if the template argument does not have a default constructor
- Iterator class  – Standard iterator for list traversal.
- Reverse iterator class – Traverse the list in reverse order.
- Const reverse iterator class – Immutable reverse iteration.
- Movement semantic – Efficient resource transfer between lists.
- Emplace elements – Construct elements directly in the list using arguments.
- Reverse the list - Invert the order of the elements.
- Sort the list - Sort elements using the QuickSort algorithm.
- Splice the list into another list - Transfer elements from one list to another.
- Remove elements conditionally – Remove elements based on a condition (remove_if).
- Find element and return iterator to the cell – Locate elements and return an iterator to them.
- And more...

## Steps for building and run tests
```
git clone https://github.com/itsdrc/list-data-structure-cpp.git
cd list-data-structure-cpp
mkdir build
cd build
cmake ..
cmake --build .
```

And run tests using ctest
```
ctest
```

Or run the executable
```
cd Debug
./testing
```


