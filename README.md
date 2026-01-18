# Singly Linked List in C++

This is a simple implementation of a singly linked list in C++ with basic operations. It includes:
- Adding and removing elements at the front;
- Removing duplicates in a sorted list
- Merging two sorted lists
- Reversing the list
- Summing all values in the list

## Usage

```cpp
#include <SLL.cpp>

int main() {
    linked_list list;
    list.push_front(5);
    list.push_front(10);
    list.push_front(15);

    // Print list
    list.print_list();

    return 0;
}
