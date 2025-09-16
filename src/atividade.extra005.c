#include<stdio.h>
#include<locale.h>

int main(){

    int A, N;

    printf("Digite a quantidade de alunos: \n");
    scanf("%d", &A);
    printf("Digite a quantidade de notas: ");
    scanf("%d", &N);

    int alunos[A][N];

    for(int i = 0; i < A; i++){
        printf("Digite as notas do %dº alun@\n", i+1);
        for(int j = 0; j < N; j++){
            scanf("%d", &alunos[i][j]);
        }
    }

    for(int i = 0; i < A; i++){
        int evoluindo = 1;
        for(int j = 0; j < N - 1; j++){
            if (alunos[i][j] > alunos[i][j + 1]){
                evoluindo = 0;
            }
        }
        printf("Aluno %i: %sesta evoluindo. \n", i + 1, evoluindo ? "" : "não");
    }

    return 0;

}