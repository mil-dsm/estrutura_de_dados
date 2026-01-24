#include "Point.h"
#include <stdlib.h>
#include <math.h>

struct point {
    double x;
    double y;
};

Point* create_point(double x, double y) {
    Point* ptr = malloc(sizeof(Point));
    if(ptr) {
        ptr->x = x;
        ptr->y = y;
    }
    return ptr;
}

void free_point(Point *p) {
    free(p);
}

// Obtém a coordenada x de um ponto.
// Retorna ERROR_OK se bem-sucedido,
// ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType get_x(const Point *p, double *x) {
    if(!p || !x) { // if(p == NULL || x == NULL)
        return ERROR_NULL_POINTER;
    }
    *x = p->x;
    return ERROR_OK;
}

// Obtém a coordenada y de um ponto.
// Retorna ERROR_OK se bem-sucedido,
// ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType get_y(const Point *p, double *y) {
    if(p == NULL || y == NULL) { // if(p == NULL || y == NULL)
        return ERROR_NULL_POINTER;
    }
    *y = p->y;
    return ERROR_OK;
}

// Obtém ambas as coordenadas (x, y) de um ponto.
// Retorna ERROR_OK se bem-sucedido, 
// ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType get_coords(const Point *p, double *x, double *y){
    if(p == NULL || x == NULL || y == NULL){
        return ERROR_NULL_POINTER;
    }
    *x = p->x;
    *y = p->y;
    return ERROR_OK;
}

// Define a coordenada x de um ponto.
// Retorna ERROR_OK se bem-sucedido, 
// ERROR_NULL_POINTER caso p seja nulo.
ErrorType set_x(Point *p, double x){
    if(p == NULL || x == NULL){
        return ERROR_NULL_POINTER;
    }
    p->x = x;
    return ERROR_OK;
}

// Define a coordenada y de um ponto.
// Retorna ERROR_OK se bem-sucedido, 
// ERROR_NULL_POINTER caso p seja nulo.
ErrorType set_y(Point *p, double y){
    if(p == NULL || y == NULL){
        return ERROR_NULL_POINTER;
    }
    p->y = y;
    return ERROR_OK;
}

// Define as coordenadas (x, y) de um ponto.
// Retorna ERROR_OK se bem-sucedido, 
// ERROR_NULL_POINTER caso p seja nulo.
ErrorType set_coords(Point *p, double x, double y){
    if(p == NULL || x == NULL || y == NULL){
        return ERROR_NULL_POINTER;
    }
    p->x = x;
    p->y = y;
    return ERROR_OK;
}

// Calcula a distância euclidiana entre dois pontos.
// retorna ERROR_OK se bem-sucedido, 
// ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType distance_between_points(const Point *p, const Point *q, double *dist){
    if(p == NULL || q == NULL || dist == NULL){
        return ERROR_NULL_POINTER;
    }
    double dx = q->x - p->x;
    double dy = q->y - p->y
    double *dist = sqrt(dx * dx + dy * dy);
    return ERROR_OK;
}

// Copia o conteúdo de um ponto para outro.
// Retorna ERROR_OK se bem-sucedido, 
// ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType point_copy(const Point *src, Point *dest){
    if(src == NULL || dest == NULL){
        return ERROR_NULL_POINTER;
    }
    // *dest = *src; // Como os dois sao uma struct do mesmo tipo, isso eh possivel
    dest->x = src->x;
    dest->y = src->y;
    return ERROR_OK;
}

// Troca os valores de dois pontos.
// retorna ERROR_OK se bem-sucedido, 
// ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType point_swap(Point *p, Point *q){
    if(p == NULL || q == NULL){
        return ERROR_NULL_POINTER;
    }
    Point *aux = *p;
    *p = *q;
    *q = *aux;
    return ERROR_OK;
}