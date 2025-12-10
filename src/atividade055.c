#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int id;
    char nickname[50];
    int pontuacao;
} Jogador;

void ler(Jogador *jogadores){
    scanf("%d %49s %d", &jogadores->id, jogadores->nickname, &jogadores->pontuacao);
}

void menu(){
    printf("======================= Escolha uma opção =======================\n");
    printf("1 - Pesquisar\n");
    printf("2 - Finalizar\n");
    printf("================================================================\n");
}

int buscabinario(int id, int n, Jogador jogadores[]){
    int i = 0;
    int f = n - 1;
    while(i <= f){

        int meio = (i + f)/2;

        if(jogadores[meio].id == id){
            return meio;
        }else if (jogadores[meio].id < id){
            i = meio + 1;
        }else{
            f = meio - 1;
        }
        
    }
    
    return -1;

}

int main(){
    int n;
    printf("Digite o valor de N\n");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Entrada inválida para N\n");
        return 1;
    }

    Jogador *jogadores = malloc(n * sizeof(Jogador));

    printf("Digite os dados dos jogadores\n");
    for(int i = 0; i < n; i++){
        ler(jogadores + i);
    }

    int operacao;
    menu();
    if (scanf("%d", &operacao) != 1) operacao = 2;

    while (operacao != 2){

        if(operacao == 1){
            int id;
            printf("Digite o id do personagem que você deseja pesquisar\n");
            scanf("%d", &id);
            int idx = buscabinario(id, n, jogadores);

            if (idx != -1){
                jogadores[idx].pontuacao = jogadores[idx].pontuacao + 100;
                printf("Nickname: %s, Nova Reputação: %d\n", jogadores[idx].nickname, jogadores[idx].pontuacao);
            }else{
                printf("Jogador com ID %d não encontrado.\n", id);
            }
        }

        menu();
        scanf("%d", &operacao);

    }

    printf("Programa Finalizado!\n");
    free(jogadores);
    
    return 0;
    
}