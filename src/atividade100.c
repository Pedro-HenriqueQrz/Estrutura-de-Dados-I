#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int custo_mana;
} Feitico;

struct no{
    Feitico dado;
    struct no * prox;
};

typedef struct no No;

typedef struct {
    No * topo;
} Pilha;

void menu(){
    printf("==== Comandos de Feiticos ====\n");
    printf("1 - Adicionar feitiço\n");
    printf("2 - Finalizar e sair\n");
    printf("===============================\n");
}

void empilhar(Pilha *ppilha, Feitico dado){
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Falha de alocacao de memoria\n");
        return;
    }
    novo->dado = dado;
    novo->prox = ppilha->topo;
    ppilha->topo = novo;
}

int main(){
    Pilha pilha;
    pilha.topo = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 2){
        if (op == 1){
            Feitico f;
            printf("Informe o nome do feitiço:\n");
            scanf("%99s", f.nome);
            printf("Informe o custo de mana:\n");
            scanf("%d", &f.custo_mana);
            empilhar(&pilha, f);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;   
}