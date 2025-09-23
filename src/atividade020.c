#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    void *ponteiro_duracao = malloc(sizeof(int));

    *((int *)ponteiro_duracao) = 10;

    printf("Power-up 'Super Salto' ativido! Duração %d segundos\n", *((int*)ponteiro_duracao));

    *((int *)ponteiro_duracao) -= 3;

    printf("3 Segundo se passaram... restam %d", *((int *)ponteiro_duracao));

    free(ponteiro_duracao);

    return 0;
}