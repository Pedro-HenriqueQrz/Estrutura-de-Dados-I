#include<stdio.h>
#include<locale.h>

int main(){

    int balas[2] = {30, 30},
        granadas[2] = {5, 5},
        foguetes[2] = {2, 2};

    int *inventario[3] = {balas, granadas, foguetes};

    printf("Inventário Inicial: \n");
    printf("Balas: %d\n", balas[0]);
    printf("Granadas: %d\n", granadas[0]);
    printf("Foguetes: %d\n", foguetes[0]);
    
    for (int i = 0; i < 3; i++){
            *(*(inventario + i ) + 0) -= 1;
    }

    printf("Inventário Final: \n");
    printf("Balas: %d de %d\n", balas[0], balas[1]);
    printf("Granadas: %d de %d\n", granadas[0], granadas[1]);
    printf("Foguetes: %d de %d\n", foguetes[0], foguetes[1]);

    return 0;
    
}