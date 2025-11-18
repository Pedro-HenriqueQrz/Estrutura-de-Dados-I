#include <stdio.h>
#include <locale.h>
#include <stdio.h>

typedef struct {
    int id;
    int pontos;
} Conquista;

int main(){
    FILE * file = fopen("./../arquivos/player_log.txt", "r+");

    int n;
    fscanf(file, "%i", &n);

    Conquista conquistas;
    int total_pontos = 0;

    for (int i = 0; i < n; i++){
        fscanf(file, "%i %i", &conquistas.id, &conquistas.pontos);
        total_pontos += conquistas.pontos;
    }
    
    printf("Total de pontos: %d", total_pontos);

    fseek(file, 0, SEEK_CUR);

    fprintf(file, ("\n--- SESSION CONCLUDED ---"));

    fclose(file);

    return 0;

}