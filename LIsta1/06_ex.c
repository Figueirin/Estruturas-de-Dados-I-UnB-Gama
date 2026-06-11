/*
Exercício 6 — Modificação por função
Implemente uma função:
void dobra(int *x);
● A função deve dobrar o valor de x
● Teste na main
Verifique: o que acontece se passar sem ponteiro?
*/

#include <stdio.h>

void dobra(int *x){

    *x *= 2;
    printf("%d\n", *x);
}

int main(){

    int A = 10;
    int *p = &A;

    dobra(p);

    /* 
    Se eu passar um inteiro que nao seja ponteiro, ele vai criar uma copia x na dobra(), 
    e quando voltar pra main ela vai ser destruida
    */

    return 0;
}