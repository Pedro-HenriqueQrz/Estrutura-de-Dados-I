#include <stdio.h>

int pares(int i, int f, int v[]){
    if(i > f) return 0;
    if(i < f){
        int meio = (i + f)/2;
        int pro1 = pares(i, meio, v);
        int pro2 = pares(meio + 1, f, v);
        return pro1 + pro2;
    }
    if(v[i]%2 == 0) return 1;
    return 0;
}

int main(){

    int n, i, j;
    printf("Digite o valor de n\n");
    scanf("%d", &n);

    int v[n];
    for(i = 0; i < n; i ++){
        scanf("%d", &v[i]);
    }

    int result = pares(0, n - 1, v);
    printf("%d\n", result);

    return 0;
}