#include <stdio.h>

int main(){

    int A = 10;
    int *p;

    p = &A;

    *p += 5;

    *p *= 2;

    printf("%d", *p);

    return 0;
}