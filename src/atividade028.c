#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct Jogador{
    float pos_x;
    int pontuacao;
    int tem_pulo_duplo;
};

int main(){
    setlocale(LC_ALL, "Portuguese");

    struct Jogador heroi = {50, 0, 0};

    printf("Inicio de Fase! Posi��o X: %.2f, Pontos: %d, Pulo Duplo: %s\n", heroi.pos_x, heroi.pontuacao, heroi.tem_pulo_duplo == 0 ? "N�o" : "Sim");

    heroi.pontuacao += 10;
    heroi.tem_pulo_duplo = 1;

    printf("Itens coletados!! Posi��o X: %.2f, Pontos: %d, Pulo Duplo: %s\n", heroi.pos_x, heroi.pontuacao, heroi.tem_pulo_duplo == 0 ? "N�o" : "Sim");
    

    return 0;


}