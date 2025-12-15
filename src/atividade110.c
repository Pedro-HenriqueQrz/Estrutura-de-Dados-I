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
    No * novo = (No*) malloc(sizeof(No));
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

void mostrar(Fila *fila){
    if (fila->inicio == NULL){
        printf("A fila de matchmaking esta vazia.\n");
        return;
    }
    No * pi;
    for (pi = fila->inicio; pi != NULL; pi = pi->prox){
        printf("ID: %d | Nick: %s\n", pi->dado.id, pi->dado.nickname);
    }
}

Jogador remover(Fila *pfila){
    Jogador falha;
    falha.id = -1;
    strcpy(falha.nickname, "");

    if (pfila->inicio == NULL){
        printf("A fila esta vazia\n");
        return falha;
    }

    No *rem = pfila->inicio;
    Jogador j = rem->dado;

    pfila->inicio = rem->prox;
    if (pfila->inicio == NULL){
        pfila->fim = NULL;
    }

    free(rem);
    return j;
}

void menu(){
    printf("=== Fila de Jogadores === \n");
    printf("1 - Adicionar Jogador na Fila\n");
    printf("2 - Mostrar Fila\n");
    printf("3 - Remover Jogador (Iniciar Partida)\n");
    printf("4 - Sair \n");
    printf("=========================\n");
}

int main(){
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 4){
        if (op == 1){
            Jogador j;
            ler_jogador(&j);
            inserir(&fila, j);
        }
        else if(op == 2){
            mostrar(&fila);
        }
        else if(op == 3){
            Jogador j = remover(&fila);
            if (j.id != -1){
                printf("O jogador %s (ID: %d) foi removido da fila e entrou em uma partida.\n", j.nickname, j.id);
            }
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}