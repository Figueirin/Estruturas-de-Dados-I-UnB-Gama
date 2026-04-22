#include <stdio.h>

struct carro{

    char modelo[50];
    int ano_fabricacao;
    char cor[30];
};

void imprimeCarro(struct carro C){

    printf("modelo: %s\nAno de Fabricacao: %d\ncor: %s\n", C.modelo, C.ano_fabricacao, C.cor);
}

int main(){

    struct carro carro1 = {"Chevette Marajo", 1982, "Prata azulado"};

    imprimeCarro(carro1);

    return 0;
}