#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char nome[50];
    int vida;
    int ataque;
} Unidade;

int main(){
    FILE *file = fopen("./../arquivos/squad.dat", "wb");

    int n, indice_maior;

    printf("Digite quantos campeões você deseja armazenar\n");
    scanf("%d", &n);

    Unidade *campeoes = malloc(n*sizeof(Unidade));

    for (int i = 0; i < n; i++)
    {
        printf("Digite o nome do %d Campeão\n", i+1);
        scanf("%s", &campeoes[i].nome);
        printf("Digite a vida do %d Campeão\n", i+1);
        scanf("%i", &campeoes[i].vida);
        printf("Digite o ataque do %d Campeão\n", i+1);
        scanf("%i", &campeoes[i].ataque);
        fwrite(&campeoes, sizeof(Unidade), 1, file);
    }

    indice_maior = 0;
    for (int i = 0; i < n; i++){
        if (campeoes[i].ataque > campeoes[indice_maior].ataque){
            indice_maior = i;
        }
    }

    printf("Campeão com maior força de ataque: Nome: %s, Vida: %d, Ataque: %d", campeoes[indice_maior].nome, campeoes[indice_maior].vida, campeoes[indice_maior].ataque);
    

    free(campeoes);
    fclose(file);

    return 0;
    
}
