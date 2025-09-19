#include <stdio.h>
#include <stdlib.h>
#include "COUNT.H"
#include "FILLING.H"
#include "SORT.H"
#include "READER.H"

int main() {

    const char* file_name = "thriller.txt";
    size_t str_count = 0;
    long long file_size = 0;
    char* BUFFR = NULL;
    TextParser(file_name, &BUFFR, &file_size, &str_count);

    char** TEXT_PTR = (char**)calloc(str_count, sizeof(char**));
    printf("Strcount: %zu\n\n", str_count);

    size_t strokesFilled = StrksToPtrs(BUFFR, TEXT_PTR, str_count);
    if (strokesFilled < str_count) {
        printf("Прочитано %zu строк из %zu\n", strokesFilled, str_count);
    }

    BubleSort(TEXT_PTR, str_count - 1);

    const char* FileOutName = "out.txt";
    FILE* FileOut = fopen(FileOutName, "w");

    for (size_t i = 0; i < str_count - 1; i++) {
        fprintf(FileOut, "%s\n", TEXT_PTR[i]);
    }
    fclose(FileOut);

    return 0;
}
