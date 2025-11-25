#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char nome[50];
    int nivel;
    int highScore;
} PlayerProfile;

int main(){
    FILE *file = fopen("./../arquivos/profiles.dat", "rb");
    PlayerProfile player;
    
    while (fread(&player, sizeof(PlayerProfile), 1, file)){
        printf("Nome: %s\n", player.nome);
        printf("Nível: %i\n", player.nivel);
        if (player.highScore > 10000){
            printf("High Score: Mestre do Jogo\n");
        }else if(player.highScore > 5000){
            printf("High Score: Veterano\n");
        }else if(player.highScore <= 5000){
            printf("High Score: Aspirante\n");
        }
    }

    fclose(file);

    return 0;
    
}