 #include <stdio.h>
 #include <stdlib.h>

 int carga_positiva(int i, int n, int *v){
    if(i == n){
        return 0;
    }

    if(v[i] > 0){
        return 1 + carga_positiva(i + 1, n, v);
    }

    return carga_positiva(i + 1, n, v);
}

int main(){
    int n;
    printf("Digite a quantidade de cristais que você possui\n");
    scanf("%d", &n);

    int *v = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    int positivas = carga_positiva(0, n, v);
    printf("Quantidade de cargas positivas: %d\n", positivas);

    free(v);
    return 0;
}