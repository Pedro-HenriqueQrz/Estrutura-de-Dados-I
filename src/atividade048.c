#include <stdio.h>
#include <stdlib.h> 

typedef struct {
    char nome[50];
    int vida;
    int ataque;
} Campeao;

// Por algum motivo, ele não lê o arquivo gerado no outro código...

void registrar_campeao(){
    FILE *file = fopen("./../arquivos/squad.dat", "wb");

    Campeao campeoes;

    for (int i = 0; i < 3; i++)
    {
        printf("Digite o nome do %d Campeão\n", i+1);
        scanf("%s", &campeoes.nome);
        printf("Digite a vida do %d Campeão\n", i+1);
        scanf("%i", &campeoes.vida);
        printf("Digite o ataque do %d Campeão\n", i+1);
        scanf("%i", &campeoes.ataque);
        fwrite(&campeoes, sizeof(Campeao), 1, file);
    }

    fclose(file);
    
}

int main(){

    registrar_campeao();

    FILE *file = fopen("./../arquivos/squad.dat", "rb");

    Campeao *campeoes = malloc(3*sizeof(Campeao));

    fread(campeoes, sizeof(Campeao), 3, file);

    int indice_maior = 0;
    for (int i = 1; i < 3; i++){
        if (campeoes[i].vida > campeoes[indice_maior].vida){
            indice_maior = i;
        }
    }

    printf("Campeão Tanque do Esquadrão: Nome: %s,Vida: %d, Ataque: %d", campeoes[indice_maior].nome, campeoes[indice_maior].vida, campeoes[indice_maior].ataque);

    free(campeoes);
    fclose(file);

    return 0;

}
