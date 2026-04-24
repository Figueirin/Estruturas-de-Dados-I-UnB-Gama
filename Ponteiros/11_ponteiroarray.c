#include <stdio.h>

void modificaArray(int *p, int tamanho){

    for(int i = 0; i < tamanho; i++){
        p[i] = p[i] * 2;
        printf("%d\n", p[i]);
    }
}

int main(){

    int array[5] = {1,2,3,4,5};
    int *p = array;

    modificaArray(array, 5);

    return 0;

}