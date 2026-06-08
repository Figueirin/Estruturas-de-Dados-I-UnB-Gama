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