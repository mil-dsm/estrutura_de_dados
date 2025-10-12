#include <stdio.h>

int fatorial(int);

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", fatorial(n));
}

int fatorial(int n){
    if(n == 1)
        return 1;
    else
        return n * fatorial(n - 1);
}