#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct {
    int pos_x;
    int pos_y;
    int moedas;
} Personagem;

Personagem atualizarPersonagem(Personagem p);

int main(){
    setlocale(LC_ALL, "Portuguese");

    Personagem jogador = {0, 0, 0};

    printf("Posição Inicial: (%d %d), Moedas: %d", jogador.pos_x, jogador.pos_y, jogador.moedas);
    
    jogador = atualizarPersonagem(jogador);

    printf("Posição atualizada: (%d %d), Moedas: %d", jogador.pos_x, jogador.pos_y, jogador.moedas);

};

Personagem atualizarPersonagem(Personagem p){
    p.pos_x = 10;
    p.pos_y = 5;
    p.moedas += 1;
    return p;
};

