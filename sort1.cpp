#include <stdio.h>
#include <string.h>

void BubleSort(char** PTR_ARR, size_t size_arr) {
    for (size_t i = 0; i < size_arr; i++) {
        for (size_t j = 0; j < size_arr - i - 1; j++) {
            if (strcmp(PTR_ARR[j], PTR_ARR[j+1]) > 0) {
                char* temp = PTR_ARR[j+1];
                PTR_ARR[j+1] = PTR_ARR[j];
                PTR_ARR[j] = temp;
            }
        }
    }
}
