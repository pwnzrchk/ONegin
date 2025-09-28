#ifndef FileReader_H
#define FileReader_H


#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stddef.h>
#include "countFun.H"


    void TextParser(char** buffer, long long* file_size, size_t* strokes, FILE* openedFile);


#endif //FileReader_H
