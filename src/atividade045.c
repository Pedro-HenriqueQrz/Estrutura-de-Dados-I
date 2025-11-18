#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char nome[50];
    int nivel;
    float vida;
    float mana;
} Personagem;

void menu () {
    printf("=================== ESCOLHA UMA OPÇÃO ===================\n");
    printf("1 - Criar novo personagem.\n");
    printf("2 - Finalizar\n");
    printf("=========================================================\n");
}

int main(){

    FILE *file = fopen("./../arquivos/savegame.sav", "wb");

    int opcao = 1;
    menu();
    scanf("%d", &opcao);

    while (opcao != 2){

        Personagem personagem;
        printf("Informe os dados do personagem:\n");
        scanf("%s", &personagem.nome);
        scanf("%i", &personagem.nivel);
        scanf("%f", &personagem.vida);
        scanf("%f", &personagem.mana);
        fwrite(&personagem, sizeof(Personagem), 1, file);
        
        menu();
        scanf("%d", &opcao);
    }

    printf("Programa Finalizado!");

    fclose(file);
    
    return 0;

}