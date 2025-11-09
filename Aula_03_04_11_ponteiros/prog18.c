#include <stdio.h>

typedef struct{
    float x, y;
} Ponto;

int main(){
    Ponto p1, *p3;
    p3 = &p1;
    (*p3).x = 1.5;
    (*p3).y = 1.5;
    printf("Ponto (%.2f, %.2f)\n", p1.x, p1.y);
    p3->x = 1.6;
    p3->y = 1.6;
    printf("Ponto (%.2f, %.2f)\n", p1.x, p1.y);
}