#include <stdio.h>
#include <string.h>
#include "swap.h"
#include <assert.h>
#include "reverseCmp.h"

void BubbleSort(char** ptr_arr, size_t size_arr) {

    assert(ptr_arr != NULL);
    assert(size_arr > 0);

    for (size_t i = 0; i < size_arr; i++) {
        for (size_t j = 0; j < size_arr - i - 1; j++) {
            if (reverseStrCmp(ptr_arr+j, ptr_arr+j+1) < 0) {
                swap(&ptr_arr[j], &ptr_arr[j+1]);
            }
        }
    }
}
