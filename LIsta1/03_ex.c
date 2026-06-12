/*
Exercício 3 — Incremento indireto
● Declare uma variável inteira
● Use um ponteiro para:
○ somar 5
○ multiplicar por 2
● Imprima o resultado final
Atenção: Não acessar diretamente a variável (somente via ponteiro).
*/

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