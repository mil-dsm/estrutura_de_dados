#include <stdio.h>

int main(){
    int x = 10;
    double y = 20.5;
    char z = 'a';

    int *px;
    px = &x; // Quer acessar o endereco desse ponteiro, o qual aponta para o endereco de x
    // int *px = &x; // O valor de px eh igual ao endereco de memoria de x
    double *py;
    py = &y;
    char *pz;
    pz = &z;

    // Quando coloca (*) se refere ao valor do ponteiro, quando eh sem (*), se refere ao endereco de memoria
    printf("Endereco x = %p, valor de x = %d\n", px, *px);
    printf("Endereco y = %p, valor de y = %2.lf\n", py, *py);
    printf("Endereco z = %p, valor de z = %c\n", pz, *pz);

    // Aritmetica com ponteiros
    double soma = (double) *px + *py;
    printf("Soma de x e y: %2.lf\n", soma);

    int *resultado;
    // resultado = &x;
    // printf("Valor de x = %p\n", resultado);
    resultado = 0x0061FF00; // Erro
    printf("Valor de x = %d\n", *resultado);
}