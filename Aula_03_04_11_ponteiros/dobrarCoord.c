#include <stdio.h>

typedef struct{
    float x, y;
} Ponto;

void dobraCoord(Ponto *);

int main(){
    Ponto p = {1, 2};
    dobraCoord(&p);
    printf("Ponto (%.2f, %.2f)\n", p.x, p.y);
}

void dobraCoord(Ponto *p){
    p->x *= 2;
    p->y *= 2;
}