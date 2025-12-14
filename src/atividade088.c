#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
}Jogador;

struct No{
    Jogador dado;
    struct No * prox;
};

typedef struct {
    struct No *inicio;
}Lista;

void menu(){
    printf("\n=== GERENCIAMENTO DE JOGADORES ===\n");
    printf("1 - Adicionar jogador no inicio\n");
    printf("2 - Adicionar jogador no fim\n");
    printf("3 - Mostrar lista de jogadores\n");
    printf("4 - Remover jogador do inicio\n");
    printf("5 - Remover jogador do fim\n");
    printf("6 - Sair\n");
    printf("===================================\n");
}

void ler(Jogador *pj){
    printf("Digite o ID do jogador: ");
    scanf(" %d", &pj->id);
    printf("Digite o nome do jogador: ");
    scanf(" %49s", pj->nome);
}

void inserir_inicio(Lista *plista, Jogador dado){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void inserir_fim(Lista *plista, Jogador dado){
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

void deletar_inicio(Lista *plista){
    if (plista->inicio == NULL){
        printf("\nNao ha jogadores na lista para remover.\n");
    }
    else{
        struct No * pi = plista->inicio;
        printf("\nJogador removido: %s (ID: %d)\n", pi->dado.nome, pi->dado.id);
        plista->inicio = pi->prox;
        free(pi);
    }
}

void deletar_fim(Lista *plista){

    if (plista->inicio == NULL){
        printf("\nNao e possivel remover jogadores. A lista esta vazia.\n");
    }

    else if (plista->inicio->prox == NULL){
        struct No * pi = plista->inicio;
        printf("\nUltimo jogador removido: %s (ID: %d)\n", pi->dado.nome, pi->dado.id);
        plista->inicio = NULL;
        free(pi);
    }

    else{
        struct No* pi;
        struct No* pa = NULL;

        for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox){
            pa = pi;
        }
        printf("\nJogador removido do final: %s (ID: %d)\n", pi->dado.nome, pi->dado.id);

        pa->prox = NULL;
      
        free(pi);
    }
}

void mostrar(Lista lista){
    struct No * pi;
    printf("\n=== LISTA DE JOGADORES ===\n");
    if (lista.inicio == NULL){
        printf("Nenhum jogador na lista.\n");
    }
    else{
        for (pi = lista.inicio; pi != NULL; pi = pi->prox){
            printf("ID: %d | Nome: %s\n", pi->dado.id, pi->dado.nome);
        }
    }
    printf("==========================\n");
}

int main(){
    Lista lista;
    lista.inicio = NULL;
    int op;
    
    do{
        menu();
        scanf("%d", &op);
        
        if (op == 1){
            Jogador j;
            printf("\n--- Adicionar jogador no inicio ---\n");
            ler(&j);
            inserir_inicio(&lista, j);
            printf("\nJogador adicionado no inicio com sucesso!\n");
        }
        else if (op == 2){
            Jogador j;
            printf("\n--- Adicionar jogador no fim ---\n");
            ler(&j);
            inserir_fim(&lista, j);
            printf("\nJogador adicionado no fim com sucesso!\n");
        }
        else if (op == 3){
            mostrar(lista);
        }
        else if (op == 4){
            printf("\n--- Remover jogador do inicio ---\n");
            deletar_inicio(&lista);
        }
        else if (op == 5){
            printf("\n--- Remover jogador do fim ---\n");
            deletar_fim(&lista);
        }
    } while (op != 6);

    printf("Programa Finalizado!");
    
    return 0;
}