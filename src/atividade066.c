#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, j;
    printf("Digite o valor de N\n");
    scanf("%d", &n);

    int *vetooor = malloc(n*sizeof(int)); // AAAÉÉÉÉÉÉÉ

    for(i = 0; i < n; i++){
        scanf("%d", &vetooor[i]);
    }

    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(vetooor[j] > vetooor[j + 1]){
                int temp = vetooor[j];
                vetooor[j] = vetooor[j + 1];
                vetooor[j + 1] = temp;
            }
        }
    }

    printf("Vetor Ordenado\n");
    for ( i = 0; i < n; i++){
        printf("%d ", vetooor[i]);
    }

    free(vetooor);

    return 0;
    
}