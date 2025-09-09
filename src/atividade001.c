#include<stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
    int vida_jogador = 100;
    int *ponteiro_vida;

    vida_jogador = 50;

    printf("Ah não! O jogador sofreu dano! \n Vida atual: %i\n", vida_jogador);

    ponteiro_vida = &vida_jogador;

    *ponteiro_vida = 100;

    printf("O jogador teve um power-up! Vida Restaurada!! \n Vida atual: %i", *ponteiro_vida);
    
    return 0;
}
