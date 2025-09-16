#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){

    int n;

    printf("Digite o tamanho da matriz\n");
    scanf("%d", &n);

    int *matriz = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i + j == n -1){
                *(matriz + (i * n) + j) = 2;
            } else if (i == j){
                *(matriz + (i * n) + j) = 1;
            } else{
                *(matriz + (i * n) + j) = 3;
            }

            printf("%d", *(matriz + (i * n) + j));
        }
        printf("\n");
    }

    return 0;
}