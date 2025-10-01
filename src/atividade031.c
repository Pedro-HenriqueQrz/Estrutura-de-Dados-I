#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct {

    int pontos;
    float pos_x;
    float pos_y;

} Coletavel;


int main(){
    setlocale(LC_ALL, "Portuguese");

    Coletavel gema_rara;

    printf("Digite a posição x e y e o valor da gema rara: \n");
    scanf("%f %f %d", &gema_rara.pos_x, &gema_rara.pos_y, &gema_rara.pontos);

    printf("Coletável criado! Valor: %d pontos. Posição: (X=%.2f, Y=%.2f)", gema_rara.pontos, gema_rara.pos_x, gema_rara.pos_y);

    return 0;
}