#include <stdio.h>
#include <string.h>

struct livros{

    char titulo[100];
    char autor[50];
    int ano_publicacao;
    int num_pagina;
};

int main(){

    struct livros livro1 = {"Memorias Postumas de Bras Cubas", "Machado de Assis", 1881, 368};

    struct livros livro2;
        livro2.ano_publicacao = 1943;
        livro2.num_pagina = 136;
        strcpy(livro2.titulo,"O pequeno principe");
        strcpy(livro2.autor, "Antoine de Saint-Exupery");

    printf("Titulo: %s\nAutor: %s\nAno: %d\nPaginas: %d\n", livro1.titulo, livro1.autor, livro1.ano_publicacao, livro1.num_pagina);
    printf("Titulo: %s\nAutor: %s\nAno: %d\nPaginas: %d\n", livro2.titulo, livro2.autor, livro2.ano_publicacao, livro2.num_pagina);

    return 0;
}