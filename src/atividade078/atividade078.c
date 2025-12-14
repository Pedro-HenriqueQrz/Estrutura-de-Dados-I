#include <stdio.h>
#include "combate.h"

int main(){
    int ataque, bonus, hp_inimigo;
    printf("Digite o ataque base do Herói:\n");
    scanf("%d", &ataque);
    printf("Digite o bônus de ataque da espada:\n");
    scanf("%d", &bonus);
    printf("Digite a vida inicial do inimigo:\n");
    scanf("%d", &hp_inimigo);
    int ataque_total = calcular_ataque_total(ataque, bonus);
    hp_inimigo = aplicar_dano(hp_inimigo, ataque_total);
    printf("Status: Ataque total: %d | Vida do Inimigo: %d\n", ataque_total, hp_inimigo);
    return 0;
}