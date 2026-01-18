#include <stdio.h>

struct Lista{
    int valor;
    struct Lista *proximo;
};

struct Lista *procurarValor(struct Lista *, int);

int main(){
    struct Lista m1, m2, m3, *p, *result;
    p = &m1;
    m1.valor = 5;
    m2.valor = 10;
    m3.valor = 15;
    m1.proximo = &m2;
    m2.proximo = &m3;
    m3.proximo = NULL;
    int n;
    printf("Valor: ");
    scanf("%d", &n);
    result = procurarValor(p, n);
    if(result == NULL){
        printf("Valor nao encontrado.\n");
    } else{
        printf("O valor esta no endereco [%p]\n", result);
    }
    return 0;
}

struct Lista *procurarValor(struct Lista *pLista, int valor){
    while(pLista != (struct Lista*)0){
        if(pLista->valor == valor){
            return (pLista);
        } else{
            pLista = pLista->proximo;
        }
    }
    return (struct Lista*)0;
}