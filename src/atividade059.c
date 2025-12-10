#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int id;
    char nome[50];
    int hp;
    int ataque;
} Monstro;

void ler(Monstro *monstro){
    scanf("%d %49s %d %d", &monstro->id, monstro->nome, &monstro->hp, &monstro->ataque);
}

void menu(){
    printf("======================= Escolha uma opção =======================\n");
    printf("1 - Pesquisar\n");
    printf("2 - Finalizar\n");
    printf("================================================================\n");
}

int BuscaBinaria(int id, Monstro *monstros, int i, int f){
    if(i > f) return -1;

    int meio = (i + f)/2;
    if(monstros[meio].id == id){
        return meio;
    }

    if(monstros[meio].id < id){
        return BuscaBinaria(id, monstros, meio + 1, f);
    }

    return BuscaBinaria(id, monstros, i, meio - 1);
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

    int opcao;
    menu();
    scanf("%d", &opcao);

    while (opcao != 2){

        if(opcao == 1){
            int id;
            printf("Digite o id do monstro que você deseja encontrar\n");
            scanf("%d", &id);
            int idx = BuscaBinaria(id, monstros, 0, n-1);
            if(idx != -1){
                printf("Monstro encontrado: %s (ID: %i) - HP: %i, Ataque: %i\n", monstros[idx].nome, monstros[idx].id, monstros[idx].hp, monstros[idx].ataque);
            } else {
                printf("Monstro não encontrado!\n");
            }
        }

    menu();
    scanf("%d", &opcao);
    }

    printf("Operação Finalizada!\n");
    free(monstros);
    return 0;
    
}