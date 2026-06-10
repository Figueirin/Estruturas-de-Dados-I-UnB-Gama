#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

void resetar(TTemperaturas *controle){

    if(controle -> medidas != NULL){
        free(controle -> medidas);
        controle -> medidas = NULL;
    }

    printf("Digite a quantidade de dias para registro: ");
    int res = scanf("%d", &controle -> qtde_dias);
    if(res == EOF){
        controle -> qtde_dias = 0;
        return;
    }
    if(res != 1){
        printf("A quantidade de dias deve ser um numero valido!\n");
        int c;
        while((c = getchar()) != '\n' && c != EOF);
        controle -> qtde_dias = 0;
        return;
    }
    if(controle -> qtde_dias <= 0){
        printf("A quantidade de dias deve ser maior que zero!\n");
        controle -> qtde_dias = 0;
        return;
    }

    controle -> medidas = (TMedidas *) malloc(controle -> qtde_dias * sizeof(TMedidas));

    if(controle -> medidas == NULL){
        printf("Erro de alocacao da memoria\n");
        controle -> qtde_dias = 0;
        controle -> qtde_medidas = 0;
        return;
    }

    controle -> qtde_medidas = 0;
    printf("Vetor resetado e alocado para %d dias\n", controle -> qtde_dias);
}

void inserirMedidas(TTemperaturas *controle){

    if (controle -> medidas == NULL){
        printf("Erro: O vetor nao foi inicializado, para isso digite 1 antes\n");
        return;
    }

    if(controle -> qtde_medidas >= controle -> qtde_dias){
        printf("Erro: Limite de dias (%d) atingido\n", controle -> qtde_dias);
        return;
    }

    int idx = controle -> qtde_medidas;

    printf("Digite a cidade: ");
    int res_cidade = scanf(" %19[^\n]", controle -> medidas[idx].cidade);
    if(res_cidade == EOF){
        return;
    }
    if(res_cidade != 1){
        printf("Erro ao ler o nome da cidade!\n");
        int c;
        while((c = getchar()) != '\n' && c != EOF);
        return;
    }
    // Consumir qualquer caractere extra ou o newline que sobrou da cidade
    int c;
    while((c = getchar()) != '\n' && c != EOF);

    printf("Digite a temperatura: ");
    int res_temp = scanf("%f", &controle->medidas[idx].temperatura);
    if(res_temp == EOF){
        return;
    }
    if(res_temp != 1){
        printf("Temperatura invalida! Digite um numero decimal.\n");
        while((c = getchar()) != '\n' && c != EOF);
        return;
    }

    controle->qtde_medidas++;
    printf("Medida cadastrada com sucesso!\n");
}

void mostrarEstatistica(TTemperaturas *controle){

    if(controle -> medidas == NULL || controle -> qtde_medidas == 0){
        printf("Nenhuma medida cadastrada para criar a estatistica. \n");
        return;
    }

    float soma = 0;
    int indiceMin = 0;
    int indiceMax = 0;

    for(int i = 0; i < controle -> qtde_medidas; i++){
        soma += controle -> medidas[i].temperatura;

        if(controle -> medidas[i].temperatura < controle -> medidas[indiceMin].temperatura){
            indiceMin = i;
        }

        if(controle -> medidas[i].temperatura > controle -> medidas[indiceMax].temperatura){
            indiceMax = i;
        }
    }

    float media = soma / controle -> qtde_medidas;

    printf("=== Estatisticas ===\n");
    printf("Temperatura Media: %.2f C\n", media);
    printf("Menor Temperatura: %.2f C (%s)\n", controle -> medidas[indiceMin].temperatura, controle -> medidas[indiceMin].cidade);
    printf("Maior Temperatura: %.2f C (%s)\n", controle -> medidas[indiceMax].temperatura, controle -> medidas[indiceMax].cidade);
}

void liberarMemoria(TTemperaturas *controle){
    if (controle -> medidas != NULL){
        free(controle -> medidas);
        controle -> medidas = NULL;
        printf("Memoria desalocada com sucesso.\n");
    }
}

int main(){

    TTemperaturas controle;
    controle.medidas = NULL;
    controle.qtde_dias = 0;
    controle.qtde_medidas = 0;

    int opcao = 0;

    while(opcao != 4){
        printf("\n=== Gerenciador de Temperatura de Cidades ===\n");
        printf("1. Resetar o vetor de medidas\n");
        printf("2. Inserir Medida\n");
        printf("3. Estatistica das Cidades\n");
        printf("4. Sair\n");
        printf("=== Gerenciador de Temperatura de Cidades ===\n");

        int res_op = scanf("%d", &opcao);
        if(res_op == EOF){
            liberarMemoria(&controle);
            printf("Saindo...\n");
            break;
        }
        if(res_op != 1){
            printf("Entrada invalida! Digite um numero.\n");
            int c;
            while((c = getchar()) != '\n' && c != EOF);
            continue;
        }

            switch(opcao){
                case 1:

                    resetar(&controle);
                    break;
                case 2:

                    inserirMedidas(&controle);
                    break;
                case 3:

                    mostrarEstatistica(&controle);
                    break;
                case 4:

                    liberarMemoria(&controle);
                    printf("Saindo...");
                    break;

                default:
                    printf("Opcao Invalida\n");
                    break;
            }
        }
    
    return 0;
}