#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} aventureiro;

struct No{
    aventureiro dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu(){
    printf("=== Escolha uma opcao ===\n");
    printf("1 - Adicionar aventureiro\n");
    printf("2 - Mostrar grupo\n");
    printf("3 - Sair\n");
    printf("=========================\n");
}

void ler(aventureiro *pa){
    scanf("%d %49s", &pa->id, pa->nome);  // lê id e depois nome, limitando 49 chars
}

void inserir_inicio(Lista *plista, aventureiro dado){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void mostrar(Lista lista){
    struct No *pi = lista.inicio;
    while (pi != NULL){
        printf("ID: %d | Nome: %s\n", pi->dado.id, pi->dado.nome);
        pi = pi->prox;
    }
}

int main(){
    Lista lista;
    lista.inicio = NULL;
    int op;
    
    menu();
    scanf("%d", &op);
    
    while (op != 3){
        if (op == 1){
            aventureiro a;
            ler(&a);
            inserir_inicio(&lista, a);
        }
        else if (op == 2){
            mostrar(lista);
        }
        menu();
        scanf("%d", &op);
    }

    printf("Operação Finalizada!");
    
    return 0;
}