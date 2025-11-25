#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y;
} Unidade;

int main(void) {
    int n;
    printf("Digite a quantidade de unidades que você deseja\n");
    scanf("%d", &n);

    Unidade *inimigos = malloc(n * sizeof *inimigos);
   

    for (int i = 0; i < n; ++i) {
        printf("Digite as coordenadas x y da unidade %d\n", i + 1);
        scanf("%d %d", &inimigos[i].x, &inimigos[i].y);
    }

    double raio;

    printf("Digite o raio\n");
    scanf("%lf", &raio);

    int contador = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double dx = (double)inimigos[j].x - inimigos[i].x;
            double dy = (double)inimigos[j].y - inimigos[i].y;
            double distancia = sqrt(dx * dx + dy * dy);
            if (distancia <= raio) contador++;
        }
    }

    printf("Total de duplas próximas: %d\n", contador);

    free(inimigos);
    return 0;
}