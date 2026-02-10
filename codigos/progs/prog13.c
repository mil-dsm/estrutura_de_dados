#include <stdio.h>

struct Lista{
    int valor;
    struct Lista *proximo;
};

int main(){
    struct Lista m1, m2, m3, *p;
    p = &m1;
    m1.valor = 10;
    m2.valor = 20;
    m3.valor = 30;
    
    m1.proximo = &m2;
    m2.proximo = &m3;
    m3.proximo = (struct Lista *) 0;

    while(p != m3.proximo){
        printf("%d\n", p->valor);
        p = p->proximo;
    }
}