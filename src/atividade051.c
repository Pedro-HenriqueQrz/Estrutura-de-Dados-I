#include<stdio.h>

typedef struct {
    char tipo[50];
    int hp;
} Inimigo;

int main(){
    int n;
    Inimigo unidade;

    printf("Digite a quantidade de unidades:\n");
    scanf("%d", &n);

    printf("Digite os dados das unidades\n");
    for (int i = 0; i < n; i++){
        scanf("%s %i", &unidade.tipo, &unidade.hp);
        printf("Inimigo: %s, HP: %i\n", unidade.tipo, unidade.hp);
    }

    return 0;
    
}