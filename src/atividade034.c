#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct {
    int saude;
    int pontuacao;
    int posX;
    int posY;
} Heroi;

int main() {
    setlocale(LC_ALL, "Portuguese");

    Heroi meuHeroi;
    meuHeroi.saude = 100;
    meuHeroi.pontuacao = 0;
    meuHeroi.posX = 0;
    meuHeroi.posY = 0;

    printf("Situação inicial do Herói:\n");
    printf("Saúde: %d\n", meuHeroi.saude);
    printf("Pontuação: %d\n", meuHeroi.pontuacao);
    printf("Posição X: %d\n", meuHeroi.posX);
    printf("Posição Y: %d\n", meuHeroi.posY);

    Heroi *ptrHeroi = &meuHeroi;

    ptrHeroi->saude -= 25;

    printf("DANO! Saúde: %d\n", meuHeroi.saude);

    ptrHeroi->pontuacao +=50;

    printf("Moedas coletadas! Pontuação: %d\n", meuHeroi.pontuacao);

    ptrHeroi->posX += 10;
    ptrHeroi->posY -= 5;

    printf("Situação Final do Herói:\n");
    printf("Saúde: %d\n", meuHeroi.saude);
    printf("Pontuação: %d\n", meuHeroi.pontuacao);
    printf("Posição X: %d\n", meuHeroi.posX);
    printf("Posição Y: %d\n", meuHeroi.posY);

    return 0;
}