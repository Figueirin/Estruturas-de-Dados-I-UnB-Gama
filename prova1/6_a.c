#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

int main() {
    Produto p1, p2;

    strcpy(p1.nome, "Arroz");
    p1.preco = 5.99;
    p1.quantidade = 10;

    strcpy(p2.nome, "Feijao");
    p2.preco = 8.49;
    p2.quantidade = 5;

    // --- escrita ---
    FILE *arq = fopen("produtos.txt", "w");
    fprintf(arq, "%s %.2f %d\n", p1.nome, p1.preco, p1.quantidade);
    fprintf(arq, "%s %.2f %d\n", p2.nome, p2.preco, p2.quantidade);
    fclose(arq);

    // --- leitura ---
    arq = fopen("produtos.txt", "r");
    char nome[50];
    float preco;
    int qtd;

    while (fscanf(arq, "%49s %f %d", nome, &preco, &qtd) == 3) {
        printf("Nome: %-15s Preco: R$ %.2f  Qtd: %d\n", nome, preco, qtd);
    }
    fclose(arq);

    return 0;
}