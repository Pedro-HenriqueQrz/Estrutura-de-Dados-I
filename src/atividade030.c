#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

struct Jogador{
    char nome[50];
    int vidas;
    int pontuacao;
};


int main(){
    setlocale(LC_ALL, "Portuguese");

    struct Jogador player1;
    player1.vidas = 3;
    player1.pontuacao = 0;

    char nome_digitado[50];

    printf("Digite o nome do seu personagem!\n");
    scanf("%s", nome_digitado);

    strcpy(player1.nome, nome_digitado);

    printf("Personagem criado! Seja bem-vindo %s! Vidas: %d, Pontua��o: %d", player1.nome, player1.vidas, player1.pontuacao);

    return 0;
}