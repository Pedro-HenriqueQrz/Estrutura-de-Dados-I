#include<stdio.h>
#include<locale.h>

void aplicar_powerup_pontuacao_dupla(int *pi){
    *pi = *pi*2;
}

int main(){
    setlocale(LC_ALL, "portuguese");

    int pontuacao_jogador = 1500, *pi = &pontuacao_jogador;

    printf("Pontua��o antes do power-up: %i\n", pontuacao_jogador);
    aplicar_powerup_pontuacao_dupla(pi);
    printf("Pontua��o ap�s o power-up %i\n", pontuacao_jogador);    
    return 0;

}