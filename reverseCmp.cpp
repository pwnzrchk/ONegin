#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "reverseCmp.h"

int letterCmp(char par1, char par2) {
    return (int)par1 - (int)par2;
}

int reverseStrCmp(const void* s1, const void* s2) {

    assert(s1 != NULL);
    assert(s2 != NULL);

    const char* str1 = *(const char**)s1;
    const char* str2 = *(const char**)s2;

    assert(str1 != NULL);
    assert(str2 != NULL);


    size_t size1 = strlen(str1);
    size_t size2 = strlen(str2);

    if (size1 == 0 || size2 == 0)
    return (int)(size1 >= size2 ? size1 : size2);

    size_t i = 1;
    while (letterCmp(str1[size1 - i], str2[size2 - i]) == 0) {
        i++;
        if (i == (size2 > size1 ? size1 :  size2)) {
            return 0;
        }
    }
    return letterCmp(str1[size1 - i], str2[size2 - i]);
}
