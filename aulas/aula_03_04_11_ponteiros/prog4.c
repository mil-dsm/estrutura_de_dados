#include <stdio.h>

int main(){
    float f = 47.78;
    int *ptr = &f; // Erro de compilacao
    int i = 54;
    float *f2 = &i; // Erro de compilacao
}