#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct{
    int vida;
    int pontuacao;
} Atributos;

typedef struct {
    char nome[50];
    Atributos stats;
} Personagem;
    

int main(){
    setlocale(LC_ALL, "Portuguese");

    Personagem Jogador;
    printf("Digite o nome do personagem\n");
    scanf("%s", &Jogador.nome);

    Jogador.stats.vida = 100;
    Jogador.stats.pontuacao = 0;

    printf("Status inicial -> Nome: %s | Vida: %d | Pontuação: %d\n", Jogador.nome, Jogador.stats.vida, Jogador.stats.pontuacao);

    Jogador.stats.pontuacao += 10;
    Jogador.stats.vida -= 25;

    printf("Status Final -> Nome: %s | Vida: %d | Pontuação: %d\n", Jogador.nome, Jogador.stats.vida, Jogador.stats.pontuacao);

    return 0;
    
}