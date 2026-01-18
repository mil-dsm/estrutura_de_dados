#include <stdio.h>

void swap(int *, int *);

int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    printf("Antes:\nx = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("Depois:\nx = %d, y = %d\n", x, y);
}

void swap(int *p1, int *p2){
    int aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

// Resposta (professor):

typedef struct{
    float x, y;
} Ponto;

void troca(Ponto *p1, Ponto *p2){
    Ponto ponto_aux = *p1;
    *p1 = *p2;
    *p2 = ponto_aux;
}

void print(Ponto *p){
    printf("x: %.2f, y: %.2f\n", p->x, p->y);
}

void dobra(Ponto *p1){
    p1->x *= 2;
    p1->y *= 2;
}

int main(){
    Ponto a = {2, 3}, b = {5, 6};
    dobra(&a);
    print(&a);
    troca(&a, &b);
    print(&a);
    print(&b);
    return 0;
}