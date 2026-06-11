/*
🔹 Exercício 11 — Comparação de strings
Implemente sua própria versão de:
int compara(char *s1, char *s2);
● Retorne:
○ 0 se iguais
○ <0 se s1 < s2
○ 0 se s1 > s2
Sem usar strcmp
Observações a serem seguidas:
● Evitar uso de indexação (v[i]) sempre que possível
● Use as opções abaixo:
○ *p
○ p++
○ *(p+i)
● Atente para a distinção entre:
○ valor
○ endereço
○ conteúdo apontado
○ endereço da variável
○ valor armazenado no ponteiro
○ valor apontado pelo ponteiro
*/

#include <stdio.h>

int compara(char *s1, char *s2){

    while(*s1 != '\0' && *s1 == *s2){
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

int main(){

    char string1[100];
    char string2[100];

    fgets(string1, 100, stdin);
    fgets(string2, 100, stdin);

    int res = compara(string1, string2);
    printf("%d", res);

    return 0;
}