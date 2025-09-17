#include<stdio.h>
#include<locale.h>

int main(){

    int moedas_coletadas[5] = {10, 50, 20, 5, 100};
    int pontuacao_total = 0;
    int *ponteiro_moeda;
    ponteiro_moeda = moedas_coletadas;

    for (int i = 0; i < 5; i++){
        pontuacao_total += *(ponteiro_moeda + i);
    }

    printf("Pontuação total do nível %d", pontuacao_total);

    return 0;

}