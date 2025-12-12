#include <stdio.h>

typedef struct{
    int posicao;
    char nome[50];
} Piloto;

void intercalacao(int e, int m, int d, Piloto v[]){
    int n1 = (m - e) + 1;
    int n2 = d - m;
    int k = e;
    Piloto E[n1];
    Piloto D[n2];
    int i, j;
    for(i = 0; i < n1; i++){
        E[i] = v[e + i];
    }
    for(j = 0; j < n2; j++){
        D[j] = v[m + 1 + j];
    }
    i = 0;
    j = 0;
    while (i < n1 && j < n2){
        if(E[i].posicao < D[j].posicao){
            v[k] = E[i];
            i++;
        }else{
            v[k] = D[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        v[k] = E[i];
        i++;
        k++;
    }
    while (j < n2){
        v[k] = D[j];
        j++;
        k++;
    }
}

void mergeSort(int i, int f, Piloto v[]){
    if(i < f){
        int meio = (i + f)/2;
        mergeSort(i, meio, v);
        mergeSort(meio + 1, f, v);
        intercalacao(i, meio, f, v);
    }
}

void ler(Piloto *pilotos){
    scanf("%s %d", &pilotos->nome, &pilotos->posicao);
}

int main(){
    int n, i;
    printf("Informe o valor de n\n");
    scanf("%d", &n);

    Piloto pilotos[n];

    for(i = 0; i < n; i++){
        ler(&pilotos[i]);
    }

    mergeSort(0, n - 1, pilotos);

    printf("Imprimindo os Pilotos\n");

    for(i = 0; i < n; i++){
        printf("%s %d\n", pilotos[i].nome, pilotos[i].posicao);
    }

    return 0;

}
