#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Monstro;

struct No {
    Monstro dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu() {
    printf("=== Bestiario de Monstros ===\n");
    printf("1 - Adicionar monstro\n");
    printf("2 - Ordenar bestiario\n");
    printf("3 - Mostrar bestiario\n");
    printf("4 - Sair\n");
    printf("==============================\n");
}

void lerMonstro(Monstro *pm) {
    scanf("%d %49s", &pm->id, pm->nome);
}

void adicionarMonstro(Lista *plista, Monstro dado) {
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

void mostrarBestiario(Lista lista) {
    struct No *pi;
    printf("\n=== Bestiario ===\n");
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        printf("ID: %d | Nome: %s\n", pi->dado.id, pi->dado.nome);
    }
    if (lista.inicio == NULL) {
        printf("(bestiario vazio)\n");
    }
    printf("=================\n\n");
}

void ordenarBestiario(Lista *plista) {
    struct No *pi;
    struct No *pj;
    struct No *pfim = NULL;
    
    if (plista->inicio == NULL) {
        printf("Lista vazia, nada para ordenar\n");
        return;
    }
    
    for (pi = plista->inicio; pi->prox != pfim; pi = plista->inicio) {
        for (pj = plista->inicio; pj->prox != pfim; pj = pj->prox) {
            if (pj->dado.id > pj->prox->dado.id) {
                // Troca os dados dos nós
                Monstro temp = pj->dado;
                pj->dado = pj->prox->dado;
                pj->prox->dado = temp;
            }
        }
        pfim = pj;
    }
    printf("Bestiario ordenado com sucesso!\n");
}

void liberarLista(Lista *plista) {
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
            Monstro m;
            printf("Informe o ID (nivel de ameaca) e nome do monstro:\n");
            lerMonstro(&m);
            adicionarMonstro(&lista, m);
            printf("Monstro adicionado ao bestiario!\n");
        }

        if (op == 2) {
            ordenarBestiario(&lista);
        }

        if (op == 3) {
            mostrarBestiario(lista);
        }
    }

    liberarLista(&lista);
    printf("Programa finalizado...\n");
    return 0;
}