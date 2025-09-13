#include<stdio.h>
#include<locale.h>

int main(){

    int tesouro_local = 0;
    int *plataforma_secreta = &tesouro_local;

    printf("Ol�, o tesouro inicialainda n�o apareceu!\nValor inicial: %i\n", tesouro_local);
    

    *plataforma_secreta = 1;

    printf("Olha s�! O personagem pisou na plataforma secreta! O tesouro apareceu!\nValor: 1", *plataforma_secreta);

    return 0;
}