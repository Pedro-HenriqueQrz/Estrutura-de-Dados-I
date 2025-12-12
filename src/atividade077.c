#include <stdio.h>

typedef struct {
    int pontuacao;
    char nome[50];
} Jogadores;

int particiona(int e, int d, Jogadores v[]){
    Jogadores pivo = v[d];
    int j = e - 1;
    int i;

    for (i = e; i < d; i++){
        if (v[i].pontuacao <= pivo.pontuacao){
            j++;
            Jogadores temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        }

    }

    Jogadores temp = v[j + 1];
    v[j + 1] = v[d];
    v[d] = temp;
    return j + 1;
}

void quicksort(int i, int f, Jogadores v[]){
    if (i < f){
        int p = particiona(i, f, v);
        quicksort(i, p - 1, v);
        quicksort(p + 1, f, v);
    }
    
}

void ler(Jogadores *pe){
    scanf("%d %s", &pe->pontuacao, pe->nome);
}

int main(){
    int n, i;
    printf("Informe o valor de n:\n");
    scanf("%d", &n);
    Jogadores v[n];

    for (i = 0; i < n; i++){
        ler(&v[i]);
    }

    quicksort(0, n-1, v);

    for (i = 0; i < n; i++){
        printf("%s: %d\n", v[i].nome, v[i].pontuacao);
    }

    return 0;
}