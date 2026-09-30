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


---

# `Sarray_destroy`

## Declaration

```c
void Sarray_destroy(S_array *array);
````

## Purpose

Destroys an `S_array` and releases all dynamically allocated memory owned by it.

The function frees:

1. The memory allocated for the array elements.
2. The memory allocated for the `S_array` structure itself.

After calling this function, the `S_array` pointer must not be used.

## Parameters

### `array`

A pointer to the `S_array` to be destroyed.

The `S_array` must have been created using `Sarray_create()` and must not have already been destroyed.

## Return Value

This function does not return a value.

```c
void
```

## Memory Ownership

`Sarray_destroy()` releases both allocations owned by the `S_array`:

```text
S_array
   │
   ├──► S_array structure
   │
   └──► data ───────► element storage
```

The function first frees the memory referenced by `array->data` and then frees the `S_array` structure itself.

After the function returns, the pointer passed to `Sarray_destroy()` becomes invalid and must not be dereferenced.

## Example

```c
S_array *arr = Sarray_create(sizeof(int), 10);

/* use arr */

Sarray_destroy(arr);
```

Before destruction:

```text
arr
 │
 ▼
┌──────────────────────┐
│ S_array              │
│                      │
│ data ────────────────┼──────► element storage
│ element_size = 4     │
│ length = 10          │
└──────────────────────┘
```

After:

```c
Sarray_destroy(arr);
```

Both the `S_array` structure and its element storage have been released.

## Current Implementation

```c
void Sarray_destroy(S_array *array)
{
    free(array->data);
    free(array);
}
```

## Complexity

### Time

**O(1)** with respect to the number of elements.

The function performs a constant number of operations regardless of the array length.

The underlying `free()` operations may have implementation-dependent costs.

### Space

**O(1)** additional space.

The function does not allocate any additional memory while destroying the array.




