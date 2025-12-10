#include<stdio.h>

int soma(int n){
    if(n == 1){
        return 1;
    }

    return n + soma(n -1);
}

int main(){
    int n;
    printf("Digite o valor de n\n");
    scanf("%d", &n);
    int result = soma(n);
    printf("%d\n", result);

    return 0;
}