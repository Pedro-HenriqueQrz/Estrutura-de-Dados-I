#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char nome[50];
    int valor_pontos;
} ItemColetavel;

int main() {
    setlocale(LC_ALL, "Portuguese");

    ItemColetavel inventario[3];

    for (int i = 0; i < 3; i++) {
        printf("DIGITE O NOME DO %iº ITEM: ", i + 1);
        scanf("%s", inventario[i].nome);

        printf("DIGITE O VALOR EM PONTOS DO %iº ITEM: ", i + 1);
        scanf("%d", &inventario[i].valor_pontos);
    }

    ItemColetavel valioso;

    valioso = inventario[0];
    
    for (int i = 1; i < 3; i++) {
        if (inventario[i].valor_pontos > valioso.valor_pontos) {
            valioso = inventario[i];
        }
    }

    printf("O item mais valioso coletado foi: %s", valioso.nome);
    
    return 0;
}