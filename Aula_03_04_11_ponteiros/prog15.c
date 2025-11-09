#include <stdio.h>

int main(){
    int array[] = {1, 2, 3, 4, 5};
    int *ptr = array;

    long unsigned valor = (ptr +5) - ptr; // Saida: 5
    printf("%ld\n", valor);
}