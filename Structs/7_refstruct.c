#include <stdio.h>

typedef struct{

    char nome[50];
    float preco;
    int qtd_estoque;
} produto;

void atualizarProduto(produto *p){

    p -> preco *= 1.10;
    p -> qtd_estoque -= 1;

    printf("Nome: %s\nPreco: %.2f\nQuantidade de Estoque: %d", p->nome, p->preco, p->qtd_estoque);
}

int main(){

    produto p1 = {"Vanish", 31.99, 3486};

    atualizarProduto(&p1);
    return 0;
}