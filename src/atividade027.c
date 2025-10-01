#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct Inimigo{
    int vida;
    int ataque;
    float velocidade;
};

void imprime_inimigos(struct Inimigo i);

int main(){
    setlocale(LC_ALL, "Portugese");

    struct Inimigo cogumelo_zumbi = {20, 5, 0.8f};
    struct Inimigo cavaleiro_zumbi = {80, 15, 1.2f};
    
    printf("ATRIBUTOS DO INIMIGO COGUMELO ZUMBI\n");
    imprime_inimigos(cogumelo_zumbi);
    printf("ATRIBUTOS DO INIMIGO CAVALEIRO ZUMBI\n");
    imprime_inimigos(cavaleiro_zumbi);
    
    return 0;
    
};

void imprime_inimigos(struct Inimigo i){
    printf("VIDA: %d\nATAQUE: %d\nVELOCIDADE; %.2f\n", i.vida, i.ataque, i.velocidade);
};
