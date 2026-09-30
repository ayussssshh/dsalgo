#if !defined(ARRAYS_h)
#define ARRAYS_h

#include <stddef.h>

// S_array means static array

typedef struct
{
    void *data;
    size_t element_size;
    size_t length;
} S_array;

S_array *Sarray_create(size_t element_size, size_t length);

void Sarray_destroy(S_array *array);

void *Sarray_at(S_array *array, size_t index);

int Sarray_set(
    S_array *array,
    size_t index,
    const void *element);

int Sarray_get(
    const S_array *array,
    size_t index,
    void *out);

int Sarray_copy(
    const S_array *source,
    S_array *destination);

S_array *Sarray_clone(const S_array *source);

int Sarray_swap(        
    S_array *array,
    size_t index1,
    size_t index2
);


#endif // ARRAYS_h
