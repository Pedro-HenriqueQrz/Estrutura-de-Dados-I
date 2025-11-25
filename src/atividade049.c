#include <stdlib.h>
#include<stdio.h>

// Por algum motivo, não esta funcionando no meu pc, então não consegui fazer o teste

int main(){
    FILE *file = fopen("level_1_map.dat", "r");
    if(file == NULL){
        printf("Ocorreu um erro ao abrir o arquivo\n");
        system("pause");
        //perror(file);
        exit(1);
    }

    return 0;
}