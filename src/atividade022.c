#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int n_inimigos;
    printf("Quantos inimigos terá nesta onda?\n");
    scanf("%d", &n_inimigos);

    int *ponteiro_onda = malloc(sizeof(int)*n_inimigos);

    printf("Digite o ID de cada um dos inimigos\n");
    for (int i = 0; i < n_inimigos; i++){
        scanf("%d", ponteiro_onda + i);
    }

    printf("Onda de inimigos criada com sucesso!\n");
    for (int i = 0; i < n_inimigos; i++){
        printf("IDs: %d\n", *(ponteiro_onda + i));
    }

    return 0;
    

}