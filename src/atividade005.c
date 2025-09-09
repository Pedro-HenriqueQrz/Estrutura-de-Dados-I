#include<stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");

    int pontuacao = 0, *ponteiro_pontuacao = &pontuacao;

    printf("seja bem-vindo! Pontua��o inicial: %d\n", pontuacao);

    for(int moedas = 0; moedas < 3; moedas++){
        
        *ponteiro_pontuacao += 10;

        printf("Olha s�! Voc� encontrou 10 moedas!\n", *ponteiro_pontuacao);

    };

    printf("Ap�s coletar as moedas, sua pontua��o final �: %d", *ponteiro_pontuacao);
}