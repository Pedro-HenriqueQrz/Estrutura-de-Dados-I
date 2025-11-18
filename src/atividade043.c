#include<stdio.h>
#include<locale.h>

typedef struct {
    char nome[50];
    int vida;
    int ataque;
} Inimigo;

int main(){
    
    FILE * file = fopen("./../arquivos/wave_data.txt", "r");

    if (!file){
        perror("Erro ao abrir o arquivo!\n");
        return -1;
    }
    
    Inimigo inf;
    Inimigo mais_forte;
    mais_forte.ataque = 0;

    while (fscanf(file, "%s %i %i", &inf.nome, &inf.vida, &inf.ataque) != EOF) {

        if (mais_forte.ataque < inf.ataque){
            mais_forte = inf;
        }
        
    }

    printf("Maior Ameaça: %s, Vida: %i, Ataque: %i", mais_forte.nome, mais_forte.vida, mais_forte.ataque);

    fclose(file);

    return 0;
    
}