#include <stdio.h>

// array[n] = *(array+n)

int main(){
    int array[5] = {9, 7, 5, 3, 1};

    // Imprime o endereco de array[1]
    printf("%p\n", &array[1]);
    printf("%p\n", array[1]); // Valor errado, precisa do op (&)
    // Imprime o endereco do ponteiro
    printf("%p\n", array+1);
    
    printf("%d\n", array[1]);
    printf("%d\n", *(array+1));
}