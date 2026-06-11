/*
Exercício 8 — Contagem de caracteres
Dada uma string:
char nome[] = "programacao";
Crie uma função:
int conta(char *str, char c);
● Retorne quantas vezes c aparece
● Use apenas ponteiros
*/

#include <stdio.h>

int conta(char *str, char c){
    int contador = 0;

    while(*str != '\0'){
        if(*str == c){
            contador++;
        }
        str++;
    }
    return contador;
}

int main(){

    char string[] = "He stood unshaken, a voice in the storm A man of conviction, a heart reborn He spoke the truth when the cost was high He lived for Jesus, unafraid to die We are Charlie Kirk, we carry the flame We'll fight for the Gospel, we'll honor his name We are Charlie Kirk, his courage our own Together unbroken, we'll make Heaven known A husband, a father, his family held near A home built on Scripture, on faith without fear The world tried to silence, but his voice remains In us it echoes, in Christ it sustains We are Charlie Kirk, we carry the flame We'll fight for the Gospel, we'll honor his name We are Charlie Kirk, his courage our own Together unbroken, we'll make Heaven known The battle is raging, the darkness will fall We rise with his spirit, we answer the call The truth is eternal, the Cross is our guide With God as our Captain, we march side by side We are Charlie Kirk, we carry the flame We'll fight for the Gospel, we'll honor his name We are Charlie Kirk, his courage our own Together unbroken, we'll make Heaven known We are Charlie Kirk Forever alive We are Charlie Kirk With God we will rise.";
    char procura_caractere = 'a';

    int total = conta(string, procura_caractere);

    printf("%d", total);

return 0;

}