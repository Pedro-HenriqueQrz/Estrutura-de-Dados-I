#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

enum EstadoPersonagem{
    PARADO,
    CORRENDO,
    PULANDO
};

int main(){
    setlocale(LC_ALL, "Portuguese");

    enum EstadoPersonagem estado_atual;

    printf("Digite o estado do Personagem (0 para PARADO, 1 para CORRENDO, ou 2 para PULANDO).\n");
    scanf("%d", &estado_atual);

    if (estado_atual == 0){
        printf("O Personagem esta parado\n");
    }else if(estado_atual == 1){
        printf("O Personagem esta correndo\n");
    }else if(estado_atual == 2){
        printf("O Personagem esta pulando\n");
    }else{
        printf("Valor Inválido!\n");
    }

    return 0;
    
}