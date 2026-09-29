# `Sarray_create`

## Declaration

```c
S_array *Sarray_create(size_t element_size, size_t length);
```

## Purpose

Creates a new `S_array` and allocates the memory required to store its elements.

## Parameters

### `element_size`

The size of one element in bytes.

Usually obtained using `sizeof`:

```c
sizeof(int)
sizeof(double)
sizeof(MyStruct)
```

### `length`

The number of elements the array will contain.

For example:

```c
Sarray_create(sizeof(int), 10);
```

creates storage for:

```text
10 × sizeof(int)
```

bytes.

## Return Value

Returns a pointer to the newly created `S_array`.

If allocation of the `S_array` structure fails, the function returns `NULL`.

If allocation of the element storage fails, the function releases the previously allocated `S_array` and returns `NULL`.

## Memory Ownership

The returned `S_array` owns two allocations:

```text
1. The S_array structure
2. The memory referenced by S_array.data
```

Both allocations must eventually be released.

A dedicated destruction function should be added to the API to handle this.

## Example

```c
S_array *arr = Sarray_create(sizeof(int), 10);
```

The resulting structure represents:

```text
element_size = 4
length       = 10
data         ───────► 40 bytes of element storage
```

assuming `sizeof(int) == 4`.

## Current Implementation

```c
S_array *Sarray_create(size_t element_size, size_t length)
{
    S_array *arr = malloc(sizeof(S_array));

    if (arr == NULL)
    {
        return NULL;
    }

    arr->data = malloc(length * element_size);

    if (arr->data == NULL)
    {
        free(arr);
        return NULL;
    }

    arr->element_size = element_size;
    arr->length = length;

    return arr;
}
```

## Complexity

### Time

**O(1)** with respect to the number of elements, excluding the underlying memory-allocation cost.

The function does not initialize each element individually.

### Space

**O(n)** where `n` is the number of elements, because it allocates:

```text
n × element_size
```

bytes of storage.
