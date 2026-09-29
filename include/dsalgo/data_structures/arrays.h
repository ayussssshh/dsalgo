#if !defined(ARRAYS_h)
#define ARRAYS_h

#include <stddef.h>


// S_array means static array

typedef struct {
    void *data;
    size_t element_size;
    size_t length;
} S_array;


S_array *Sarray_create(size_t element_size, size_t length);

void Sarray_destroy(S_array *array);


#endif // ARRAYS_h
