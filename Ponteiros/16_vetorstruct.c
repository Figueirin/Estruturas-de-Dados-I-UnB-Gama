#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    char nome[100];
    float nota;
    int matricula;

} Aluno;

int main(){

    Aluno turma[3];

    Aluno *ptr = turma;

    strcpy(ptr->nome, "Renato");
    ptr->matricula = 101;
    ptr->nota = 7.00;

    strcpy((ptr + 1)->nome, "Velho");
    (ptr + 1)->matricula = 102;
    (ptr + 1)->nota = 10.00;

    strcpy((ptr + 2)->nome, "Mexicano");
    (ptr + 2)->matricula = 103;
    (ptr + 2)->nota = 8.50;

    for(int i = 0; i < 3; i++){
        printf("Nome: %s\n", (ptr + i)->nome);
        printf("Matricula: %d\n", (ptr + i)->matricula);
        printf("Nota: %.2f\n", (ptr + i)->nota);
    }

    return 0;

}
