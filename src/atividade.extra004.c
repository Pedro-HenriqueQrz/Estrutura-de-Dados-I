#include<stdio.h>
#include<locale.h>
#include<string.h>

int main(){
    char texto[200];
    char chave[50];
    int contador = 0;
    char *ponteiro;
    

    printf("Escreva o texto: \n");
    fgets(texto, sizeof(texto), stdin);

    printf("\nEscreva a palavra chave: \n");
    fgets(chave, 50, stdin);

    texto[strcspn(texto, "\n")] = '\0';
    chave[strcspn(chave, "\n")] = '\0';

    ponteiro = texto;

    while ((ponteiro = strstr(ponteiro, chave)) != NULL){
        contador++;
        ponteiro += strlen(chave);
    }

    strstr(texto, chave) != NULL ? printf("Palavra encontrada! Ela aparece %i", contador) : printf("Palavra não encontrada!");
    
  

    return 0;

}