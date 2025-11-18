#include<stdio.h>
#include<locale.h>

typedef struct {
    int resolucao_x, resolucao_y;
    float volume;
} Configuracao;

int main(){

    Configuracao config;

    FILE * file = fopen("./../arquivos/config.txt", "r");

    if(!file){
    perror("Erro: Arquivo config.txt nao encontrado!\n");
    return -1;
    }

    fscanf(file, "%i %i %f", &config.resolucao_x, &config.resolucao_y, &config.volume );

    printf("Configurações carregadas: Resolução [x]x[Y] = [%d]x[%d] | Volume = %.1f", config.resolucao_x, config.resolucao_y, config.volume);

    fclose(file);

    return 0;

}