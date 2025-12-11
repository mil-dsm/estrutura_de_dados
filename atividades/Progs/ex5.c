#include <stdio.h>

int main(){
    // Estrutura basica: (tipo do ponteiro) *(nome do ponteiro);
    int x = 10;
    printf("Valor de x (antes): %d\n", x);
    printf("Endereço de x (antes): %p\n", x);
    int *p;
    p = &x;
    printf("Valor de x (depois): %d\n", x);
    printf("Endereço de x (depois): %p\n", x);
    printf("Valor de p: %d\n", *p);
    printf("Endereço de p: %p\n", p);

    // Mudanca de valores indiretamente
    int x = 10, y = 20;
    printf("x = %d, y = %d\n", x, y);
    int *p;
    p = &x;
    *p = y;
    printf("x = %d, y = %d\n", x, y);
}