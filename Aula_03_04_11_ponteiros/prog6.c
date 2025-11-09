#include <stdio.h>

void dobra(int x){
    x *= 2;
}

void dobre_ptr(int *p){
    *p *= 2;
}

int main(){
    int a =3;
    dobra(a);
    printf("Funcao (dobra) = %d\n", a);
    dobra_ptr(&a);
    printf("Funcao (dobre_ptr) = %d\n", a);
}