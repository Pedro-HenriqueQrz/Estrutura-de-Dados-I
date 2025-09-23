#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int l, c;
    int **mapa;
    int contador = 0;

    printf("Digite o número de linhas e colunas:\n");
    scanf("%d %d", &l, &c);

    mapa = (int **)malloc(l * sizeof(int *));
    if (mapa == NULL) {
        printf("Erro ao alocar memória para linhas.\n");
        return 1;
    }

    for (int i = 0; i < l; i++) {
        mapa[i] = (int *)malloc(c * sizeof(int));
        if (mapa[i] == NULL) {
            printf("Erro ao alocar memória para coluna %d.\n", i);
            for (int k = 0; k < i; k++) free(mapa[k]);
            free(mapa);
            return 1;
        }
    }

    printf("Digite os valores do mapa (0, 1 ou 2):\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &mapa[i][j]);
            if (mapa[i][j] == 1) contador++;
        }
    }

    printf("O mapa possui %d blocos de tijolo.\n", contador);
    
    for (int i = 0; i < l; i++) {
        free(mapa[i]);
    }
    free(mapa);

    return 0;
}

