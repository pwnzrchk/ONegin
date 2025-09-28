#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "COUNT.H"
#include "massFill.H"
#include "sort1.H"
#include "FileReader.H"
#include "swap.h"

int letterCmp(char par1, char par2) {
    return (int)par1 - (int)par2;
}

int reverseStrCmp (const void* s1, const void* s2) {
    char* str1 = *(char**)s1;
    char* str2 = *(char**)s2;
    size_t size1 = strlen(str1);
    size_t size2 = strlen(str2);

    size_t i = 0;
    if (letterCmp(str1[size1 - i], str2[size2 - i]) == 0) {
        i++;
        if (i == (size2 > size1 ? size1 :  size2)) {
            return 0;
        }
    } else
    return letterCmp(str1[size1 - i], str2[size2 - i]);

}
