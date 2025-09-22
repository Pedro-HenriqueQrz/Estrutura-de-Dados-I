#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    char inventario[5][20];
    char palavra_chave[20];
    int encontrado = 0;

    printf("Digite 5 itens necess�rios para abrir a porta:\n");
    for (int i = 0; i < 5; i++) {
        printf("Item %d: ", i + 1);
        scanf("%19s", inventario[i]);
    }

    printf("Digite o item necess�rio para abrir a porta:\n");
    scanf("%19s", palavra_chave);

    for (int i = 0; i < 5; i++) {
        if (strcmp(inventario[i], palavra_chave) == 0) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        printf("Porta aberta!\n");
    } else {
        printf("Voc� n�o tem o item necess�rio.\n");
    }

    return 0;
}