#ifndef POINT_H // Evita que o codigo seja repetido varias vezes // if not define
// Se nao tiver sido definido, define e opera o codigo
// Se ja foi definida, pula todo o codigo e pula para o fim do if
#define POINT_H

// declaração de um tipo opaco que representa um ponto
// no espaço bidimensional.
typedef struct point Point;

// Códigos de erro retornados pelas funções do TAD Point.
typedef enum { ERROR_OK, ERROR_NULL_POINTER, ERROR_ALLOCATION } ErrorType;

// Função que recebe duas coordenadas e retorna 
// um ponteiro para um Point alocado dinamicamente.
// Se o ponteiro for invalido retorna NULL.
Point* create_point(double x, double y);

// Libera a memória associada a um ponto.
void free_point(Point *p);

// Obtém a coordenada x de um ponto.
// Retorna ERROR_OK se bem-sucedido,
// ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType get_x(const Point *p, double *x);

// Obtém a coordenada y de um ponto.
// Retorna ERROR_OK se bem-sucedido,
// ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType get_y(const Point *p, double *y);

// Obtém ambas as coordenadas (x, y) de um ponto.
// Retorna ERROR_OK se bem-sucedido, 
// ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType get_coords(const Point *p, double *x, double *y);

// Define a coordenada x de um ponto.
// Retorna ERROR_OK se bem-sucedido, 
// ERROR_NULL_POINTER caso p seja nulo.
ErrorType set_x(Point *p, double x);

// Define a coordenada y de um ponto.
// Retorna ERROR_OK se bem-sucedido, 
// ERROR_NULL_POINTER caso p seja nulo.
ErrorType set_y(Point *p, double y);

// Define as coordenadas (x, y) de um ponto.
// Retorna ERROR_OK se bem-sucedido, 
// ERROR_NULL_POINTER caso p seja nulo.
ErrorType set_coords(Point *p, double x, double y);

// Calcula a distância euclidiana entre dois pontos.
// retorna ERROR_OK se bem-sucedido, 
// ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType distance_between_points(const Point *p, const Point *q, double *dist);

// Copia o conteúdo de um ponto para outro.
// Retorna ERROR_OK se bem-sucedido, 
// ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType point_copy(const Point *src, Point *dest);

// Troca os valores de dois pontos.
// retorna ERROR_OK se bem-sucedido, 
// ERROR_NULL_POINTER caso algum ponteiro seja nulo.
ErrorType point_swap(Point *p, Point *q);

#endif // Finaliza o comando if