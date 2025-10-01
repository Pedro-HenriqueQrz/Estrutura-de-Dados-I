#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    int inimigos_fase;

    printf("Digite a quantidade de inimigos da fase:\n");
    scanf("%d", &inimigos_fase);

    int *status_inimigos;
    status_inimigos = (int*) calloc(inimigos_fase, sizeof(int));

    if (status_inimigos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < inimigos_fase; i++){
       printf("Inimigo %i: %s\n", i+1, status_inimigos[i] == 0 ? "Inativo" : "Ativo"); 
    }

    for (int i = 0; i < inimigos_fase; i++){
        status_inimigos[i] = 1;
        printf("Inimigo %i: %s\n", i+1, status_inimigos[i] == 0 ? "Inativo" : "Ativo"); 
    }
    
    free(status_inimigos);
    
    return 0;

     
}