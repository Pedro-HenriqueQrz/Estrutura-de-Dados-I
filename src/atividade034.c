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

    printf("Situa��o inicial do Her�i:\n");
    printf("Sa�de: %d\n", meuHeroi.saude);
    printf("Pontua��o: %d\n", meuHeroi.pontuacao);
    printf("Posi��o X: %d\n", meuHeroi.posX);
    printf("Posi��o Y: %d\n", meuHeroi.posY);

    Heroi *ptrHeroi = &meuHeroi;

    ptrHeroi->saude -= 25;

    printf("DANO! Sa�de: %d\n", meuHeroi.saude);

    ptrHeroi->pontuacao +=50;

    printf("Moedas coletadas! Pontua��o: %d\n", meuHeroi.pontuacao);

    ptrHeroi->posX += 10;
    ptrHeroi->posY -= 5;

    printf("Situa��o Final do Her�i:\n");
    printf("Sa�de: %d\n", meuHeroi.saude);
    printf("Pontua��o: %d\n", meuHeroi.pontuacao);
    printf("Posi��o X: %d\n", meuHeroi.posX);
    printf("Posi��o Y: %d\n", meuHeroi.posY);

    return 0;
}