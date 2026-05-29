#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    char nome[20];
    float preco;
} Produto;

int main(){

    Produto p1;

    Produto *ptr;

    ptr = &p1;

    fgets(ptr->nome, 20, stdin);
    scanf("%f", &ptr->preco);

    printf("Nome: %s\n", ptr->nome);
    printf("Valor: %.2f\n", ptr->preco);

    return 0;

}