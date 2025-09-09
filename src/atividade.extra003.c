#include<stdio.h>
#include<string.h>
#include<locale.h>

int main(){
    char nomes[3][50];
    char temp[50];

    for(int i = 0; i < 3; i++){
        printf("Insira o nome %i: \n", i+1);
        scanf(" %s", nomes[i]);
    }

    for(int j = 0; j < 2; j++){
        for(int i = 0; i < 2; i++){
            if(strcmp(nomes[i], nomes[i + 1]) > 0){
                strcpy(temp, nomes[i]);
                strcpy(nomes[i], nomes[i + 1]);
                strcpy(nomes[i + 1], temp);
            }
        }
    }

    printf("Nomes em ordem alfabetica: \n");
    for(int i = 0; i < 3; i++){
        printf("%s\n", nomes[i]);
    }

    return 0;
}