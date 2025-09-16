#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void ordenar(int *ordenacao){

    int temp;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            if (ordenacao[j] > ordenacao[j + 1]){
                temp = ordenacao[j];
                ordenacao[j] = ordenacao[j + 1];
                ordenacao[j + 1] = temp;
            }
        }
    }
}

int main(){

    int *numeros = malloc(sizeof(int) * 3), temp;

    printf("Digite os números: \n");
    scanf("%d %d %d", &numeros[0], &numeros[1], &numeros[2]);

    ordenar(numeros);

    for (int i = 0; i < 3; i++){
        printf("%d ", *(numeros + i));
    }


    printf("\n");

    for (int i = 2; i >= 0; i--){
        printf("%d ", *(numeros + i));
    }

    return 0;
}