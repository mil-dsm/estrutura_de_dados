#include <stdio.h>

void swap(int *, int *);

int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    printf("Antes:\nx = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("Depois:\nx = %d, y = %d\n", x, y);
}

void swap(int *p1, int *p2){
    int aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}