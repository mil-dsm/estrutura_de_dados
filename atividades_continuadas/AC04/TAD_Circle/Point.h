// ESTE ARQUIVO JA ESTA PRONTO PARA USO, NAO MEXA NELE
#ifndef POINT_H
#define POINT_H

/**
 * @file Point.h
 * @brief Tipo abstrato de dado (TAD) para representar e manipular pontos no plano cartesiano.
 *
 * Este módulo fornece operações básicas sobre pontos bidimensionais, incluindo
 * criação, destruição, acesso e modificação de coordenadas, além de funções
 * utilitárias como cópia, troca e cálculo de distância entre pontos.
 */

/**
 * Estrutura opaca que representa um ponto no plano.
 * Os detalhes internos da estrutura são ocultos do usuário.
 * As operações sobre pontos devem ser realizadas apenas pelas funções deste módulo.
 */
typedef struct point Point;

/**
 * Códigos de erro retornados pelas funções do TAD Point.
 */
typedef enum {
    ERROR_OK,              /**< Operação bem-sucedida. */
    ERROR_NULL_POINTER,    /**< Ponteiro nulo passado como argumento. */
    ERROR_ALLOCATION       /**< Falha de alocação de memória. */
} ErrorType;

/**
 * Cria um ponto com coordenadas (0, 0).
 * Retorna um ponteiro para o novo ponto criado, 
 * ou NULL se ocorrer falha de alocação.
 */
Point* create_point_default(void);

/**
 * Cria um ponto com coordenadas específicas x e y.
 * Retorna um ponteiro para o novo ponto criado, 
 * ou NULL se ocorrer falha de alocação.
 */
Point* create_point_with_coords(double x, double y);

/**
 * Libera a memória associada a um ponto.
 * Retorna sempre NULL, permitindo a escrita segura: p = free_point(p);
 */
Point* free_point(Point *p);

/**
 * Obtém a coordenada x de um ponto.
 * Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
 */
ErrorType get_x(const Point *p, double *x);

/**
 * Obtém a coordenada y de um ponto.
 * Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
 */
ErrorType get_y(const Point *p, double *y);

/**
 * Obtém ambas as coordenadas (x, y) de um ponto.
 * Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
 */
ErrorType get_coords(const Point *p, double *x, double *y);

/**
 * Define a coordenada x de um ponto.
 * Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso p seja nulo.
 */
ErrorType set_x(Point *p, double x);

/**
 * Define a coordenada y de um ponto.
 * Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso p seja nulo.
 */
ErrorType set_y(Point *p, double y);

/**
 * Define as coordenadas (x, y) de um ponto.
 * Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso p seja nulo.
 */
ErrorType set_coords(Point *p, double x, double y);

/**
 * Calcula a distância euclidiana entre dois pontos.
 * retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
 */
ErrorType distance_between_points(const Point *p, const Point *q, double *dist);

/**
 * Copia o conteúdo de um ponto para outro.
 * Retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
 */
ErrorType point_copy(const Point *src, Point *dest);

/**
 * Troca os valores de dois pontos.
 * retorna ERROR_OK se bem-sucedido, ERROR_NULL_POINTER caso algum ponteiro seja nulo.
 */
ErrorType point_swap(Point *p, Point *q);

#endif /* POINT_H */