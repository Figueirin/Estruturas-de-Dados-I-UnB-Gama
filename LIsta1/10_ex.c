/*
Exercício 10 — Intercalação de vetores
Crie uma função:
void intercala(int *v1, int *v2, int *v3, int n);
● Intercale os elementos de v1 e v2 em v3
● Resultado: v3 com tamanho 2n
Exemplo:
v1 = [1,3,5]
v2 = [2,4,6]
v3 = [1,2,3,4,5,6]
👉 Regra: usar apenas aritmética de ponteiros
*/

#include <stdio.h>

void intercala(int *v1, int *v2, int *v3, int n){

    for(int i = 0; i < n; i++){
        *v3 = *v1;
        v3++;
        v1++;

        *v3 = *v2;
        v3++;
        v2++;
    }
}

int main(){

    int n = 3;
    int v1[] = [1,3,5];
    int v2[] = [2,4,6];
    int v3[n * 2];
    
    intercala(v1,v2,v3,n);

    for(int i = 0; i < n; i++){
        printf("%d", v3[i]);
    }
    printf("\n");

    return 0;
}