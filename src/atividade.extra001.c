#include <stdio.h>

int main() {
    float estudantes[3][3];
    float *ponteiro_estudantes = (float *)estudantes;
    int i;
    for (i = 0; i < 3; i++) {
        scanf("%f %f", &estudantes[i][0], &estudantes[i][1]);
    }
    for (i = 0; i < 3; i++) {

        estudantes[i][0] > estudantes[i][1] ? printf("%.2f\n", estudantes[i][0]) : printf("%.2f\n", estudantes[i][1]);

       /* if (estudantes[i][0] > estudantes[i][1]) {
            printf("%.2f\n", estudantes[i][0]);
        }
        else {
            printf("%.2f\n", estudantes[i][1]);
        }*/
       
    }
}