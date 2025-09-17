#include<stdio.h>
#include<locale.h>

int main(){

    int sala_01[3] = {10, 20, 5}, 
        sala_02[2] = {50, 100},
        sala_03[4] = {5, 5, 5, 10};

    int *ponteiro_salas[3] = {sala_01, sala_02, sala_03};
    int tamanhos[3] = {sizeof(sala_01)/sizeof(sala_01[0]), sizeof(sala_02)/sizeof(sala_02[0]), sizeof(sala_03)/sizeof(sala_03[0])};

    for (int i = 0; i < 3; i++){
        printf("Moedas da sala %d:", i+1);
        for (int j = 0; j < tamanhos[i]; j++){
            printf(" %d", *(*(ponteiro_salas + i) + j ));
        }
        
        printf("\n");
        
    }
    
    return 0;

}