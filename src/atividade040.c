#include <stdio.h>
#include <locale.h>
#include <string.h>
#include<stdlib.h>

typedef struct {
    char nome[50];
    int pontuacao;
} Jogador;

int main() {
    int quantidade, indice_maior;

    FILE *file = fopen("./../arquivos/jogador_pontuacao.txt", "w");

    printf("Digite a quantidade de Jogadores com dados\n");
    scanf("%d", &quantidade);

    Jogador *jogadres = malloc(quantidade * sizeof(Jogador));

    printf("Digite os dados do Jogadores!\n");
    for (int i = 0; i < quantidade; i++){
        printf("Nome do %i Jogador: ", i + 1);
        scanf("%49s", jogadres[i].nome);
        printf("Pontuacao do %i Jogador: ", i + 1);
        scanf("%d", &jogadres[i].pontuacao);
    }

    indice_maior = 0;
    for (int i = 1; i < quantidade; i++){
        if (jogadres[i].pontuacao > jogadres[indice_maior].pontuacao){
            indice_maior = i;
        }
    }

    fprintf(file, "Nome: %s | Pontuação: %d", jogadres[indice_maior].nome, jogadres[indice_maior].pontuacao);


    fclose(file);


    free(jogadres);
    


    return 0;
}
