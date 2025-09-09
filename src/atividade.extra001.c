#include <stdio.h>

int main() {
    float estudantes[3][3];
    float *ponteiro_estudantes = estudantes;
    int i;
    for (i = 0; i < 3; i++) {
        scanf("%f %f", &estudantes[i][0], &estudantes[i][1]);
    }
    for (i = 0; i < 3; i++) {
        if (estudantes[i][0] > estudantes[i][1]) {
            printf("%.2f\n", estudantes[i][0]);
        }
        else {
            printf("%.2f\n", estudantes[i][1]);
        }
    }
}