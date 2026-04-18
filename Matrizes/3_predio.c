#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seletorSala(int predio[][10][24]){

    int andar, sala;
    int flag1 = 1, flag2 = 1;
    while(flag1 != 0){
        printf("Selecione o Andar {0 a 4}\n");
        scanf(" %d", &andar);
            if(andar >= 0 && andar < 5){
                printf("Andar valido\n");
                flag1 = 0;
            } else {
                printf("Andar invalido\n");
                }
            }
    while(flag2 != 0){
        printf("Selecione a Sala {0 a 9}\n");
        scanf(" %d", &sala);
            if(sala >= 0 && sala < 10){
                printf("Sala valida\n");
                flag2 = 0;
            } else {
                printf("Sala invalida\n");
            }
        }
    printf("A temperatura da sala selecionada durante o dia foi:\n"); 
    for(int i = 0; i < 24; i++){
        printf("Hora %d: %d graus\n", i + 1, predio[andar][sala][i]);
    }
}

void calcularTempMedia(int predio[][10][24]){

    int temperatura = 0, andar, flag1 = 1;
    float temperatura_media;

    while(flag1 != 0){
        printf("Selecione o Andar para AFERIR a TEMP media {0 a 4}\n");
        scanf(" %d", &andar);
            if(andar >= 0 && andar < 5){
                printf("Andar valido\n");
                flag1 = 0;
            } else {
                printf("Andar invalido\n");
                }
            }
    
    for(int j = 0; j < 10; j++){
        for(int k = 0; k < 24; k++){
            temperatura += predio[andar][j][k];
            }
        }

    temperatura_media = temperatura / 240.0;
    printf("A temperatura media de TODAS as salas foi %.2f!\n", temperatura_media);    
}

int main(){
    
    int predio[5][10][24] = {{{0}}},  opcao = 0;
    srand(time(NULL));

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 24; k++){
                predio[i][j][k] = (rand() % 26) + 15;
            }
        }
    }

    while(opcao != 4){

        printf("==============================================\n");
        printf("Aferidor de Temperaturas Aleatorias do Renatao\n");
        printf("Conferir TODAS as Temperaturas do Predio - Tecle 1\n");
        printf("Para selecionar o Andar e a Sala - Tecle 2\n");
        printf("Para ver a temperatura media de cada ANDAR - Tecle 3\n");
        printf("Para Sair - Tecle 4\n");
        printf("==============================================\n");
        scanf(" %d", &opcao);

        switch(opcao){

            case 1:
                for(int i = 0; i < 5; i++){
                printf("\n");
                printf("Andar %d: ", i + 1);
                printf("\n");
                for(int j = 0; j < 10; j++){
                    printf("\n");
                    printf("Sala %d: ", j + 1);
                    for(int k = 0; k < 24; k++){
                        printf("%d " ,predio[i][j][k]);
                    }
                }
            }
                printf("\n");
                break;
            case 2:
                seletorSala(predio);
                break;
            case 3:
                calcularTempMedia(predio);
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