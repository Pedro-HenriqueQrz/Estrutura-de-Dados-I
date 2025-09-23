#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define LINHAS 5
#define COLUNAS 10

int main(){
    setlocale(LC_ALL, "Portuguese");

    int *level_map = malloc(LINHAS * COLUNAS * sizeof(int));

    if (level_map == NULL){
        printf("Falha na alocação!");
        return 1;
    }

    for (int i = 0; i < LINHAS; i++){
        for (int j = 0; j < COLUNAS; j++){
            if (i == LINHAS - 1){
                *(level_map + i * COLUNAS + j) = 1;                
            }else{
                *(level_map + i * COLUNAS + j) = 0;  
            }
            printf("%d", *(level_map + i * COLUNAS + j));
        }
        printf("\n");
    }

    free(level_map);
    
    return 0;

}