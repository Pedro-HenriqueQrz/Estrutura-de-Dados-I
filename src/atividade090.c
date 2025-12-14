#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[100];
} Ward;

struct No {
    Ward dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu() {
    printf("=== Controle de Wards ===\n");
    printf("1 - Inserir ward no fim\n");
    printf("2 - Mostrar wards\n");
    printf("3 - Ward Shatter (deletar apos ID)\n");
    printf("4 - Deletar ward por ID\n");
    printf("5 - Sair\n");
    printf("========================\n");
}

void ler_ward(Ward *pw) {
    scanf("%d %99s", &pw->id, pw->nome);
}

void inserir_fim(Lista *plista, Ward dado) {
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

void mostrar(Lista lista) {
    struct No *pi;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        printf("%d %s\n", pi->dado.id, pi->dado.nome);
    }
    if (lista.inicio == NULL) {
        printf("(lista vazia)\n");
    }
}

void deletar_apos(Lista *plista, int id_ref) {
    if (plista->inicio == NULL) {
        printf("A lista esta vazia\n");
        return;
    }

    struct No *pa;
    for (pa = plista->inicio; pa != NULL && pa->dado.id != id_ref; pa = pa->prox) {
    }

    if (pa == NULL) {
        printf("Ward de referencia %d nao encontrado\n", id_ref);
        return;
    }

    if (pa->prox == NULL) {
        printf("Ward %d eh o ultimo; nenhum ward para remover apos ele\n", id_ref);
        return;
    }

    struct No *remover = pa->prox;
    pa->prox = remover->prox;
    free(remover);
    printf("Ward apos %d removido\n", id_ref);
}

void deletar_por_id(Lista *plista, int id) {
    if (plista->inicio == NULL) {
        printf("A lista esta vazia\n");
        return;
    }

    if (plista->inicio->dado.id == id) {
        struct No *remover = plista->inicio;
        plista->inicio = remover->prox;
        free(remover);
        printf("Ward %d removido (inicio)\n", id);
        return;
    }

    struct No *anterior = plista->inicio;
    struct No *pi = plista->inicio->prox;
    while (pi != NULL && pi->dado.id != id) {
        anterior = pi;
        pi = pi->prox;
    }

    if (pi == NULL) {
        printf("Ward %d nao encontrado\n", id);
        return;
    }

    anterior->prox = pi->prox;
    free(pi);
    printf("Ward %d removido\n", id);
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

int main(){
    Lista lista;
    lista.inicio = NULL;
    int op = 0;

    while (op != 5) {
        menu();
        scanf("%d", &op);

        if (op == 1) {
            Ward w;
            printf("Informe ID e nome do ward:\n");
            ler_ward(&w);
            inserir_fim(&lista, w);
        }

        if (op == 2) {
            mostrar(lista);
        }

        if (op == 3) {
            int id_ref;
            printf("Informe o ID do ward de referencia:\n");
            scanf("%d", &id_ref);
            deletar_apos(&lista, id_ref);
            mostrar(lista);
        }

        if (op == 4) {
            int id;
            printf("Informe o ID do ward a remover:\n");
            scanf("%d", &id);
            deletar_por_id(&lista, id);
            mostrar(lista);
        }
    }

    liberar_lista(&lista);
    return 0;
}