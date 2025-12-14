#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} Movimento;

struct No {
    Movimento dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void ler(Movimento *pm) {
    scanf("%d %s", &pm->id, pm->nome);
}

void menu() {
    printf("========== Escolha uma opção ==========\n");
    printf("1 - Inserir novo movimento no início do combo\n");
    printf("2 - Sair\n");
    printf("=======================================\n");
}

void inserir_inicio(Lista *lista, Movimento dado) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op;
    
    menu();
    scanf("%d", &op);
    
    while (op != 2) {
        if (op == 1) {
            Movimento m;
            ler(&m);
            inserir_inicio(&lista, m);
        }
        menu();
        scanf("%d", &op);
    }

    printf("Operação Finalizada!\n");
    
    return 0;
}