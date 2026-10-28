# Data Structures in C++

Ten data structure classes implemented from scratch in C++, using arrays and pointers. Each file has its own `main()` with a small test program.

## What is implemented

| File | Structures |
|---|---|
| `Ulist.cpp` | Unsorted array list |
| `Slist.cpp` | Sorted array list with binary search |
| `Ulinkedlist.cpp` | Unsorted linked list |
| `Slinkedlist.cpp` | Sorted linked list |
| `circular_doublylinkedlist.cpp` | Sorted circular linked list and sorted doubly linked list |
| `stack_linkedstack.cpp` | Array-based stack and linked stack |
| `Queue_linkedQueue.cpp` | Circular array queue and linked queue |

## Operations

- `insert`, `search`, `del`, `display`
- `getlen`, `isfull`, `isempty`, `makeempty`
- `push` and `pop` for stacks, `inqueue` and `dequeue` for queues
- Extra helpers: `calculateavg`, `getmax`, `getmin`, `splitlist`, `copy`, `replaceitem`

## Key ideas

- Sorted insertion in arrays (shifting) and in linked lists (pointer walking)
- Binary search on the sorted array list
- Circular queue using modulo indexing, with one slot kept empty to tell full from empty
- Circular and doubly linked lists, with special cases for the first and last node
- A friend function (`calculateavg`) accessing a private member of the linked list

## How to build and run

Each file is a separate program. For example:

```
g++ Slist.cpp -o Slist
./Slist
```

On Windows, run `Slist.exe` instead.

## Known limitations

- Array-based structures have a fixed capacity of 100 elements.
- Elements are `int` only; templates are not used.
- The linked structures do not define destructors yet.
