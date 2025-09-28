#include <stdio.h>
#include <assert.h>
size_t StrksToPtrs(char* BUF, char** PTR, size_t ptrsize) {

    assert(BUF != NULL && PTR != NULL && ptrsize > 0);
    size_t count = 0;
    PTR[count++] = BUF;

    for (size_t i = 0; count < ptrsize && BUF[i] != '\0'; i++) {
        if (BUF[i] == '\n') {

            BUF[i] = '\0';

            if(BUF[i+1] != '\0') {
                PTR[count++] = &BUF[i + 1];
            } else {
                break;                      
            }
        }
    }
    return count;
}
