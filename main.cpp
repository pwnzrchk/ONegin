#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "countFun.H"
#include "massFill.H"
#include "sort1.H"
#include "FileReader.H"
#include "swap.h"
#include "reverseCmp.h"
#include "bubbleSort.h"

struct filedInfo {
    const char* file_name;
    size_t str_count;
    long long file_size;
    char* buffr;
};

int main() {

    filedInfo file_par = {"input.txt", 0, 0, 0};

    FILE* file = fopen(file_par.file_name, "r");

    TextParser(&file_par.buffr, &file_par.file_size, &file_par.str_count, file);
    assert(file_par.buffr != NULL && file_par.file_size > 0 && file_par.str_count > 0);
    fclose(file);

    char** text_ptr = (char**)calloc(file_par.str_count, sizeof(char**));
    assert(text_ptr != NULL);

    printf("Strcount: %zu\n\n", file_par.str_count);

    size_t strokesFilled = StrksToPtrs(file_par.buffr, text_ptr, file_par.str_count);
    if (strokesFilled < file_par.str_count - 1) {
        fprintf(stderr, "Прочитано %zu строк из %zu\n", strokesFilled, file_par.str_count - 1);
    }

    //BubbleSort(text_ptr, file_par.str_count - 1);
    //bubbleSort(text_ptr, file_par.str_count - 1, sizeof(char*), reverseStrCmp);

    qsort(text_ptr, file_par.str_count - 1, sizeof(char*), reverseStrCmp);

    const char* FileOutName = "out.txt";
    FILE* FileOut = fopen(FileOutName, "w");

    for (size_t i = 0; i < file_par.str_count - 1; i++) {
        fprintf(FileOut, "%s\n", text_ptr[i]);
    }
    fclose(FileOut);

    return 0;
}
