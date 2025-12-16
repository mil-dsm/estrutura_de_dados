#include <stdio.h>

void troca(int *i, int *j){
    int *temp;
    *temp = *i;
    *i = *j;
    *j = *temp;
}

int main(){
    int x = 1, y = 2;
    printf("Atm...\nx = %d, y = %d\n", x, y);
    troca(x, y);
    printf("Trocando...\nx = %d, y = %d\n", x, y);
}