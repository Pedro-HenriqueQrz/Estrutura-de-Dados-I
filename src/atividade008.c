#include<stdio.h>
#include<locale.h>

int main(){

    int fase[10] = {0, 1, 0, 0, 1, 1, 0, 1, 0, 0};
    int moedas_coletadsas = 0, *ponteiro_jogador;
    ponteiro_jogador = fase;

    for (int i = 0; i < 10; i++){

        if (*(ponteiro_jogador + i) == 1){
            moedas_coletadsas++;
        }
        
    }
    
    printf("O jogador coletou um total de %d moedas!", moedas_coletadsas);
    
    return 0;

}