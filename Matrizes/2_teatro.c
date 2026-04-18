#include <stdio.h>

void reservaAssento(int poltrona[][20]){

    int fileira, assento, flag1 = 1, flag2 = 1, flag3 = 1;
    while(flag3 != 0){
        while(flag1 != 0){
        printf("Em qual fileira quer reservar?\n");
        scanf(" %d", &fileira);
            if(fileira >= 0 && fileira < 15){
                printf("Valido\n");
                flag1 = 0;
            } else {
                printf("Invalido\n");
            }
        }
        while(flag2 != 0){
        printf("Em qual assento quer reservar?\n");
        scanf(" %d", &assento);
            if(assento >= 0 && assento < 20){
                printf("Valido\n");
                flag2 = 0;
            } else {
                printf("Invalido\n");
            }
        }

        if(poltrona[fileira][assento] == 0){
            poltrona[fileira][assento] = 1;
            printf("Reservado com sucesso!\n");
            flag3 = 0;
        } else {
            printf("Este lugar ja esta reservado!\n");
            flag1 = 1;
            flag2 = 1;
        }
    }
}

int main(){
    int poltronas[15][20], opcao;
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 20; j++){
            poltronas[i][j] = 0;
        }
    }
    while (opcao != 3){
        printf("Bem vindo ao menu de reservas!\n");
        printf("Ver assentos disponiveis - Tecle 1\n");
        printf("Reservas de assento - Tecle 2\n");
        printf("Sair - Tecle 3\n");
        scanf(" %d", &opcao);
        
    switch(opcao){

        case 1:
        printf("Assentos do Teatro\n");
            for(int i = 0; i < 15; i++){
                for(int j = 0; j < 20; j++){
                    printf("%d ", poltronas[i][j]);
                }
                printf("\n");
            }
            break;

        case 2:
            reservaAssento(poltronas);
            break;
            
        case 3:
            printf("Sair\n");
            break;

        default:
            printf("Opcao invalida\n");
            break;
        }
    }
    return 0;
}