#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int hp;
} Monstro;

void ler(Monstro *monstros){
    scanf("%s %d", &monstros->nome, &monstros->hp);
}

int main(){
    int n;
    printf("Digite a quantidade de monstros a serem catalogados:\n");
    scanf("%d", &n);
    Monstro *monstros = malloc(n*sizeof(Monstro));

    printf("Digite os dados dos monstros\n");
    for (int i = 0; i < n; i++){
        ler(&monstros[i]);
    }

    Monstro menor = monstros[0];
    for(int i = 1; i < n; i++){
        if (monstros[i].hp < menor.hp){
            menor = monstros[i];
        }
    }
    printf("Alvo prioritario: %s (HP: %i)\n", menor.nome, menor.hp);

    return 0;
}

