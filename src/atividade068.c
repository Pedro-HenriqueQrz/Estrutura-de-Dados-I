#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int pontuacao;
} Jogadores;

void ler(Jogadores *jogador){
    scanf("%d %d", &jogador->id, &jogador->pontuacao);
}

void bolha(int n, Jogadores v[]){
    int i, j;

    for(i = 0; i < n; i++){
        int trocou = 0;
        for(j = 0; j < n - 1; j++){
            if(v[j].id < v[i + 1].id){
                Jogadores temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocou = 1;
            }
        }
        if(trocou == 0){
            return;
        }
    }
}

int main(){
    int n, i;
    printf("Digite o valor de n\n");
    scanf("%d", &n);

    Jogadores *jogador = malloc(n*sizeof(Jogadores));

    for(i = 0; i < n; i++){
        ler(&jogador[i]);
    }

    bolha(n, jogador);

    for(i = 0; i < n; i++){
        printf("%d %d\n", jogador[i].id, jogador[i].pontuacao);
    }

    free(jogador);

    return 0;

}