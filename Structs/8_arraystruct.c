#include <stdio.h>

struct aluno{

    char nome[50];
    float nota1;
    float nota2;
    float nota3;
};

int main(){

    struct aluno turma[3];
    float nota_media;

    turma[0] = (struct aluno){"Renato", 8.0, 8.5, 10};
    turma[1] = (struct aluno){"Velho", 7.5, 1.4, 5.3};
    turma[2] = (struct aluno){"Caua Bessa", 9.0, 6.3, 1.0};

    for(int i = 0; i < 3; i++){
        nota_media = (turma[i].nota1 + turma[i].nota2 + turma[i].nota3) / 3;
        printf("Nome: %s\nNota Media %.2f\n", turma[i].nome, nota_media);
    }

    return 0;
}