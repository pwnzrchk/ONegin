#ifndef bubbleSort_h
#define bubbleSort_h

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "swap.h"
#include "reverseCmp.h"


void bubbleSort(void* arr, size_t size, size_t elmt, int comparator(const void* par1, const void* par2));

#endif //bubbleSort.h
