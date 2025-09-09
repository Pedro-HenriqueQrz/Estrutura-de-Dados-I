#include<stdio.h>
#include<locale.h>

void aplicar_powerup_pontuacao_dupla(int *pi){
    *pi = *pi*2;
}

int main(){
    setlocale(LC_ALL, "portuguese");

    int pontuacao_jogador = 1500, *pi = &pontuacao_jogador;

    printf("Pontuação antes do power-up: %i\n", pontuacao_jogador);
    aplicar_powerup_pontuacao_dupla(pi);
    printf("Pontuação após o power-up %i\n", pontuacao_jogador);    
    return 0;

}