#include <stdio.h>

int main(void) {
    int n;
    printf("Digite o tamanho da energia do Golen\n");
    scanf("%d", &n);

    while (n > 1) {
        printf("%d\n", n);
        n /= 2;
    }

    return 0;
}