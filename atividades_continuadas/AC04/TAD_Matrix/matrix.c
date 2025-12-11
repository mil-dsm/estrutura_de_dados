#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>

struct matrix {
    int m_rows;    // número de linhas da matriz
    int n_columns; // número de colunas da matriz
    int *array;    // ponteiro para um vetor que simula a matriz de inteiros (deve ser alocado)
};

// Completar a implementação

// Aloca dinamicamente uma matriz de inteiros com m linhas e n colunas.
// Se m <= 0 ou n <= 0 então retorna NULL.
// Se ocorrer algum problema na alocação, então retorna NULL também.
Matrix* matrix_create(int m, int n){
    Matrix *p = (Matrix *) malloc(sizeof(Matrix));
    if(!p || m <= 0 || n <= 0){
        return NULL;
    }
    p->array = (int *) malloc(m * n * sizeof(int));
    if(p->array == NULL){
        return NULL;
    }
    p->m_rows = m;
    p->n_columns = n;
    return p;
}

// Libera toda a memória que foi alocada dinamicamente para a matriz.
// Imprime na tela a string "matriz liberada\n".
void matrix_free(Matrix *pm){
    free(pm->array);
    free(pm);
    printf("matriz liberada\n");
}

// Retorna o numero de linhas da matriz.
// Se qualquer um dos ponteiros for nulo, retorna ERROR_NULL_POINTER.
// Se der tudo certo, retorna ERROR_OK.
ErrorMatrix matrix_rows(const Matrix *pm, int *out_rows){
    if(!pm || !out_rows){
        return ERROR_NULL_POINTER;
    }
    *out_rows = pm->m_rows;
    return ERROR_OK;
}

// Retorna o numero de colunas da matriz
// Se qualquer um dos ponteiros for nulo, retorna ERROR_NULL_POINTER.
// Se der tudo certo, retorna ERROR_OK.
ErrorMatrix matrix_columns(const Matrix *pm, int *out_columns){
    if(!pm || !out_columns){
        return ERROR_NULL_POINTER;
    }
    *out_columns = pm->n_columns;
    return ERROR_OK;
}

// Retorna o valor inteiro contido na celula [i][j] da matriz.
// Se i ou j forem inválidos, retorna ERROR_INVALID_ARGUMENT.
// Se qualquer um dos ponteiros for nulo, retorna ERROR_NULL_POINTER.
// Se der tudo certo, retorna ERROR_OK.
ErrorMatrix matrix_getValue(const Matrix *pm, int i, int j, int *value){
    if(!pm || !value){
        return ERROR_NULL_POINTER;
    }
    if(i < 0 || i >= pm->m_rows || j < 0 || j >= pm->n_columns){
        return ERROR_INVALID_ARGUMENT;
    }
    *value = *(pm->array + (i * pm->n_columns + j));
    return ERROR_OK;
}

// Atribui o valor new_value para a celula [i][j] da matriz.
// Se i ou j forem inválidos, retorna ERROR_INVALID_ARGUMENT.
// Se qualquer um dos ponteiros for nulo, retorna ERROR_NULL_POINTER.
// Se der tudo certo, retorna ERROR_OK.
ErrorMatrix matrix_setValue(Matrix *pm, int i, int j, int new_value){
    if(!pm){
        return ERROR_NULL_POINTER;
    }
    if(i < 0 || i >= pm->m_rows || j < 0 || j >= pm->n_columns){
        return ERROR_INVALID_ARGUMENT;
    }
    *(pm->array + (i * pm->n_columns + j)) = new_value;
    return ERROR_OK;
}

// Recebe como entrada ponteiros para 3 matrizes: a, b e c.
// Essa função multiplica a matriz 'a' pela matrix 'b' e 
// coloca o resultado da multiplicação na matriz 'c'.
// Se qualquer um dos ponteiros for nulo, retorna ERROR_NULL_POINTER.
// Se não for possível multiplicar por causa de incompatibilidade 
// nas dimensões das matrizes a, b e c, então a função retorna ERROR_INVALID_ARGUMENT.
// Se der tudo certo na multiplicação, retorna ERROR_OK.
ErrorMatrix matrix_multiply(const Matrix *a, const Matrix *b, Matrix *c){
    if(!a || !b || !c){
        return ERROR_NULL_POINTER;
    }
    if(a->n_columns != b->m_rows){
        return ERROR_INVALID_ARGUMENT;
    }
    if(c->m_rows != a->m_rows || c->n_columns != b->n_columns){
        return ERROR_INVALID_ARGUMENT;
    }
    for(int i = 0; i < a->m_rows; i++){
        for(int j = 0; j < b->n_columns; j++){
            int soma = 0;
            for(int k = 0; k < a->n_columns; k++){
                int *a_ik = (a->array +  (i * a->n_columns + k));
                int *b_kj = (b->array + (k * b->n_columns + j));
                soma += (*a_ik) * (*b_kj);
            }
            *(c->array + (i * b->n_columns + j)) = soma;
        }
    }
    return ERROR_OK;
}

// Recebe como entrada ponteiros para 3 matrizes: a, b e c.
// Essa função soma a matriz 'a' e a matrix 'b' e 
// coloca o resultado da soma na matriz 'c'.
// A matriz 'c' já foi criada fora da função.
// Se qualquer um dos ponteiros for nulo, retorna ERROR_NULL_POINTER.
// Se não for possível somar por causa de incompatibilidade 
// nas dimensões das matrizes a, b e c, então a função retorna ERROR_INVALID_ARGUMENT.
// Se der tudo certo na soma, retorna ERROR_OK.
ErrorMatrix matrix_sum(const Matrix *a, const Matrix *b, Matrix *c){
    if(!a || !b || !c){
        return ERROR_NULL_POINTER;
    }
    if(a->m_rows != b->m_rows || a->n_columns != b->n_columns || a->m_rows != c->m_rows || a->n_columns != c->n_columns){
        return ERROR_INVALID_ARGUMENT;
    }
    for(int i = 0; i < a->m_rows * a->n_columns; i++){
        *(c->array + i) = *(a->array + i) + *(b->array + i);
    }
    return ERROR_OK;
}