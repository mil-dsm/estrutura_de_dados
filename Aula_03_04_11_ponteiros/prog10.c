#include <stdio.h>

int main(){
    int array[5] = {9, 7, 5, 3, 1};

    // Desreferenciar um array retorna o primeiro elemento
    printf("%d\n", *array);

    // Dada essa propriedade, podemos declarar
    // um ponteiro (int) e apontalo para array
    int *ptr = array;
    printf("%d\n", *ptr);
}