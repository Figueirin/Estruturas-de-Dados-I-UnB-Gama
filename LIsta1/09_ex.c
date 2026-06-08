#include <stdio.h>

void inverte(int *v, int tamanho){
    int *inicio = v;
    int *fim = v + (tamanho - 1);

    while (inicio < fim){
        int temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        inicio ++;
        fim--;
    }
}

int main(){

    int v[] = {1, 2, 3, 4, 5};
    int tamanho = 5;

    for(int i = 0; i < tamanho; i++){
        printf("%d ", v[i]);
    }

    inverte(v, tamanho);

    for(int i = 0; i < tamanho; i++){
        printf("%d ", v[i]);
    }

    return 0;
}