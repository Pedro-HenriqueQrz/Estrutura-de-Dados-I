#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int pontuacao;
} Jogadores;

void ler(Jogadores *jogador){
    scanf("%s %d", &jogador->nome, &jogador->pontuacao);
}

int main(){
    int n, i, j;
    printf("Digite a quantidade de jogadores que deseja cadastrar\n");
    scanf("%d", &n);
    Jogadores *jogador = malloc(n*sizeof(Jogadores));

    for ( i = 0; i < n; i++){
        ler(&jogador[i]);
    }

    for(i = 1; i < n; i++){
        Jogadores x = jogador[i];
        for (j = i - 1; j >= 0 && x.pontuacao < jogador[j].pontuacao; j--){
            jogador[j + 1] = jogador[j];
        }
        jogador[j + 1] = x;
    }

    printf("Imprimindo Jogadores\n");

    for ( i = 0; i < n; i++){
        printf("%s %d\n", jogador[i].nome, jogador[i].pontuacao);
    }

    return 0;
    
}