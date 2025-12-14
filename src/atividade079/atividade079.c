#include <stdio.h>
#include "heroi/heroi.h"
#include <stdlib.h>

int main(){
    int n;
    printf("Informe o valor de n:\n");
    scanf("%d", &n);

    heroi *v = cria(n);

    if (v == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    ler(n, v);
    imprimir(n, v);

    free(v);
    return 0;
}