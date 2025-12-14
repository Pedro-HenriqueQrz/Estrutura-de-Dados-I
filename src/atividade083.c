// Fila de jogadores usando lista encadeada
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int mat;
    char nome[50];
}jogador;

struct No{
    jogador dado;
    struct No * prox;
};

typedef struct {
    struct No *inicio;
}Lista;

void menu(){
    printf("=== Escolha uma opcao ===\n");
    printf("1 - Adicionar jogador no inicio da fila\n");
    printf("2 - Adicionar jogador no fim da fila\n");
    printf("3 - Mostrar fila\n");
    printf("4 - Sair\n");
    printf("=========================\n");
}

void ler(jogador *pj){
    scanf(" %d %49s", &pj->mat, pj->nome);
}

void inserir_inicio(Lista *plista, jogador dado){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void inserir_fim(Lista *plista, jogador dado){
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
    printf("\n=== Fila de Jogadores ===\n");
    for (pi = lista.inicio; pi != NULL; pi = pi->prox){
        printf("Matricula: %d | Nome: %s\n", pi->dado.mat, pi->dado.nome);
    }
    printf("=========================\n\n");
}

int main(){
    Lista lista;
    lista.inicio = NULL;
    int op;
    
    do{
        menu();
        scanf("%d", &op);
        
        if (op == 1){
            jogador j;
            printf("Digite a matricula e o nome do jogador: ");
            ler(&j);
            inserir_inicio(&lista, j);
            printf("Jogador adicionado no inicio da fila!\n\n");
        }
        else if (op == 2){
            jogador j;
            printf("Digite a matricula e o nome do jogador: ");
            ler(&j);
            inserir_fim(&lista, j);
            printf("Jogador adicionado no fim da fila!\n\n");
        }
        else if (op == 3){
            mostrar(lista);
        }
    } while (op != 4);

    printf("Programa Finalizado!");
    
    return 0;
}