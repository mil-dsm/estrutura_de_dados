#include <stdio.h>

int main(){
    int v[] = {1, 2, 3, 4, 5};
    int *p = v; // aponta para o primeiro elemento
    for(int i=0; i<5; i++){
        printf("v[%d] = %d\n", i, *(p + i));
    }
    printf("%p : %d\n", p, *p);
    printf("%p : %d\n", p+1, *(p+1));
    printf("%p : %d\n", p+2, *(p+2));
    printf("%p : %d\n", p+3-1, *(p+3-2));
}