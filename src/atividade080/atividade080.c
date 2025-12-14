#include <stdio.h>
#include "personagem/personagem.h"

int main(){
    int n;
    printf("Informe quantos membros a equipe tera:\n");
    scanf("%d", &n);

    Personagem *party = cria_party(n);

    if (party == NULL) {
        printf("Falha ao alocar memoria.\n");
        return 1;
    }

    registra_membros(party, n);
    exibe_relatorio(party, n);
    libera_party(party);
    return 0;
}