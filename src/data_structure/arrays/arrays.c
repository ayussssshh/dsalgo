#include "dsalgo/data_structures/arrays.h"
#include  <stdlib.h>
#include <stddef.h>
#include <stdio.h>




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





