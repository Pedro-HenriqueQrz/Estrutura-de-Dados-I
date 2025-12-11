#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome [50];
    int eliminacoes;
} Jogador;

void ler(Jogador *jogador){
    scanf("%s %d", &jogador->nome, &jogador->eliminacoes);
}

int main(){
    int n, i, j;
    printf("Digite a quantidade de jogadores\n");
    scanf("%d", &n);

    Jogador *jogador = malloc(n*sizeof(Jogador));

    for (i = 0; i < n; i++){
        ler(&jogador[i]);
    }
    
    for(i = 0; i < n; i++){
        int imenor = i;
        for(j = i + 1; j < n; j++){
            if(jogador[j].eliminacoes < jogador[imenor].eliminacoes){
                imenor = j;
            }
        }
        Jogador temp = jogador[i];
        jogador[i] = jogador[imenor];
        jogador[imenor] = temp;
    }

    for ( i = 0; i < n; i++){
        printf("%s %d\n", jogador[i].nome, jogador[i].eliminacoes);
    }
    

    return 0;
}