#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Matrix.h"

struct matrix {
    size_t rows;
    size_t columns;
    int *data;
};

// Cria uma matrix com n linhas e m colunas.
// Retorna um ponteiro para a matrix criada.
// Caso ocorra erro de alocação, retorna NULL.
Matrix* matrix_create(size_t n, size_t m) {
    Matrix *nova_matrix = (Matrix*) malloc(sizeof(Matrix));
    if(nova_matrix == NULL) {
        return NULL;
    }
    nova_matrix->rows = n;
    nova_matrix->columns = m;
    nova_matrix->data = (int*)malloc(n * m * sizeof(int));
    if(nova_matrix->data == NULL) {
        free(nova_matrix);
        return NULL;
    }
    return nova_matrix;
}

// Libera toda a memória alocada dinamicamente para a matrix.
void matrix_free(Matrix *mat) {
    if(mat != NULL) {
        free(mat->data);
        free(mat);
    }
}

// Retorna o valor armazenado na posição (i, j) da matrix.
ErrorType matrix_get(Matrix *mat, size_t i, size_t j, int *out_var) {
    if(mat == NULL || out_var == NULL) {
        return ERROR_NULL_POINTER;
    }
    if(i >= mat->rows || j >= mat->columns) {
        return ERROR_OUT_OF_BOUNDS;
    }
    *out_var = mat->data[i * mat->columns + j];
    return ERROR_OK;
}

// Define o valor da posição (i, j) da matrix como val.
ErrorType matrix_set(Matrix *mat, size_t i, size_t j, int val) {
    if(mat == NULL) {
        return ERROR_NULL_POINTER;
    }
    if(i >= mat->rows || j >= mat->columns) {
        return ERROR_OUT_OF_BOUNDS;
    }
    mat->data[i * mat->columns + j] = val;
    return ERROR_OK;
}

// Retorna a quantidade de linhas da matrix.
ErrorType matrix_get_rows(Matrix *mat, size_t *out_var) {
    if(mat == NULL || out_var == NULL) {
        return ERROR_NULL_POINTER;
    }
    *out_var = mat->rows;
    return ERROR_OK;
}

// Retorna a quantidade de colunas da matrix.
ErrorType matrix_get_columns(Matrix *mat, size_t *out_var) {
    if(mat == NULL || out_var == NULL) {
        return ERROR_NULL_POINTER;
    }
    *out_var = mat->columns;
    return ERROR_OK;
}

// Imprime a matrix no formato de linhas e colunas.
void matrix_print(Matrix *mat) {
    if(mat == NULL) {
        return;
    }
    for(size_t i = 0; i < mat->rows; i++) {
        printf("[ ");
        for(size_t j = 0; j < mat->columns; j++) {
            printf("%d ", mat->data[i * mat->columns + j]);
        }
        printf("]\n");
    }
}

// Verifica se duas matrixes são iguais.
// Retorna true se tiverem mesmas dimensões e mesmos valores.
ErrorType matrix_equals(Matrix *mat1, Matrix *mat2, bool *is_equal) {
    if(mat1 == NULL || mat2 == NULL || is_equal == NULL) {
        return ERROR_NULL_POINTER;
    }
    if(mat1->rows != mat2->rows || mat1->columns != mat2->columns) {
        *is_equal = false;
        return ERROR_OK;
    }
    for(size_t i = 0; i < mat1->rows; i++) {
        for(size_t j = 0; j < mat1->columns; j++) {
            if(mat1->data[i * mat1->columns + j] != mat2->data[i * mat2->columns + j]) {
                *is_equal = false;
                return ERROR_OK;
            }
        }
    }
    *is_equal = true;
    return ERROR_OK;
}

// Realiza a soma entre duas matrixes.
// Retorna um código de erro ou sucesso conforme a implementação.
ErrorType matrix_sum(Matrix *mat1, Matrix *mat2, Matrix *out_result) {
    if(mat1 == NULL || mat2 == NULL || out_result == NULL) {
        return ERROR_NULL_POINTER;
    }
    if(mat1->rows != mat2->rows || mat1->columns != mat2->columns || out_result->rows != mat1->rows || out_result->columns != mat1->columns) {
        return ERROR_INVALID_VALUE;
    }
    for(size_t i = 0; i < mat1->rows; i++) {
        for(size_t j = 0; j < mat1->columns; j++) {
            out_result->data[i * out_result->columns + j] = mat1->data[i * mat1->columns + j] + mat2->data[i * mat2->columns + j];
        }
    }
    return ERROR_OK;
}

// Realiza a multiplicação entre duas matrixes.
// Retorna um código de erro ou sucesso conforme a implementação.
ErrorType matrix_mutiply(Matrix *mat1, Matrix *mat2, Matrix *out_result) {
    if(mat1 == NULL || mat2 == NULL || out_result == NULL) {
        return ERROR_NULL_POINTER;
    }
    if(mat1->columns != mat2->rows || out_result->rows != mat1->rows || out_result->columns != mat2->columns) {
        return ERROR_INVALID_VALUE;
    }
    for(size_t i = 0; i < out_result->rows; i++) {
        for(size_t j = 0; j < out_result->columns; j++) {
            int sum = 0;
            for(size_t k = 0; k < mat1->columns; k++) {
                sum += mat1->data[i * mat1->columns + k] * mat2->data[k * mat2->columns + j];
            }
            out_result->data[i * out_result->columns + j] = sum;
        }
    }
    return ERROR_OK;
}