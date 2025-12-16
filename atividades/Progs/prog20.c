#include <stdio.h>

void extremos(int *, int *, int *, int);

int main(){
    int valor = 10, menor, maior, vet[] = {50, 10, 250, 500, 25};
    int *p;
    extremos(vet, &menor, &maior, 5);
}

void extremos(int *v, int *me, int *ma, int tam){
    *me = v[0];
    *ma = v[0];
    for(int i=0; i<tam; i++){
        if(*(v + i) < *me){
            me = &v[i];
        }
        if(*(v+i) > *ma){
            ma = &i[v];
        }
    }
    printf("Maior elemento: %d, em [%p]\n", *ma, ma);
    printf("Menor elemento: %d, em [%p]\n", *me, me);
}