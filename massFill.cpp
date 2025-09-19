#include <stdio.h>

size_t StrksToPtrs(char* BUF, char** PTR, size_t ptrsize) {

    size_t count = 0;
    PTR[count++] = BUF;

    for (size_t i = 0; count < ptrsize && BUF[i] != '\0'; i++) {
        if (BUF[i] == '\n') {

            BUF[i] = '\0';

            if(BUF[i+1] != '\0' && BUF[i+1] != '\n') {
                PTR[count++] = &BUF[i+1];
            }
        }
    }
    return count;
}
