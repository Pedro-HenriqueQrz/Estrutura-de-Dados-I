#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    float *ponteiro_altura_salto_duplo = NULL;

    printf("Jogador não possui o Salto Duplo\n");

    ponteiro_altura_salto_duplo = malloc(sizeof(float));

    if(ponteiro_altura_salto_duplo == NULL){

        printf("A alocação falhou!\n");
        return 1;

    }else{

        *ponteiro_altura_salto_duplo = 15.50;
        printf("Pena dourada coletada! Altura do Salto Duplo: %.2f", *ponteiro_altura_salto_duplo);
        free(ponteiro_altura_salto_duplo);

    }
    
    return 0;

}