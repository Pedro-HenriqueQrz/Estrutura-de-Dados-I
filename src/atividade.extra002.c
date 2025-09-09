#include <stdio.h>

int main() {
    float * alunos[3];
    float e1[3];
    float e2[3];
    float e3[3];
    alunos[0] = e1;
    alunos[1] = e2;
    alunos[2] = e3;
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%f", *(alunos + i) + j);
        }
    }

    float maior = alunos[0][0];
    int cont = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (*(*(alunos + i) + j) >= 7) {
                cont++;
            }
            if (*(*(alunos + i) + j) > maior) {
                maior = alunos[i][j];
            }
        }
    }

    printf("Maior nota: %.2f\n", maior);
    printf("Quantidade positivos: %d\n", cont);
    return 0;
}