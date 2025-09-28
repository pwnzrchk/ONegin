#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "swap.h"
#include "reverseCmp.h"
#include "swap.h"

void bubbleSort(void* arr, size_t size, size_t elmt, int (*comparator)(const void* par1, const void* par2)) {

    assert(arr != NULL);
    assert(size > 0);
    assert(elmt > 0);

    char** char_arr = (char**)arr;

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (comparator(((char*)arr + j*elmt), ((char*)arr + (j+1)*elmt) < 0)) {
                void* 
                swap(&char_arr[j], &char_arr[j+1]);
            }
        }
    }
}
