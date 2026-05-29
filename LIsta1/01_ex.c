#include <stdio.h>

int main(){

    int a = 1;
    float b = 2;

    int *p1;
    float *p2;

    p1 = &a;
    p2 = &b;

    printf("valor de A %d\n", *p1);
    printf("Valor de B %f\n", *p2);

    return 0;
}