#include <stdio.h>
#include <stdlib.h>

int main(){
    char *cPtr;
    // Aloca espaco de 1000 caracteres
    cPtr = (char *) malloc(1000); // char tem 1 byte
    int *iPtr;
    // Aloca espaco para 250 inteiros
    iPtr = (int *) malloc(1000 * sizeof(int));
}