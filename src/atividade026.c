#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int *mochila = malloc(sizeof(int)*3);
    printf("Digite os três primeiros itens: \n");
    scanf("%d %d %d", &mochila[0], &mochila[1], &mochila[2]);
    printf("%d %d %d\n", mochila[0], mochila[1], mochila[2]);

    mochila = realloc(mochila, sizeof(int)*6);

    printf("Sua mochila aumentou de tamanho! Digite mais três itens para pôr nela:\n");
    scanf("%d %d %d", &mochila[3], &mochila[4], &mochila[5]);

    for (int i = 0; i < 6; i++){
        printf("Itens: %d\n", *mochila+i);
    }

    free(mochila);

    return 0;
}