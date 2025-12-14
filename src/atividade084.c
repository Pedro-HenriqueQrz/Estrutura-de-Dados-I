#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int id;
    char titulo[50];
    char status[30];
}Missao;

struct No{
    Missao dado;
    struct No * prox;
};

typedef struct {
    struct No *inicio;
}Lista;

void menu(){
    printf("\n=== SISTEMA DE MISSOES ===\n");
    printf("1 - Adicionar missao no inicio\n");
    printf("2 - Adicionar missao no fim\n");
    printf("3 - Mostrar todas as missoes\n");
    printf("4 - Pesquisar missao por ID\n");
    printf("5 - Sair\n");
    printf("==========================\n");
}

void ler(Missao *pm){
    printf("Digite o ID da missao: ");
    scanf(" %d", &pm->id);
    printf("Digite o titulo da missao: ");
    scanf(" %49s", pm->titulo);
    printf("Digite o status da missao: ");
    scanf(" %29s", pm->status);
}

void inserir_inicio(Lista *plista, Missao dado){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void inserir_fim(Lista *plista, Missao dado){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = NULL;
    if (plista->inicio == NULL){
        plista->inicio = novo;
    }
    else{
        struct No *pi;
        for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox);
        pi->prox = novo;
    }
}

void mostrar(Lista lista){
    struct No * pi;
    printf("\n=== LISTA DE MISSOES ===\n");
    for (pi = lista.inicio; pi != NULL; pi = pi->prox){
        printf("ID: %d | Titulo: %s | Status: %s\n", pi->dado.id, pi->dado.titulo, pi->dado.status);
    }
    printf("========================\n");
}

struct No* pesquisar_missao(Lista lista, int id){
    struct No * pi;
    for (pi = lista.inicio; pi != NULL && pi->dado.id != id; pi = pi->prox);
    return pi;
}

int main(){
    Lista lista;
    lista.inicio = NULL;
    int op;
    
    do{
        menu();
        scanf("%d", &op);
        
        if (op == 1){
            Missao m;
            printf("\n--- Adicionar missao no inicio ---\n");
            ler(&m);
            inserir_inicio(&lista, m);
            printf("\nMissao adicionada com sucesso!\n");
        }
        else if (op == 2){
            Missao m;
            printf("\n--- Adicionar missao no fim ---\n");
            ler(&m);
            inserir_fim(&lista, m);
            printf("\nMissao adicionada com sucesso!\n");
        }
        else if (op == 3){
            mostrar(lista);
        }
        else if (op == 4){
            int id;
            printf("\nInforme o ID da missao: ");
            scanf("%d", &id);
            struct No * pi = pesquisar_missao(lista, id);
            if (pi != NULL){
                printf("\n=== MISSAO ENCONTRADA ===\n");
                printf("ID: %d\n", pi->dado.id);
                printf("Titulo: %s\n", pi->dado.titulo);
                printf("Status: %s\n", pi->dado.status);
                printf("=========================\n");
            }
            else{
                printf("\nMissao nao encontrada!\n");
            }
        }
    } while (op != 5);
    
    return 0;
}