#include <string.h>

char* replaceSpaces(char* S, int length){
    int p = strlen(S);
    for (int i = length - 1; i >= 0; i--) {
        if (S[i] == ' ') {
            S[--p] = 0 + '0';
            S[--p] = 2 + '0';
            S[--p] = '%';
        } else {
            S[--p] = S[i];
        }
    }
    return S + p;
}