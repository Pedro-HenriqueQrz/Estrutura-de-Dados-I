#include <stdio.h>
#include <locale.h>

typedef struct
{
    char nome[50];
    float HP;
    float ATK;
} Inimigo;

int main()
{
    Inimigo monstro01;
    Inimigo monstro02;
    Inimigo monstro03;
    Inimigo v[3] = {monstro01, monstro02, monstro03};

    FILE *file = fopen("./../arquivos/inimigos.txt", "r");
    
    
    if (!file){
        perror("Erro ao abrir arquivo");
        return 1;
    }

    for (int i = 0; i < 3; i++){
        fscanf(file, "%49s %f %f", v[i].nome, &v[i].HP, &v[i].ATK);
    }

    for (int i = 0; i < 3; i++){
        float nivel_ameaca = v[i].ATK + v[i].HP;
        if (nivel_ameaca > 200){
            printf("Nome: %s | Nível de Ameaça: %.1f\n", v[i].nome, nivel_ameaca);
        }
    }

    fclose(file);

    return 0;
}