#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int *duracao_fumaca = malloc(sizeof(int));

    if (duracao_fumaca == NULL){
        printf("A alocação falhou!\n");
        return 1;
    }

    *duracao_fumaca = 5;

    printf("Bomba de fumaça ativada! Duração: %d\n", *duracao_fumaca);
    free(duracao_fumaca);
    duracao_fumaca = NULL;

    printf("A fumaça se dissipou...");

    return 0;
    

}