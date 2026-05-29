#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fp;

    int ch; int caracteres = 0; int espacos = 0; int tabs = 0; int newlines = 0; char nomeArquivo[100];

    printf("Digite o nome do arquivo\n");
    scanf("%s", nomeArquivo);

    fp = fopen(nomeArquivo, "r");

    if(fp == NULL){
        printf("Erro ao abrir o arquivo \n");
        return 1;
    }

    while((ch = fgetc(fp)) != EOF){
        caracteres++;
         
        if(ch == ' '){
            espacos++;
        } else if (ch == '\t'){
            tabs++;
        } else if (ch == '\n'){
            newlines++;
        }
    }

    fclose(fp);

    printf("Resultado da contagem\n");
    printf("Total de Caracteres %d\n", caracteres);
    printf("Total de espaços: %d\n", espacos);
    printf("Total de tabs: %d\n", tabs);
    printf("Total de Newlines: %d\n", newlines);

    return 0;
}