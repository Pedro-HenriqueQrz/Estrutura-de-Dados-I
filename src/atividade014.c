#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");
    char fase_inicio_luta[150] = {"Voc� nunca sair� daqui com vida!"};
    char caixa_dialogo[150] = {"Sil�ncio"};

    printf("Chefe antes da luta: %s\n", caixa_dialogo);

    strcpy(caixa_dialogo, fase_inicio_luta);

    printf("Chefe diz: %s\n", caixa_dialogo);

    return 0;

}