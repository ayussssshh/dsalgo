#include "dsalgo/data_structures/arrays.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

// create a fixed lenght generic array(static array)
// element_size: size of element in bytes
// length: number element in array
// it returns a pointer to S_array struct

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

//  Destroys an S_array and releases all memory owned by it.
//  The function first releases the element storage pointed to by
//  array->data and then releases the S_array structure itself.

void Sarray_destroy(S_array *array)
{

    free(array->data);
    free(array);
}

// return the address of the element at given index
// work on the formula { Adress at index i = A + i*S }

void *Sarray_at(S_array *array, size_t index)
{
    if (index >= array->length)
    {
        return NULL;
    }

    return ((char *)array->data + (index * array->element_size));
}

// copy the given element in array a given index
// the caller must give the element of the same size as in array
// in success it returns 0, on fail it return -1

int Sarray_set(
    S_array *array,
    size_t index,
    const void *element)
{

    if (index >= array->length)
    {
        return -1;
    }

    void *place = Sarray_at(array, index);

    memcpy(place, element, array->element_size);

    return 0;
}

// it copy the element of array to a veriable.
// the caller must give the element of the same size as in array.
// in success it returns 0, on fail it return -1.

int Sarray_get(
    const S_array *array,
    size_t index,
    void *out)
{

    if (index >= array->length)
    {
        return -1;
    }

    memcpy(out, Sarray_at(array, index), array->element_size);

    return 0;
}

// it copy one array to another
// three if statment ara error handling
// in success it returns 0, on fail it return -1

int Sarray_copy(
    const S_array *source,
    S_array *destination)
{
    if (source->element_size != destination->element_size)
    {
        return -1;
    }

    if (source->length != destination->length)
    {
        return -1;
    }

    if (source == destination)
    {
        return 0;
    }

    memcpy(destination->data, source->data, (source->element_size * source->length));

    return 0;
}

// Creates a new S_array containing an independent copy
// of the source array.

// Returns NULL if allocation fails.

S_array *Sarray_clone(const S_array *source)
{

    S_array *destination = Sarray_create(source->element_size, source->length);

    if (destination == NULL)
    {
        return NULL;
    }

    int copy_status = Sarray_copy(source, destination);

    if (copy_status == -1)
    {
        Sarray_destroy(destination);
        return NULL;
    }

    return destination;
}

// swaps two element of given
// in success it returns 0, on fail it return -1

int Sarray_swap(
    S_array *array,
    size_t index1,
    size_t index2)
{
    if (index1 >= array->length || index2 >= array->length)
    {
        return -1;
    }

    void *element1 = Sarray_at(array, index1);
    void *element2 = Sarray_at(array, index2);
    void *temp = malloc(array->element_size);

    if (temp == NULL)
    {
        return -1;
    }

    memcpy(temp, element1, array->element_size);

    Sarray_set(array, index1, element2);
    Sarray_set(array, index2, temp);

    free(temp);

    return 0;
}
