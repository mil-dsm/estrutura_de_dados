#include <stdbool.h>
#include "Point.h"
#include "Circle.h"
#include <stdlib.h>
#include <math.h>

struct circle{
    double radius;
    Point *center;
};

// Cria um círculo com centro na origem (0,0) e com raio igual a 1.0
// Retorna NULL se não foi possível alocar.
Circle* circle_create_default(void){
    Circle *c = (Circle *) malloc(sizeof(Circle));
    if(!c){
        return NULL;
    }
    c->center = create_point_default();
    c->radius = 1.0;
    return c;
}

// Cria um círculo passando como argumento o ponto central e o raio.
// Retorna NULL se não foi possível alocar.
Circle* circle_create(double x, double y, double radius){
    Circle *c = (Circle *) malloc(sizeof(Circle));
    if(!c){
        return NULL;
    }
    c->center = create_point_with_coords(x, y);
    c->radius = radius;
    return c;
}

// Obtém o valor do raio.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_get_radius(Circle *c, double *out_var){
    if(!c || !out_var){
        return ERROR_NULL_POINTER;
    }
    *out_var = c->radius;
    return ERROR_OK;
}

// Obtém as coordenadas do centro do círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_get_center(Circle *c, double *out_x, double *out_y){
    if(!c || !out_x || !out_y){
        return ERROR_NULL_POINTER;
    }
    double x, y;
    get_coords(c->center, &x, &y);
    *out_x = x;
    *out_y = y;
    return ERROR_OK;
}

// Modifica o valor do raio.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_set_radius(Circle *c, double radius){
    if(!c){
        return ERROR_NULL_POINTER;
    }
    c->radius = radius;
    return ERROR_OK;
}

// Modifica o valor das coordenadas do centro do círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_set_center(Circle *c, double x, double y){
    if(!c){
        return ERROR_NULL_POINTER;
    }
    set_coords(c->center, x, y);
    return ERROR_OK;
}

// Modifica o valor da coordenada x do centro do círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_set_xcenter(Circle *c, double x){
    if(!c){
        return ERROR_NULL_POINTER;
    }
    set_x(c->center, x);
    return ERROR_OK;
}

// Modifica o valor da coordenada y do centro do círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_set_ycenter(Circle *c, double y){
    if(!c){
        return ERROR_NULL_POINTER;
    }
    set_y(c->center, y);
    return ERROR_OK;
}

// Obtém o valor da área do círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_area(Circle *c, double *out_area){
    if(!c){
        return ERROR_NULL_POINTER;
    }
    *out_area = PI * c->radius * c->radius;
    return ERROR_OK;
}

// Recebe como entrada um círculo e um ponto e retorna "true" se e somente se
// o ponto estiver contido no círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_contains(Circle *c, Point *p, bool *is_contained){
    if(!c || !p || !is_contained){
        return ERROR_NULL_POINTER;
    }
    double xc, yc, xp, yp;
    get_coords(c->center, &xc, &yc);
    get_coords(p, &xp, &yp);
    double dx = xp - xc;
    double dy = yp - yc;
    double dist = sqrt(dx * dx + dy * dy);
    if(dist <= c->radius){
        *is_contained = true;
    }
    else{
        *is_contained = false;
    }
    return ERROR_OK;
}

// Libera a memória associada a um círculo.
// Retorna sempre NULL, permitindo a escrita segura: c = circle_free(c);
Circle* circle_free(Circle *c){
    free_point(c->center);
    free(c);
    return NULL;
}