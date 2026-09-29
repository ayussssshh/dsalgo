# S_array

## Status

**In development**

## Data Structure

Static Array

## Purpose

`S_array` is a generic fixed-length array structure implemented in C.

The structure stores a contiguous block of memory for a fixed number of elements. The type of the elements is not stored explicitly; instead, the structure stores the size of each element in bytes.

This allows the same structure to store different C types such as:

* `int`
* `double`
* `char`
* user-defined `struct` types

## Current Implementation

The current implementation supports:

* Creating an `S_array`
* Allocating memory for its elements
* Storing the element size
* Storing the array length

The following operations have **not yet been implemented**:

* Element access
* Element modification
* Element copying
* Element swapping
* Array copying
* Array destruction through a dedicated API
* Other array operations

## Memory Representation

An `S_array` contains three fields:

```c
typedef struct {
    void *data;
    size_t element_size;
    size_t length;
} S_array;
```

### Fields

| Field          | Meaning                                       |
| -------------- | --------------------------------------------- |
| `data`         | Pointer to the memory containing the elements |
| `element_size` | Size of one element in bytes                  |
| `length`       | Number of elements                            |

The structure itself and its element storage are separate allocations:

```text
S_array
┌──────────────────────┐
│ data ────────────────┼──────────► element storage
│ element_size         │
│ length               │
└──────────────────────┘
```

## Design Constraint

The implementation does not use a C array as its underlying storage.

C's memory-management facilities are used as primitives, while the array abstraction and its operations are implemented by this library.
