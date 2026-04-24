#include <stdio.h>

void imprimir(int *endereco){

    printf("%d", *endereco);
}

int main(){

    int num = 35;

    imprimir(&num);

    return 0;
}