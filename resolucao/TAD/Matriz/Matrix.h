#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix Matrix;

typedef enum { ERROR_OK, ERROR_NULL_POINTER, ERROR_OUT_OF_BOUNDS, ERROR_INVALID_VALUE } ErrorType;

// Cria uma matrix com n linhas e m colunas.
// Retorna um ponteiro para a matrix criada.
// Caso ocorra erro de alocação, retorna NULL.
Matrix* matrix_create(size_t n, size_t m);

// Libera toda a memória alocada dinamicamente para a matrix.
void matrix_free(Matrix *mat);

// Retorna o valor armazenado na posição (i, j) da matrix.
ErrorType matrix_get(Matrix *mat, size_t i, size_t j, int *out_var);

// Define o valor da posição (i, j) da matrix como val.
ErrorType matrix_set(Matrix *mat, size_t i, size_t j, int val);

// Retorna a quantidade de linhas da matrix.
ErrorType matrix_get_rows(Matrix *mat, size_t *out_var);

// Retorna a quantidade de colunas da matrix.
ErrorType matrix_get_columns(Matrix *mat, size_t *out_var);

// Imprime a matrix no formato de linhas e colunas.
void matrix_print(Matrix *mat);

// Verifica se duas matrixes são iguais.
// Retorna true se tiverem mesmas dimensões e mesmos valores.
ErrorType matrix_equals(Matrix *mat1, Matrix *mat2, bool *is_equal);

// Realiza a soma entre duas matrixes.
// Retorna um código de erro ou sucesso conforme a implementação.
ErrorType matrix_sum(Matrix *mat1, Matrix *mat2, Matrix *out_result);

// Realiza a multiplicação entre duas matrixes.
// Retorna um código de erro ou sucesso conforme a implementação.
ErrorType matrix_mutiply(Matrix *mat1, Matrix *mat2, Matrix *out_result);

#endif