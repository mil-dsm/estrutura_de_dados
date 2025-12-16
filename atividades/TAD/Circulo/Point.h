#ifndef POINT_H
#define POINT_H

typedef struct point Point;

typedef enum { ERROR_OK, ERROR_INVALID_VALUE, ERROR_NULL_POINTER, ERROR_ALLOCATION } ErrorType;

// Função de criação de um ponto.
// Aloca e retorna um ponto com as coordenadas (x, y).
Point* create_point(double x, double y);

// Função para liberar um ponto.
// Libera a memória de um ponto previamente criado.
void free_point(Point *p);

// Função que acessa o valor do ponto x de uma coordenada.
ErrorType get_x(Point *p, double *out_var);

// Função que acessa o valor do ponto y de uma coordenada.
ErrorType get_y(Point *p, double *out_var);

// Função que acessa o valor dos pontos x e y de uma coordenada.
ErrorType get_coords(Point *p, double *out_x, double *out_y);

// Função que atribui o valor do ponto x de uma coordenada.
ErrorType set_x(Point *p, double x);

// Função que atribui o valor do ponto y de uma coordenada.
ErrorType set_y(Point *p, double y);

// Função que atribui o valor do ponto x e y de uma coordenada.
ErrorType set_coords(Point *p, double x, double y);

// Função que retorna a distâcia entre dois pontos.
ErrorType distance_between_points(Point *p1, Point *p2, double *out_var);

// Função que copia o ponto source para o destination.
ErrorType point_copy(Point *src, Point *dest);

// Função que troca os valores das coordenadas de dois pontos.
ErrorType point_swap(Point *p1, Point *p2);

#endif