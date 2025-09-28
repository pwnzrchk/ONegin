#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

void swap(void* p1, void* p2, size_t size) {       //memcpy для разных типов
    assert(p1);
    assert(p2);
    
    void* buffer = malloc(size);
    memcpy(buffer, p1, size);
    memcpy(p1, p2, size);
    memcpy(p2, buffer, size);

}

