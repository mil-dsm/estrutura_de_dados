#ifndef CIRCLE_H
#define CIRCLE_H
#include <stdbool.h>
#include "Point.h"

typedef struct circle Circle; // tipo opaco para o TAD Circle

#define PI 3.14159265358979323846 // constante PI, caso necessário

// Cria um círculo com centro na origem (0,0) e com raio igual a 1.0
// Retorna NULL se não foi possível alocar.
Circle* circle_create_default(void);

// Cria um círculo passando como argumento o ponto central e o raio.
// Retorna NULL se não foi possível alocar.
Circle* circle_create(double x, double y, double radius);

// Obtém o valor do raio.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_get_radius(Circle *c, double *out_var);

// Obtém as coordenadas do centro do círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_get_center(Circle *c, double *out_x, double *out_y);

// Modifica o valor do raio.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_set_radius(Circle *c, double radius);

// Modifica o valor das coordenadas do centro do círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_set_center(Circle *c, double x, double y);

// Modifica o valor da coordenada x do centro do círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_set_xcenter(Circle *c, double x);

// Modifica o valor da coordenada y do centro do círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_set_ycenter(Circle *c, double y);

// Obtém o valor da área do círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_area(Circle *c, double *out_area);

// Recebe como entrada um círculo e um ponto e retorna "true" se e somente se
// o ponto estiver contido no círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_contains(Circle *c, Point *p, bool *is_contained);

// Libera a memória associada a um círculo.
// Retorna sempre NULL, permitindo a escrita segura: c = circle_free(c);
Circle* circle_free(Circle *c);

#endif