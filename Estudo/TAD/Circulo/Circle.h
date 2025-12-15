#ifndef CIRCLE_H
#define CIRCLE_H

#define PI 3.14159265358979323846 // constante PI, caso necessário

typedef struct circle Circle;

// Cria um círculo padrão.
// Cria um círculo com centro na origem (0,0) e com raio igual a 1.0
// Retorna NULL se não foi possível alocar.
Circle* circle_default_create(void);

// Cria um círculo com centro (x, y) e raio radius.
// Retorna NULL se não foi possível alocar.
Circle* circle_create(double x, double y, double radius);

// Libera a memória de um círculo previamente criado
void circle_free(Circle *c);

// Obtém as coordenadas do centro do círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_get_center(Circle *c, double *out_x, double *out_y);

// Obtém o valor do raio.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_get_radius(Circle *c, double *out_var);

// Modifica o valor das coordenadas do centro do círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_set_center(Circle *c, double x, double y);

// Modifica o valor da coordenada x do centro do círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_set_xcenter(Circle *c, double x);

// Modifica o valor da coordenada y do centro do círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_set_ycenter(Circle *c, double y);

// Modifica o valor do raio.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_set_radius(Circle *c, double radius);

// Função que retorna o valor da perimetro do círculo.
ErrorType circle_perimeter(Circle *c, double *out_perimeter);

// Função que retorna o valor da área do círculo.
ErrorType circle_area(Circle *c, double *out_area);

// Recebe como entrada um círculo e um ponto e retorna "true" se e somente se
// o ponto estiver contido no círculo.
// Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType circle_contains(Circle *c, Point *p, bool *is_contained);

#endif