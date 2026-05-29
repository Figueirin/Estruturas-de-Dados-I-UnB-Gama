#include <stdio.h>

int main(){

    char nome[50];
    int idade;
    float salario;
    
    FILE *arquivo;

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo de origem");
        return 1;
    }

    while(fscanf(arquivo, " %49[^;];%d;%f", nome, &idade, &salario) == 3){

        printf("nome: %s\nidade: %d\nsalario: %.2f\n", nome, idade, salario);
    }

    fclose(arquivo);

    arquivo == NULL;
    return 0;

    
}