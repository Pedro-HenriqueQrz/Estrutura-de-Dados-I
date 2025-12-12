#include <stdio.h>
#include <stdlib.h>

void bolha(int n, int v[]){
    int i, j;
    for(i = 0; i < n; i++){
        int trocou = 0;
        for(j = 0; j < n - 1; j++){
            if(v[j] > v[j + 1]){
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocou = 1;
            }
        }
        if(trocou == 0){
            return;
        }
    }
}

int main(){
    int n, i;
    printf("Digite o valor de N\n");
    scanf("%d", &n);

    int *vetooor = malloc(n*sizeof(int)); // AAAÉÉÉÉÉÉÉ

    for(i = 0; i < n; i++){
        scanf("%d", &vetooor[i]);
    }

    bolha(n, vetooor);

    for ( i = 0; i < n; i++){
        printf("%d ", vetooor[i]);
    }

    free(vetooor);
    
    return 0;
    
}