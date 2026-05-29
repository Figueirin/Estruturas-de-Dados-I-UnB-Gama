#include <stdio.h>
#include <stdlib.h>

typedef struct{

    char nome[100];
    float nota;
    
} Aluno;

int main(){

    Aluno a1 = {"Renato", 7.0};

    Aluno *ptr;

    ptr = &a1;

    printf("Nome: %s\nNota: %.2f\n", ptr->nome, ptr->nota);

    return 0;
}