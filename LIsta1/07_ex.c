#include <stdio.h>

int maior(int *v, int tamanho){

    int maior_elemento = *(v + 0);
    for(int i = 0; i < tamanho; i++){
        if(*(v + i) > maior_elemento){
            maior_elemento = *(v + i);
        }
    }

    return maior_elemento;
}

int main(){
    
    int v[] = {10, 20, 30, 40, 50};
    int tamanho = 5;
    int *p = v;

    int res = maior(p, tamanho);

    printf("%d", res);

    return 0;
}