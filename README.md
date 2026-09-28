# Data Structures & Algorithms in C

A personal implementation and study of fundamental **data structures and algorithms in C**, built from the ground up with a focus on understanding what happens beneath the abstraction.

This project is not intended to invent new data structures or algorithms. Almost everything implemented here has been implemented many times before. The purpose is to **reconstruct these ideas independently**, understand their memory representation and behavior, and compare the implementations with established approaches.

The project will eventually become both:

1. A usable C library for working with common data structures and algorithms.
2. A detailed study of how these structures and algorithms work internally.

---

## Goals

The main goals of this project are:

* Understand data structures at the memory level.
* Understand pointers, allocation, ownership, and deallocation through practical implementation.
* Implement data structures from scratch in C.
* Implement fundamental algorithms that operate on those structures.
* Analyze time and space complexity.
* Understand the invariants maintained by each data structure.
* Write tests for correctness and edge cases.
* Investigate memory behavior and implementation details.
* Compare implementations with established libraries and algorithms.
* Develop a clean and reusable C API.
* Learn how a real C library is organized, compiled, tested, and distributed.
* Document the reasoning behind the implementations rather than only documenting their usage.

---

# Project Structure

```text
dsalgo/
│
├── README.md
├── LICENSE
├── Makefile
├── .gitignore
│
├── include/
│   └── dsalgo/
│       ├── data_structures/
│       │   ├── array.h
│       │   ├── linked_list.h
│       │   ├── doubly_linked_list.h
│       │   ├── stack.h
│       │   ├── queue.h
│       │   ├── deque.h
│       │   ├── hash_table.h
│       │   ├── heap.h
│       │   ├── bst.h
│       │   └── graph.h
│       │
│       └── algorithms/
│           ├── search.h
│           ├── sort.h
│           ├── tree.h
│           └── graph.h
│
├── src/
│   ├── data_structures/
│   │   ├── array/
│   │   │   └── array.c
│   │   ├── linked_list/
│   │   │   └── linked_list.c
│   │   ├── doubly_linked_list/
│   │   │   └── doubly_linked_list.c
│   │   ├── stack/
│   │   │   └── stack.c
│   │   ├── queue/
│   │   │   └── queue.c
│   │   ├── deque/
│   │   │   └── deque.c
│   │   ├── hash_table/
│   │   │   └── hash_table.c
│   │   ├── heap/
│   │   │   └── heap.c
│   │   ├── bst/
│   │   │   └── bst.c
│   │   └── graph/
│   │       └── graph.c
│   │
│   └── algorithms/
│       ├── search/
│       │   └── search.c
│       ├── sort/
│       │   └── sort.c
│       ├── tree/
│       │   └── tree.c
│       └── graph/
│           └── graph.c
│
├── tests/
│   ├── data_structures/
│   │   ├── test_array.c
│   │   ├── test_linked_list.c
│   │   └── ...
│   │
│   └── algorithms/
│       ├── test_search.c
│       ├── test_sort.c
│       └── ...
│
├── docs/
│   ├── data_structures/
│   │   ├── array/
│   │   │   ├── theory.md
│   │   │   ├── memory.md
│   │   │   ├── operations.md
│   │   │   └── complexity.md
│   │   ├── linked_list/
│   │   └── ...
│   │
│   └── algorithms/
│       ├── searching/
│       ├── sorting/
│       └── ...
│
└── examples/
    ├── array/
    ├── linked_list/
    ├── sorting/
    └── ...
```

## Directory Overview

### `include/`

Contains the **public header files** of the library.

These define the interfaces that a user of the library will interact with.

For example:

```c
#include <dsalgo/data_structures/array.h>
```

The implementation details should generally remain outside of the public interface.

---

### `src/`

Contains the actual implementations.

The `data_structures/` directory contains implementations of structures such as:

* Dynamic arrays
* Linked lists
* Stacks
* Queues
* Hash tables
* Trees
* Heaps
* Graphs

The `algorithms/` directory contains algorithms that operate on appropriate data representations.

Examples include:

* Searching
* Sorting
* Tree algorithms
* Graph algorithms

Data structures and algorithms are intentionally separated where the algorithm is not inherently part of a particular structure.

---

### `tests/`

Contains tests for the library.

Tests will cover:

* Normal operations
* Boundary conditions
* Empty structures
* Single-element structures
* Large inputs
* Invalid operations
* Memory-related errors
* Algorithm correctness

Testing is considered part of the implementation rather than something added at the end.

---

### `docs/`

Contains the theoretical and implementation documentation.

The documentation is intended to go beyond describing the public API.

For a data structure, documentation may include:

```text
Theory
Memory representation
Invariants
Operations
Implementation decisions
Time complexity
Space complexity
Experiments
Design alternatives
```

For an algorithm, documentation may include:

```text
Problem
Input and output
Algorithm
Pseudocode
Correctness reasoning
Time complexity
Space complexity
Applicable data structures
Trade-offs
Implementation notes
```

The goal is to document **why the implementation works**, not only how to use it.

---

### `examples/`

Contains small programs demonstrating how the library can be used.

These examples should remain simple and focus on the public API.

---

# Data Structures

The library will progressively implement structures including:

* Arrays
* Dynamic arrays
* Singly linked lists
* Doubly linked lists
* Stacks
* Queues
* Deques
* Hash tables
* Heaps
* Binary search trees
* Balanced trees
* Tries
* Graphs
* Union-Find / Disjoint Set Union
* Segment trees
* Fenwick trees

Additional and more advanced structures may be added as the project develops.

---

# Algorithms

The algorithm portion of the library will cover areas including:

* Searching
* Sorting
* Selection
* Array algorithms
* Linked-list algorithms
* Tree algorithms
* Heap algorithms
* Graph traversal
* Shortest paths
* Minimum spanning trees
* Dynamic programming
* Greedy algorithms
* Backtracking
* String algorithms
* Number-theoretic algorithms
* Computational geometry
* Randomized algorithms

The complete study scope is maintained separately as the project's master topic list.

---

# Memory-Level Approach

A central objective of this project is to understand what is happening beneath the data-structure abstraction.

For example, a linked list should not simply be understood as:

> "A collection of nodes connected by pointers."

The implementation will investigate questions such as:

* How large is a node in memory?
* Where is the node allocated?
* What does the pointer actually contain?
* How are two nodes connected?
* What happens during insertion?
* What happens during deletion?
* Who owns the allocated memory?
* When is memory released?
* What happens when allocation fails?
* What invariants must remain true?

The same approach will be applied to arrays, hash tables, trees, graphs, and other structures.

---

# Complexity

Every major operation will be analyzed in terms of:

* Time complexity
* Space complexity
* Worst-case behavior
* Average-case behavior where relevant
* Amortized complexity where relevant

The goal is to derive these properties from the implementation rather than simply memorize complexity tables.

---

# Engineering Practices

As the project grows, it will also explore practical aspects of building a C library:

* Header/source separation
* Compilation and linking
* Static libraries
* Makefiles
* Testing
* Debugging
* Sanitizers
* Memory debugging
* Benchmarking
* API design
* Generic programming in C
* Error handling
* Documentation
* Git and version control
* Continuous integration

---

# Development Philosophy

The implementation of a topic will generally follow this process:

```text
Study the concept
      ↓
Design the representation
      ↓
Implement from scratch
      ↓
Test
      ↓
Investigate memory behavior
      ↓
Analyze complexity
      ↓
Document
      ↓
Compare with established implementations
      ↓
Refine the implementation
```

Existing implementations are not treated as something to avoid. They are valuable references for discovering better designs, edge cases, trade-offs, and engineering practices.

The goal is to **understand first, compare second, and improve continuously**.

---

# Project Status

This project is being developed incrementally as a long-term study and engineering project.

The initial focus is on building a strong foundation with:

1. C memory management
2. Dynamic arrays
3. Linked lists
4. Stacks
5. Queues
6. Searching
7. Sorting
8. Hash tables
9. Trees
10. Graphs
11. Fundamental algorithms

More advanced structures and algorithms will be added after the foundations are well understood.

---

## Why This Project Exists

The purpose of this project is not to create something that has never existed before.

Data structures and algorithms have been studied and implemented extensively by computer scientists and engineers for decades.

The purpose is to **rebuild these ideas independently**, understand their internal mechanics, and develop a deeper understanding of computer science through implementation.

This project is therefore both a **C library** and a **long-term study of data structures, algorithms, memory, and software engineering**.
