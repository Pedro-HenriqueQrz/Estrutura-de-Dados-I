#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, novo_tempo;
    printf("Digite o valor de N\n");
    scanf("%d", &n);

    int *tempo = malloc(n*sizeof(int)+1);

    for(i = 0; i < n; i++){
        scanf("%i", &tempo[i]);
    }

    scanf("%d", &novo_tempo);

    for(i = n - 1; i >= 0 && novo_tempo < tempo[i]; i--){
        tempo[i + 1] = tempo[i];
    }
    tempo[i+1] = novo_tempo;

    for ( i = 0; i < n+1; i++){
        printf("%i ", tempo[i]);
    }

    free(tempo);

    return 0;
    
}