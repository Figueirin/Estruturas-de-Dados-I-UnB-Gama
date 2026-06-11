/*
Exercício 4 — Swap manual (sem função)
● Declare duas variáveis inteiras
● Use ponteiros para trocar os valores dentro da main
● Não use variável auxiliar tradicional (use manipulação via ponteiros)
*/

#include <stdio.h>

int main(){

    int A = 10, B = 20;
    int *p1, *p2;

    p1 = &A;
    p2 = &B;

    printf("Antes\n");
    printf("A: %d\nB: %d\n", *p1, *p2);

    *p1 = *p1 + *p2;
    *p2 = *p1 - *p2;
    *p1 = *p1 - *p2;

    printf("Depois\n");
    printf("A: %d\nB: %d\n", *p1, *p2);

    return 0;
}