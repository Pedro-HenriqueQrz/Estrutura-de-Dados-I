#include<stdio.h>
#include<stdlib.h>

int fibonaci(int n){
    if(n == 1)
        return 0;
    
    if (n == 2)
        return 1;
    
    return fibonaci(n -1 ) + fibonaci(n - 2);
    
}

int main(){
    int n;
    printf("Digite o valor de n\n");
    scanf("%d", &n);

    int result = fibonaci(n);
    printf("%d", result);

    return 0;
}