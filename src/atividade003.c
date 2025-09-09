#include<stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL,"portuguese");

    float coordenada_x, *ponteiro_x = &coordenada_x;

    printf("Olha só, um portal! Para onde você gostaria de ir?\n");
    scanf("%f", &coordenada_x);

    printf("Posição do portal no eixo X: %f\n", *ponteiro_x);
    printf("Endereço do portal para teletranporte: %p", ponteiro_x);

    return 0;

}