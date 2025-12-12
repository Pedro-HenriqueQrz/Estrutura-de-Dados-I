#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, j;
    printf("Digite o valor de N\n");
    scanf("%d", &n);

    int *fragmentos = malloc(n*sizeof(int));

    for(i = 0; i < n; i++){
        scanf("%i", &fragmentos[i]);
    }

    for(i = 1; i < n; i++){
        int x = fragmentos[i];
        for(j = i - 1; j >= 0 && x < fragmentos[j]; j--){
            fragmentos[j + 1] = fragmentos[j];
        }
        fragmentos[j + 1] = x;
    }

    for ( i = 0; i < n; i++){
        printf("%i ", fragmentos[i]);
    }

    free(fragmentos);
    
    return 0;
    
}