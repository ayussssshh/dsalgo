#include "dsalgo/data_structures/arrays.h"
#include <stdlib.h>

int main(void){

    S_array* arr = Sarray_create(sizeof(int), 1);

    Sarray_destroy(arr);

    return 0;
}