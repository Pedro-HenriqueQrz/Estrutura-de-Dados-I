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

void mostrar(Fila fila){
    if (fila.inicio == NULL){
        printf("A fila de matchmaking esta vazia.\n");
        return;
    }
    No * pi;
    for (pi = fila.inicio; pi != NULL; pi = pi->prox){
        printf("ID: %d | Nick: %s\n", pi->dado.id, pi->dado.nickname);
    }
}

void menu(){
    printf("=== Fila de Jogadores === \n");
    printf("1 - Inserir\n");
    printf("2 - Mostrar\n");
    printf("3 - Remover\n");
    printf("4 - Verificar se a Fila esta Vazia\n");
    printf("5 - Ver quem e o proximo da Fila\n");
    printf("6 - Sair \n");
    printf("=========================\n");
}

void remover(Fila *pfila){
    if (pfila->inicio == NULL){
        printf("A fila esta vazia\n");
    }
    else if (pfila->inicio->prox == NULL){
        pfila->inicio = NULL;
        pfila->fim = NULL;
    }
    else{
        No * pi = pfila->inicio;
        pfila->inicio = pi->prox;
        free(pi);
    }
}

int vazia(Fila fila){
    if (fila.inicio == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

Jogador verInicio(Fila *f){
    Jogador falha;
    falha.id = -1;
    strcpy(falha.nickname, "");
    if (f->inicio == NULL){
        return falha;
    }
    return f->inicio->dado;
}

int main(){
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 6){
        if (op == 1){
            Jogador j;
            ler_jogador(&j);
            inserir(&fila, j);
        }
        else if(op == 2){
            mostrar(fila);
        }
        else if(op == 3){
            remover(&fila);
        }
        else if (op == 4){
            int r;
            r = vazia(fila);
            if (r == 1){
                printf("A fila esta vazia\n");
            }
            else{
                printf("A fila nao esta vazia\n");
            }
        }
        else if (op == 5){
            Jogador j = verInicio(&fila);
            if (j.id == -1){
                printf("A fila esta vazia, nenhum jogador na frente.\n");
            } else {
                printf("O proximo jogador a entrar na partida e: %s (ID: %d)\n", j.nickname, j.id);
            }
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}