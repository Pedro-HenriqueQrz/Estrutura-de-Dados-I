#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct{
    int x;
    int y;
} Posicao;

void mover_personagem(Posicao *pos, int movimento_x, int movimento_y) {
    pos->x += movimento_x;
    pos->y += movimento_y;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    Posicao posicao_jogador = {0, 0};
    Posicao *ponteiro_posicao = &posicao_jogador;
    printf("Posição do Jogador: [%d,%d]\n", posicao_jogador.x, posicao_jogador.y);
    mover_personagem(ponteiro_posicao, 10, 5);
    printf("Posição do Jogador: [%d,%d]\n", posicao_jogador.x, posicao_jogador.y);

    return 0;

}