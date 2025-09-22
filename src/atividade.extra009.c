#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){

    int n;

    printf("Digite o tamanho da matriz\n");
    scanf("%d", &n);

    int *matriz = malloc(sizeof(int) * n * n);

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int min1 = i < j ? i : j;
            int min2 = (n-1-i) < (n-1-j) ? (n-1-i) : (n-1-j);
            int valor = 1 + (min1 < min2 ? min1 : min2);
            *(matriz + (i * n) + j) = valor;

            printf("%d", valor);
        }

        printf("\n");
        
    }

    free(matriz);
    return 0;
}