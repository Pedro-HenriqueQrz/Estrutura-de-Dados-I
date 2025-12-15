#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nickname[100];
} Jogador;

struct no{
    Jogador dado;
    struct no * prox;
};

typedef struct no No;

typedef struct {
    No * inicio;
    No * fim;
} Fila;

void ler_jogador(Jogador *j){
    printf("Informe o ID e o nickname:\n");
    scanf("%d %99s", &j->id, j->nickname);
}

void inserir(Fila *pfila, Jogador dado){
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL){
        printf("Falha de alocacao de memoria\n");
        return;
    }
    novo->dado = dado;
    novo->prox = NULL;
    if (pfila->inicio == NULL){
        pfila->inicio = novo;
        pfila->fim = novo;
    }
    else{
        pfila->fim->prox = novo;
        pfila->fim = novo;
    }
}

void mostrar(Fila *f){
    if (f->inicio == NULL){
        printf("A fila de matchmaking esta vazia.\n");
        return;
    }
    No *aux;
    for (aux = f->inicio; aux != NULL; aux = aux->prox){
        printf("ID: %d | Nick: %s\n", aux->dado.id, aux->dado.nickname);
    }
}

void menu(){
    printf("=== Fila de Jogadores ===\n");
    printf("1 - Adicionar Jogador na Fila\n");
    printf("2 - Mostrar Fila\n");
    printf("3 - Sair\n");
    printf("========================\n");
}

int main(){
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;

    int op;
    menu();
    scanf("%d", &op);
    while (op != 3){
        if (op == 1){
            Jogador j;
            ler_jogador(&j);
            inserir(&fila, j);
        }
        else if(op == 2){
            mostrar(&fila);
        }
        menu();
        scanf("%d", &op);
    }

    return 0;
}