#include<stdio.h>
#include<locale.h>

int main(){
    int plataformas[5] = {10, 20, 5, 15, 30};
    int *ponteiro_plataforma = plataformas;
    int altura_total = 0;

    for(int i = 0; i < 5; i++){
        altura_total += *(ponteiro_plataforma + i);
    }
    printf("Altura total do salto: %d metros!", altura_total);
}