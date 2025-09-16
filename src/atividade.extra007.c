#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){

    int n, cont = 0;
    float soma = 0;

    printf("Digite o tamanho de sua matriz\n");
    scanf("%d", &n);

    int *matriz = (int *) malloc(n * n * (sizeof(int)));

    printf("Digite os valores da matriz: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j ++){
            scanf("%d", &matriz[i * n + j]);

            if (i > (n - j - 1)){
                soma += *(&matriz[i] + j);
                cont++;
            }

        }
    }

    printf("A média dos valores da matriz é: %.2f", (soma/cont) );

    return 0;

}