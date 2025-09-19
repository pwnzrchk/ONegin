#ifndef READER_H
#define READER_H


#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stddef.h>
#include "COUNT.H"


    void TextParser (const char* file_name, char** buffer, long long* file_size, size_t* strokes);


#endif
