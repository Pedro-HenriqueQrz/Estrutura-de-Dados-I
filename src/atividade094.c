#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Mercenario;

struct No {
    Mercenario dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu() {
    printf("=== Guilda de Mercenarios ===\n");
    printf("1 - Contratar mercenario\n");
    printf("2 - Mostrar todos\n");
    printf("3 - Verificar tamanho da guilda\n");
    printf("4 - Sair\n");
    printf("=============================\n");
}

void ler_mercenario(Mercenario *pm) {
    scanf("%d %49s", &pm->id, pm->nome);
}

void inserir_fim(Lista *plista, Mercenario dado) {
    struct No *novo = (struct No *) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = NULL;
    if (plista->inicio == NULL) {
        plista->inicio = novo;
    } else {
        struct No *pi;
        for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox) {
        }
        pi->prox = novo;
    }
}

int tamanho(Lista lista) {
    int contador = 0;
    struct No *pi;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        contador++;
    }
    return contador;
}

void mostrar(Lista lista) {
    struct No *pi;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        printf("%d %s\n", pi->dado.id, pi->dado.nome);
    }
    if (lista.inicio == NULL) {
        printf("(guilda vazia)\n");
    }
}

void liberar_lista(Lista *plista) {
    struct No *pi = plista->inicio;
    while (pi != NULL) {
        struct No *tmp = pi;
        pi = pi->prox;
        free(tmp);
    }
    plista->inicio = NULL;
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op = 0;

    while (op != 4) {
        menu();
        scanf("%d", &op);

        if (op == 1) {
            Mercenario m;
            printf("Informe ID e nome do mercenario:\n");
            ler_mercenario(&m);
            inserir_fim(&lista, m);
            printf("Mercenario contratado com sucesso\n");
        }

        if (op == 2) {
            mostrar(lista);
        }

        if (op == 3) {
            int tam = tamanho(lista);
            printf("Tamanho atual da guilda: %d mercenario(s)\n", tam);
        }
    }

    liberar_lista(&lista);
    printf("Programa finalizado...\n");
    return 0;
}