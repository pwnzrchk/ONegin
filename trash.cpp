#include <ctype.h>

size_t StrksToPtrs(char* BUF, char** PTR, size_t ptrsize) {

    size_t count = 0;
    PTR[count++] = BUF;

    for (size_t i = 0; count < ptrsize && BUF[i] != '\0'; i++) {
        if (BUF[i] == '\n') {

            BUF[i] = '\0';

            size_t j = i+1;

            while(!isalnum(BUF[j]) && BUF[j] != '\0') j++;

            if(BUF[j] != '\0' && BUF[j] != '\n') {
                PTR[count++] = &BUF[j];
                i = j - 1;
            }

            if(BUF[j] == '\0') {
                break;
            }
        }
    }
    return count;
}
