#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, j;
    printf("Digite o valor de n\n");
    scanf("%d", &n);
    int *v = malloc(n*sizeof(int));

    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    for(i = 0; i < n; i++){
        int menor = i;
        for(j = i + 1; j < n; j++){
            if (v[j] < v[menor]){
                menor = j;
            }
        }
        int temp = v[i];
        v[i] = v[menor];
        v[menor] = temp;
    }

    printf("Lista Ordenada\n");
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
}