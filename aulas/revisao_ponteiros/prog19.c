#include <stdio.h>

typedef struct{
    double x, y;
} Ponto;

int main(){
    Ponto p1, *p2;
    p2 = &p1;
    p1.x = 1;
    p1.y = 2;
    p2->x = 4.5;
    p2->y = 6.5;
    printf("p1 = (%.2lf, %.2lf)\n", p1.x, p1.y);
}