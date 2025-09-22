#include<stdio.h>
#include<string.h>
#include<locale.h>

int main(){
    char palavra_secreta[50] = {"LUX"}, tentativa_jogador[50];

    printf("Uma voz ancestral ecoa... 'Diga a palvra passe!\n'");
    scanf("%[^\n]s\n", &tentativa_jogador);

    strcmp(palavra_secreta, tentativa_jogador) == 0 ? printf("A porta magica se abre!") : printf("Nada acontece... Parece que a palavra esta incorreta.");

    return 0;

}