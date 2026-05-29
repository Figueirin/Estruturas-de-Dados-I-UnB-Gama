#include <stdio.h>
#include <stdlib.h>


typedef struct{

    char titulo[100];
    char autor[100];
    int ano;
} Livro;

int main(){

    Livro livro1 = {"Dom Casmurro", "Machado de Assis", 1899};

    Livro *ptr;

    ptr = &livro1;

    printf("Titulo: %s\n", ptr->titulo);
    printf("Autor %s\n", ptr->autor);
    printf("Ano %d\n", ptr->ano);

    return 0;

}