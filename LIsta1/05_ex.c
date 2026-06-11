/*
Exercício 5 — Vetor com ponteiros
Dado um vetor:
int v[5] = {10, 20, 30, 40, 50};
Faça:
● Percorra usando ponteiro (não use índice)
● Imprima os valores
● Some todos os elementos usando apenas aritmética de ponteiros
Dica: use *(p + i) ou incremento de ponteiro
*/

#include <stdio.h>

int main(){

    int v[5] = {10, 20, 30, 40, 50};
    int *p = v;

    for (int i = 0; i < 5; i++){
        printf("%d ", *(p + i));
    }

    return 0;
}