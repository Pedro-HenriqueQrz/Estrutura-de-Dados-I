#include<stdio.h>
#include<locale.h>
#include<string.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    char nome_jogador[150];
    char titulo_conquistado[150];

    printf("Digite o nome do herói:\n");
    scanf("%s", nome_jogador);

    printf("Digite o título conquistado:\n");
    scanf("%s", titulo_conquistado);

    strcat(nome_jogador, " Vulgo ");
    strcat(nome_jogador, titulo_conquistado);

    printf("O herói agora é conhecido como: %s", nome_jogador);

    return 0;
}
