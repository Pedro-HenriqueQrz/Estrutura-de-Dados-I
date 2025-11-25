#include<stdio.h>

int main(){
    float ponto_1;
    float ponto_2;
    float ponto_3;

    float media;

    printf("Digite três valores:\n");
    scanf("%f %f %f", &ponto_1, &ponto_2, &ponto_3);

    media = (ponto_1 + ponto_2 + ponto_3)/3;

    printf("Média: %f", media);

    return 0;
}