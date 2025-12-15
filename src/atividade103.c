// Verificando se a pilha esta vazia
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
    printf("2 - Lançar próximo feitiço (pop)\n");
    printf("3 - Mostrar pilha de comandos\n");
    printf("4 - Verificar status da pilha\n");
    printf("5 - Finalizar e sair\n");
    printf("===============================\n");
}

void empilhar(Pilha *ppilha, Feitico dado){
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL){
        printf("Falha de alocacao de memoria\n");
        return;
    }
    novo->dado = dado;
    novo->prox = ppilha->topo;
    ppilha->topo = novo;
}

int vazia(Pilha *p){
    return p->topo == NULL ? 1 : 0;
}

Feitico pop(Pilha *p){
    Feitico falha;
    strcpy(falha.nome, "");
    falha.custo_mana = -1;
    if (vazia(p)){
        printf("A pilha de comandos esta vazia!\n");
        return falha;
    }
    No *rem = p->topo;
    Feitico valor = rem->dado;
    p->topo = rem->prox;
    free(rem);
    return valor;
}

void mostrar_pilha(Pilha *p){
    if (vazia(p)){
        printf("A pilha de comandos esta vazia.\n");
        return;
    }
    printf("\nTopo ->\n");
    No *pi;
    for (pi = p->topo; pi != NULL; pi = pi->prox){
        printf("Feitiço: %s | Mana: %d\n", pi->dado.nome, pi->dado.custo_mana);
    }
    printf("<- Base\n\n");
}

void liberar_pilha(Pilha *p){
    while (!vazia(p)){
        (void)pop(p);
    }
}

int main(){
    Pilha pilha;
    pilha.topo = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 5){
        if (op == 1){
            Feitico f;
            printf("Informe o nome do feitiço:\n");
            scanf("%99s", f.nome);
            printf("Informe o custo de mana:\n");
            scanf("%d", &f.custo_mana);
            empilhar(&pilha, f);
        }
        else if (op == 2){
            Feitico l = pop(&pilha);
            if (l.custo_mana != -1){
                printf("Feitiço '%s' lançado com sucesso!\n", l.nome);
            }
        }
        else if (op == 3){
            mostrar_pilha(&pilha);
        }
        else if (op == 4){
            if (vazia(&pilha)){
                printf("A pilha de comandos está vazia.\n");
            } else {
                printf("A pilha de comandos possui feitiços pendentes.\n");
            }
        }
        menu();
        scanf("%d", &op);
    }
    liberar_pilha(&pilha);
    return 0;   
}