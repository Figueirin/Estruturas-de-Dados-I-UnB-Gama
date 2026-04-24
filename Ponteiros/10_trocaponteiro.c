#include <stdio.h>

void trocaValor(int *a, int *b){

    int z = *a;
    *a = *b;
    *b = z;

    printf("a: %d\nb: %d\n", *a, *b);
}

int main(){

    int x = 17;
    int y = 21;

    trocaValor(&x,&y);

    return 0;
}