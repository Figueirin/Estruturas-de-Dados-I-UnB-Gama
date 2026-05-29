#include <stdio.h>
#include <stdlib.h>

typedef struct{

    char nome[100];
    float nota;
    int matricula;

} Aluno;

int main(){

    Aluno turma[3];

    Aluno *ptr = turma;

    ptr->matricula = 101;
    ptr->nota = 7.00;

    (ptr + 1)->matricula = 102;
    (ptr + 1)->nota = 10.00;

    (ptr + 2)->matricula = 103;
    (ptr + 2)->nota = 8.50;

    printf("Matricula: %d\nNota: %.2f\n", ptr->matricula, ptr->nota);
    printf("Matricula: %d\nNota: %.2f\n", (ptr + 1)->matricula, (ptr + 1)->nota);
    printf("Matricula: %d\nNota: %.2f\n", (ptr + 2)->matricula, (ptr + 2)->nota);

    return 0;

}