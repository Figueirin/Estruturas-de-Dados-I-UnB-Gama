#include <stdio.h>
#include <stdlib.h>

typedef struct{

    char titulo[100];
    char autor[100];
    int ano;
}Livro;

int main(){

        Livro livro1;

        printf("Digite o titulo do livro: ");
        fgets(livro1.titulo, 100, stdin);

        printf("Digite o autor do livro: ");
        fgets(livro1.autor, 100, stdin);

        printf("Digite o ano do livro: ");
        scanf("%d", &livro1.ano);

        printf("Dados do livro:\n");
        printf("Titulo: %s", livro1.titulo);
        printf("Autor: %s", livro1.autor);
        printf("Ano: %d", livro1.ano);

    return 0;
}