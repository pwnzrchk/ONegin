#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "countFun.H"
#include "FileReader.H"

long long fileSize(FILE* ishodnik) {

    struct stat file_info;
    fstat(fileno(ishodnik), &file_info);
    return file_info.st_size;
}

void TextParser(char** buffer, long long* file_size, size_t* strokes, FILE* openedFile) {

    *file_size = fileSize(openedFile);

    *buffer = (char*)calloc((size_t)*file_size + 1, sizeof(char));
    if (*buffer != NULL) {
        (*buffer)[*file_size] = '\0';
    }

    if (fread(*buffer, sizeof(char), (size_t)*file_size, openedFile) < (size_t)*file_size) {
        fprintf(stderr, "Прочитано меньше символов, чем в файле\n");
    }

    *strokes = (size_t)countSymb(*buffer, '\n', (size_t)*file_size) + 1;
    printf("\nCount of \\0: %zu\n\n", (size_t)countSymb(*buffer, '\0', (size_t)*file_size) + 1);

}
