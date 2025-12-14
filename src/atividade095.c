#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char tipo[50];
} Inimigo;

struct No {
    Inimigo dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu() {
    printf("=== Gerenciador de Inimigos ===\n");
    printf("1 - Adicionar inimigo no inicio\n");
    printf("2 - Adicionar inimigo no fim\n");
    printf("3 - Mostrar todos os inimigos\n");
    printf("4 - Tamanho da lista\n");
    printf("5 - Criar lista de inimigos\n");
    printf("6 - Deletar toda a lista\n");
    printf("7 - Sair\n");
    printf("================================\n");
}

void ler_inimigo(Inimigo *pi) {
    scanf("%d %49s", &pi->id, pi->tipo);
}

void inserir_inicio(Lista *plista, Inimigo dado) {
    struct No *novo = (struct No *) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void inserir_fim(Lista *plista, Inimigo dado) {
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

void deletar_lista(Lista *plista) {
    struct No *pi = plista->inicio;
    while (pi != NULL) {
        struct No *tmp = pi;
        pi = pi->prox;
        free(tmp);
    }
    plista->inicio = NULL;
}

void mostrar(Lista lista) {
    struct No *pi;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        printf("%d %s\n", pi->dado.id, pi->dado.tipo);
    }
    if (lista.inicio == NULL) {
        printf("(lista vazia)\n");
    }
}

int tamanho(Lista lista) {
    struct No *pi;
    int cont = 0;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        cont++;
    }
    return cont;
}

Lista criar_lista(int n) {
    Lista nova_lista;
    nova_lista.inicio = NULL;
    int i;
    printf("Informe os %d inimigos (ID e tipo):\n", n);
    for (i = 0; i < n; i++) {
        Inimigo inimigo;
        printf("Inimigo %d: ", i + 1);
        ler_inimigo(&inimigo);
        inserir_fim(&nova_lista, inimigo);
    }
    return nova_lista;
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op = 0;

    while (op != 7) {
        menu();
        scanf("%d", &op);

        if (op == 1) {
            Inimigo inimigo;
            printf("Informe ID e tipo do inimigo:\n");
            ler_inimigo(&inimigo);
            inserir_inicio(&lista, inimigo);
        }

        if (op == 2) {
            Inimigo inimigo;
            printf("Informe ID e tipo do inimigo:\n");
            ler_inimigo(&inimigo);
            inserir_fim(&lista, inimigo);
        }

        if (op == 3) {
            mostrar(lista);
        }

        if (op == 4) {
            int tam = tamanho(lista);
            printf("Tamanho da lista: %d inimigo(s)\n", tam);
        }

        if (op == 5) {
            int n;
            printf("Informe a quantidade de inimigos:\n");
            scanf("%d", &n);
            // Libera a lista anterior antes de criar a nova
            deletar_lista(&lista);
            // Cria e atribui a nova lista, substituindo a anterior
            lista = criar_lista(n);
            printf("Lista criada com sucesso!\n");
        }

        if (op == 6) {
            deletar_lista(&lista);
            printf("Todos os inimigos foram removidos\n");
        }
    }

    deletar_lista(&lista);
    printf("Programa finalizado...\n");
    return 0;
}