#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "Point.h"

struct Circle{
    Point *center;
    double radius;
};

Circle* create_circle(double radius, const Point *center){
    Circle *c = (Circle *) malloc(sizeof(Circle));
    if(c == NULL){
        printf("Erro. Memória insuficiente.\n");
        exit(1);
    }
    double x, y;
    get_x((Point*) center, &x);
    get_y((Point*) center, &y);
    c->center = create_point(x, y);
    c->radius = radius;
    return c;  
}

void setRadius(Circle *c, double r){
    if(c == NULL){
        printf("Erro. Ponteiro nulo.\n");
        return;
    }
    c->radius = r;
}

void setCenterByCoords(Circle *c, double x, double y){
    if(c == NULL){
        printf("Erro. Ponteiro nulo.\n");
        return;
    }
    set_x(c->center, x);
    set_y(c->center, y);
}

void setCenterByPoint(Circle *c, const Point *p){
    if (c == NULL || p == NULL){
        printf("Erro. Ponteiro nulo.\n");
        return;
    }
    double x, y;
    get_x(p, &x);
    get_y(p, &y);
    set_x(c->center, x);
    set_y(c->center, y);
}


double getRadius(const Circle *c){
    if(c == NULL){
        printf("Erro. Ponteiro nulo.\n");
        return -1;
    }
    return c->radius;
}

Point* getCenter(const Circle *c){
    if(c == NULL){
        printf("Erro. Ponteiro nulo.\n");
        return NULL;
    }
    return c->center;
}

double area(const Circle *c){
    if(c == NULL){
        printf("Erro. Ponteiro nulo.\n");
        return -1;
    }
    return M_PI * c->radius * c->radius;
}

bool contains(const Circle *c, const Point *p){
    if(c == NULL || p == NULL){
        printf("Erro. Ponteiro nulo.\n");
        return false;
    }
    double xc, yc, xp, yp;
    get_x(c->center, &xc);
    get_y(c->center, &yc);
    get_x(p, &xp);
    get_y(p, &yp);
    double dx = xp - xc; 
    double dy = yp - yc;
    double d = sqrt(dx * dx + dy * dy);
    if(d <= c->radius)
        return true;
    else
        return false;
}