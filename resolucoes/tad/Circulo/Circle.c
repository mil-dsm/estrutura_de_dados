#include <stdlib.h>
#include <math.h>
#include <stdbool>
#include "Point.h"
#include "Circle.h"

struct circle {
    Point *center;
    double radius;
};

// Cria um círculo padrão.
// Cria um círculo com centro na origem (0,0) e com raio igual a 1.0
// Retorna NULL se não foi possível alocar.
Circle* circle_default_create(void) {
    Circle *c = (Circle*) malloc(sizeof(Circle));
    if(c == NULL) {
        return NULL;
    }
    c->center = create_point(0, 0);
    if(c->center == NULL) {
        free(c);
        return NULL;
    }
    c->radius = 1;
    return c;
}

// Cria um círculo com centro (x, y) e raio radius.
// Retorna NULL se não foi possível alocar.
Circle* circle_create(double x, double y, double radius) {
    Circle *c = (Circle*) malloc(sizeof(Circle));
    if(c == NULL) {
        return NULL;
    }
    c->center = create_point(x, y);
    if(c->center == NULL) {
        return NULL;
    }
    if(radius < 0) {
        free_point(c->center);
        free(c);
        return NULL;
    }
    c->radius = radius;
    return c;
}

// Libera a memória de um círculo previamente criado
void circle_free(Circle *c) {
    if(c != NULL) {
        free_point(c->center);
        free(c);
    }
}

// Obtém as coordenadas do centro do círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_get_center(Circle *c, double *out_x, double *out_y) {
    if(c == NULL || out_x == NULL || out_y == NULL) {
        return ERROR_NULL_POINTER;
    }
    ErrorType err = get_coords(c->center, out_x, out_y);
    return err;
}

// Obtém o valor do raio.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_get_radius(Circle *c, double *out_var) {
    if(c == NULL || out_var == NULL) {
        return ERROR_NULL_POINTER;
    }
    *out_var = c->radius;
    return ERROR_OK;
}

// Modifica o valor das coordenadas do centro do círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_set_center(Circle *c, double x, double y) {
    if(c == NULL) {
        return ERROR_NULL_POINTER;
    }
    ErrorType err = set_coords(c->center, x, y);
    if(err != ERROR_OK) return err;
    return ERROR_OK;
}

// Modifica o valor da coordenada x do centro do círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_set_xcenter(Circle *c, double x) {
    if(c == NULL) {
        return ERROR_NULL_POINTER;
    }
    ErrorType err = set_x(c->center, x);
    return err;
}

// Modifica o valor da coordenada y do centro do círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_set_ycenter(Circle *c, double y) {
    if(c == NULL) {
        return ERROR_NULL_POINTER;
    }
    ErrorType err = set_y(c->center, y);
    return err;
}

// Modifica o valor do raio.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_set_radius(Circle *c, double radius) {
    if(c == NULL) {
        return ERROR_NULL_POINTER;
    }
    if(radius < 0) {
        return ERROR_INVALID_VALUE;
    }
    c->radius = radius;
    return ERROR_OK;
}

// Função que retorna o valor da perimetro do círculo.
ErrorType circle_perimeter(Circle *c, double *out_var) {
    if(c == NULL || out_var == NULL) {
        return ERROR_NULL_POINTER;
    }
    *out_var = 2 * PI * c->radius;
    return ERROR_OK;
}

// Função que retorna o valor da área do círculo.
ErrorType circle_area(Circle *c, double *out_var) {
    if(c == NULL || out_var == NULL) {
        return ERROR_NULL_POINTER;
    }
    *out_var = PI * c->radius * c->radius;
    return ERROR_OK;
}

ErrorType circle_contains(Circle *c, Point *p, bool *is_contained) {
    if(c == NULL || p == NULL || is_contained == NULL) {
        return ERROR_NULL_POINTER;
    }

    double dist;
    ErrorType err = distance_between_points(c->center, p, &dist);
    if(err != ERROR_OK) return err;

    (dist <= c->radius) ? *is_contained = true : *is_contained = false;
    return ERROR_OK;
}