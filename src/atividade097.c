#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Membro;

struct No {
    Membro dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu() {
    printf("=== Roster da Guilda ===\n");
    printf("1 - Adicionar membro\n");
    printf("2 - Mostrar todos os membros\n");
    printf("3 - Salvar roster em arquivo\n");
    printf("4 - Sair\n");
    printf("========================\n");
}

void ler_membro(Membro *pm) {
    scanf("%d %49s", &pm->id, pm->nome);
}

void inserir_fim(Lista *plista, Membro dado) {
    struct No *novo = (struct No *) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = NULL;
    if (plista->inicio == NULL) {
        plista->inicio = novo;
    } else {
        struct No *pi;
        for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox) {
        }
        pi->prox = novo;
    }
}

void mostrar(Lista lista) {
    struct No *pi;
    printf("\n=== Membros da Guilda ===\n");
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        printf("ID: %d | Nome: %s\n", pi->dado.id, pi->dado.nome);
    }
    if (lista.inicio == NULL) {
        printf("(roster vazio)\n");
    }
    printf("=========================\n\n");
}

void salvar_guild_arquivo(Lista lista) {
    FILE *file = fopen("./../arquivos/guild_roster.bin", "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita\n");
        return;
    }
    
    struct No *pi;
    int contador = 0;
    
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        
        fwrite(&pi->dado, sizeof(Membro), 1, file);
        contador++;
    }
    
    fclose(file);
    printf("Roster salvo com sucesso! %d membro(s) gravado(s) em guild_roster.bin\n", contador);
}

void liberar_lista(Lista *plista) {
    struct No *pi = plista->inicio;
    while (pi != NULL) {
        struct No *tmp = pi;
        pi = pi->prox;
        free(tmp);
    }
    plista->inicio = NULL;
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op = 0;

    while (op != 4) {
        menu();
        scanf("%d", &op);

        if (op == 1) {
            Membro m;
            printf("Informe o ID e nome do membro:\n");
            ler_membro(&m);
            inserir_fim(&lista, m);
            printf("Membro adicionado ao roster!\n");
        }

        if (op == 2) {
            mostrar(lista);
        }

        if (op == 3) {
            salvar_guild_arquivo(lista);
        }
    }

    liberar_lista(&lista);
    printf("Programa finalizado...\n");
    return 0;
}