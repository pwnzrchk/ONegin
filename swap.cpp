#include <stdio.h>
#include <stddef.h>
#include <assert.h>

void swap(void* p1, void* p2) {       //memcpy для разных типов
    assert(p1);                         //
    assert(p2);

    char* par1 = (char*)p1;
    char* par2 = (char*)p2;


}

