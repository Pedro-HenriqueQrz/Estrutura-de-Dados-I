#include<stdio.h>
#include<string.h>
#include<locale.h>

int main(){
    char nome_jogador[50], comprimento;

    printf("Digite seu nome: \n");
    scanf("%[^\n]s", &nome_jogador);

    comprimento = strlen(nome_jogador);

    comprimento <= 15 ? printf(" Bem-vindo ao jogo, %s", nome_jogador) : printf("Nome muito longo! Por favor, escolha um nome com ate 15 caracteres");

   return 0;
    

}