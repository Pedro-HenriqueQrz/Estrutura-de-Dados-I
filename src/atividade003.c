#include<stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL,"portuguese");

    float coordenada_x, *ponteiro_x = &coordenada_x;

    printf("Olha s�, um portal! Para onde voc� gostaria de ir?\n");
    scanf("%f", &coordenada_x);

    printf("Posi��o do portal no eixo X: %f\n", *ponteiro_x);
    printf("Endere�o do portal para teletranporte: %p", ponteiro_x);

    return 0;

}