#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

int main(){
    int estado;
    char situacao[255];

    FILE *file = fopen("./../arquivos/game_log.txt", "a");

    printf("====================================================================\n");
    printf("                      Você tem duas opções                          \n");
    printf("               Digite 1 - Cadastrar um novo evento                  \n");
    printf("            Digite 2 - Encerramento de um novo evento               \n");
    printf("====================================================================\n");

    scanf("%d", &estado);

    while (estado == 1){

        printf("Digite a situação atual do jogo (SEM ESPAÇOS):\n");
        scanf("%s", &situacao);
        printf("Deseja adicionar um novo evento? (digite 1 para sim ou 2 para não)\n");
        scanf("%d", &estado);
        fprintf(file, "%s\n", situacao);
        
    }

    fclose(file);

    return 1;
    
}