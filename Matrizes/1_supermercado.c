#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void aumentarEstoque(int estoque[], int produto){
    printf("Quantos deseja adicionar? ao %d\n", produto);
    int qtd;
    scanf(" %d", &qtd);
    estoque[produto] += qtd;
    printf("Estoque atualizado: %d\n", estoque[produto]);
}

void diminuirEstoque(int estoque[], int produto){
    int qtd;
    printf("Quantos deseja retirar? ao %d\n", produto);
    scanf(" %d", &qtd);
    estoque[produto] -= qtd;
    printf("Estoque atualizado: %d\n", estoque[produto]);
}

int main(){
    int estoque[10], opcao = 0, produto;
    srand(time(NULL));

    for(int i = 0; i < 10; i++){
        estoque[i] = rand() % 100;
    }

    while (opcao != 4){
    printf("ESTOQUE MERCADO\n");
    printf("Ver estoque tecle 1\n");
    printf("Adicionar ao estoque tecle 2\n");
    printf("Remover do estoque tecle 3\n");
    printf("Sair tecle 4\n");
    scanf(" %d", &opcao);

    switch(opcao){
        case 1:
            printf("Ver estoque\n");
            for(int i = 0; i < 10; i++){
                printf("Produto %d: %d\n", i, estoque[i]);
            }
            break;
        case 2:
            printf("Adicionar ao estoque\n");
            printf("Qual produto deseja adicionar?\n");
            for(int i = 0; i < 10; i++){
                printf("Produto %d: %d\n", i , estoque[i]);
            }
            printf("Digite o numero do produto:\n");
            scanf(" %d", &produto);
            aumentarEstoque(estoque,produto);
            break;
        
        case 3:
            printf("Remover do estoque\n");
            printf("Qual produto deseja retirar?\n");
            for(int i = 0; i < 10; i++){
                printf("Produto %d: %d\n", i , estoque[i]);
            }
            printf("Digite o numero do produto:\n");
            scanf(" %d", &produto);
            diminuirEstoque(estoque, produto);
            break;
        case 4:
            printf("Sair\n");
            break;

        default:
            printf("Opcao invalida\n");
            break;
        }
    }
    return 0;
}