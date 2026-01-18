#include <stdio.h>
#include "Point.h"

void print_point(Point *p){
    double x, y;
    get_coods(p, &x, &y);
    printf("%.2lf, %.2lf\n", x, y);
}

int main() {
    int n;
    printf("Quantos pontos voce quer criar?: ");
    scanf("%d", &n);
    double x, y;
    Point *vec_pontos[n];
    for(int i = 0; i < n; i++){
        scanf("%lf", &d, &y);
        vec_points[i] = create_point(x, y);
    }
    for(int i = 0; i < n; i++){
        print_point(vec_pontos[i]);
    }
    for(int i = 0; i < n; i++){
        free_points(vec_pontos[i]);
    }
    Point *p;
    p = create_point(3.4, 8.9);
    double x;
    ErrorType err = get_x(p, &x);

    if(get_x(p, &x) == ERROR_OK)
        printf("valor de x = %.2f\n", x);
    else if(err == ERROR_NULL_POINTER)
        printf("Erro. Ponteiro nulo.\n");
    else
        printf("Erro. Memoria insuficiente.\n");
    free_point(p);
    return 0;
}