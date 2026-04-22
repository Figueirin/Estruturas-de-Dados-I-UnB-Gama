#include <stdio.h>

struct pessoa{

    char nome[50];
    int idade;
    float altura;
};

int main(){

    struct pessoa pessoa1 = {"Joao", 25, 1.80};

    printf("Nome: %s\nIdade: %d\nAltura: %.2f\n", pessoa1.nome, pessoa1.idade, pessoa1.altura);

    pessoa1.idade = 26;
    pessoa1.altura = 1.81;

    printf("Nome: %s\nIdade: %d\nAltura: %.2f\n", pessoa1.nome, pessoa1.idade, pessoa1.altura);
    
    return 0;
}