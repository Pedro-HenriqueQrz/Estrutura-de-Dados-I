#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int posicao_x;
    int posicao_y;
    int valor;
} Moeda;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int moedas_cadastradas;
    int total_pontos = 0;

    printf("Quantas moedas serão cadastradas?\n");
    scanf("%d", &moedas_cadastradas);

    Moeda *moedas = (Moeda *)malloc(moedas_cadastradas * sizeof(Moeda));
    if (moedas == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < moedas_cadastradas; i++) {
        printf("POSIÇÃO X DA MOEDA %d:\n", i + 1);
        scanf("%d", &moedas[i].posicao_x);
        printf("POSIÇÃO Y DA MOEDA %d:\n", i + 1);
        scanf("%d", &moedas[i].posicao_y);
        printf("VALOR DA MOEDA %d:\n", i + 1);
        scanf("%d", &moedas[i].valor);
    }

    for (int i = 0; i < moedas_cadastradas; i++) {
        total_pontos += moedas[i].valor;
    }

    printf("Pontuacao maxima do nivel: %d\n", total_pontos);

    free(moedas);

    return 0;

} 