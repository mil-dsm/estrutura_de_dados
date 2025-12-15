#include <stdlib.h> // malloc, free, exit;
#include <math.h> // sqrt
#include "Point.h"

struct point{
    double x;
    double y;
};

// Função de criação de um ponto.
// Aloca e retorna um ponto com as coordenadas (x, y).
Point* create_point(double x, double y) {
    Point *p = (Point*) malloc(sizeof(Point));
    if(p == NULL) {
        return NULL;
    }
    p->x = x;
    p->y = y;
    return p;
}

// Função para liberar um ponto.
// Libera a memória de um ponto previamente criado.
void free_point(Point *p) {
    if(p != NULL)
        free(p);
}

// Função que acessa o valor do ponto x de uma coordenada.
ErrorType get_x(Point *p, double *out_var) {
    if(p == NULL || out_var == NULL) {
        return ERROR_NULL_POINTER;
    }
    *out_var = p->x;
    return ERROR_OK;
}

// Função que acessa o valor do ponto y de uma coordenada.
ErrorType get_y(Point *p, double *out_var) {
    if(p == NULL || out_var == NULL) {
        return ERROR_NULL_POINTER;
    }
    *out_var = p->y;
    return ERROR_OK;
}


// Função que acessa o valor dos pontos x e y de uma coordenada.
ErrorType get_coords(Point *p, double *out_x, double *out_y) {
    if(p == NULL || out_x == NULL || out_y == NULL) {
        return ERROR_NULL_POINTER;
    }
    *out_x = p->x;
    *out_y = p->y;
    return ERROR_OK;
}

// Função que atribui o valor do ponto x de uma coordenada.
ErrorType set_x(Point *p, double x) {
    if(p == NULL) {
        return ERROR_NULL_POINTER;
    }
    p->x = x;
    return ERROR_OK;
}

// Função que atribui o valor do ponto y de uma coordenada.
ErrorType set_y(Point *p, double y) {
    if(p == NULL) {
        return ERROR_NULL_POINTER;
    }
    p->y = y;
    return ERROR_OK;
}

// Função que atribui o valor do ponto x e y de uma coordenada.
ErrorType set_coords(Point *p, double x, double y) {
    if(p == NULL) {
        return ERROR_NULL_POINTER;
    }
    p->x = x;
    p->y = y;
    return ERROR_OK;
}

// Função que retorna a distâcia entre dois pontos.
ErrorType distance_between_points(Point *p1, Point *p2, double *out_var) {
    if(p1 == NULL || p2 == NULL || out_var == NULL) {
        return ERROR_NULL_POINTER;
    }
    *out_var = sqrt(((p2->y - p1->y) * (p2->y - p1->y)) + ((p2->x - p1->x) * (p2->x - p1->x)));
    return ERROR_OK;
}

// Função que copia o ponto source para o destination.
ErrorType point_copy(Point *src, Point *dest) {
    if(src == NULL || dest == NULL) {
        return ERROR_NULL_POINTER;
    }
    *dest = *src;
    return ERROR_OK;
}

// Função que troca os valores das coordenadas de dois pontos.
ErrorType point_swap(Point *p1, Point *p2) {
    if(p1 == NULL || p2 == NULL) {
        return ERROR_NULL_POINTER;
    }
    Point aux = *p1;
    *p1 = *p2;
    *p2 = aux;
    return ERROR_OK;
}