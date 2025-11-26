#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nome[50];
    int forca, agilidade, inteligencia;
} Personagem;

void ler_dados(Personagem *per){
    scanf("%d %s %d %d %d", &per->id, &per->nome, &per->forca, &per->agilidade, &per->inteligencia);
}

void menu(){
    printf("======================= Escolha uma opção =======================\n");
    printf("1 - Pesquisar\n");
    printf("2 - Finalizar\n");
    printf("================================================================\n");
}

int pesquisar(int id, int n, Personagem per[]){
    for (int i = 0; i < n; i++){
        if(per[i].id == id){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    printf("Informe o valor de n\n");
    scanf("%d", &n);

    Personagem *personagens = malloc(n * sizeof(Personagem));

    for (int i = 0; i < n; i++){
        ler_dados(personagens + i);
    }
    
    int operacao;
    menu();
    scanf("%d", &operacao);
    while (operacao != 2){
        if (operacao == 1)
        {
            int id;
            printf("Digite o ID do personagem\n");
            scanf("%d", &id);
            int idx = pesquisar(id, n, personagens);
            if (idx != -1){
                int media = ((personagens + idx)->forca + (personagens + idx)->agilidade + (personagens + idx)->inteligencia)/3;

                printf("%d %s %i\n", (personagens + idx)->id, (personagens + idx)->nome, media );
            }
            
        }
        
        menu();
        scanf("%d", &operacao);
    }

    printf("Programa Finalizado!");
    
    return 0;
}