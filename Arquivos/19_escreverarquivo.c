#include <stdio.h>

int main(){

    FILE *origem; 
    FILE *destino;
    char nomeOrigem[100];
    char nomeDestino[100];
    int ch;

    printf("Digite o nome do arquivo a ser copiado\n");
    scanf("%s", nomeOrigem);

    printf("Digite o nome do arquivo de destino\n");
    scanf("%s", nomeDestino);

    origem = fopen(nomeOrigem, "r");

    if(origem == NULL){
        printf("Erro ao abrir o arquivo de origem");
        return 1;
    }

    destino = fopen(nomeDestino, "w");

    if(destino == NULL){
        printf("Erro ao criar o arquivo de destino");
        return 1;
    }

    while((ch = fgetc(origem)) != EOF){
        fputc(ch, destino);
    }

    fclose(origem);
    fclose(destino);

    printf("Arquivo copiadoo com sucesso");

    return 0;
}