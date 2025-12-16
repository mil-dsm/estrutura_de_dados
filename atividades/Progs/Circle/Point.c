#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "Point.h"

struct Point{
    double x, y;
};

Point* create_point(double x, double y){
    Point *p = (Point *) malloc(sizeof(Point));
    if(p == NULL){
        printf("Erro. Memoria insuficiente\n");
        exit(1);
    }
    p->x = x;
    p->y = y;
    return p;
}

void free_point(Point *p){
    free(p);
}

bool get_x(Point *p, double *out_var) {
    if(p != NULL) {
        *out_var = p->x;
        return true;
    }
    return false;
}

bool get_y(Point *p, double *out_var) {
    if(p != NULL) {
        *out_var = p->y;
        return true;
    }
    return false;
}

void set_x(Point *p, double x){
    if(p != NULL)
        p->x = x;
}

void set_y(Point *p, double y){
    if(p != NULL)
        p->y = y;
}

double distance(Point *p1, Point *p2){
    if(p1 != NULL && p2 != NULL)
        return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
    printf("Erro. Ponteiro nulo.\n");
    return -1;
}