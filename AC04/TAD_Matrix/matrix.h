// ------------------------------------------------
// ESTE ARQUIVO JA ESTA FINALIZADO, NAO MEXA NELE
// ------------------------------------------------
#ifndef MATRIZ_H
#define MATRIZ_H

typedef enum { 
    ERROR_OK,               // não houve erro
    ERROR_ALLOCATION,       // erro de alocação de memória
    ERROR_NULL_POINTER,     // erro de ponteiro nulo
    ERROR_INVALID_ARGUMENT  // um argumento tem valor inválido
} ErrorMatrix;

typedef struct matrix Matrix; // definição do tipo opaco

// Aloca dinamicamente uma matriz de inteiros com m linhas e n colunas.
// Se m <= 0 ou n <= 0 então retorna NULL.
// Se ocorrer algum problema na alocação, então retorna NULL também.
Matrix* matrix_create(int m, int n);

// Libera toda a memória que foi alocada dinamicamente para a matriz.
// Imprime na tela a string "matriz liberada\n".
void matrix_free(Matrix *pm);

// Retorna o numero de linhas da matriz.
// Se qualquer um dos ponteiros for nulo, retorna ERROR_NULL_POINTER.
// Se der tudo certo, retorna ERROR_OK.
ErrorMatrix matrix_rows(const Matrix *pm, int *out_rows);

// Retorna o numero de colunas da matriz
// Se qualquer um dos ponteiros for nulo, retorna ERROR_NULL_POINTER.
// Se der tudo certo, retorna ERROR_OK.
ErrorMatrix matrix_columns(const Matrix *pm, int *out_columns);  

// Retorna o valor inteiro contido na celula [i][j] da matriz.
// Se i ou j forem inválidos, retorna ERROR_INVALID_ARGUMENT.
// Se qualquer um dos ponteiros for nulo, retorna ERROR_NULL_POINTER.
// Se der tudo certo, retorna ERROR_OK.
ErrorMatrix matrix_getValue(const Matrix *pm, int i, int j, int *value);

// Atribui o valor new_value para a celula [i][j] da matriz.
// Se i ou j forem inválidos, retorna ERROR_INVALID_ARGUMENT.
// Se qualquer um dos ponteiros for nulo, retorna ERROR_NULL_POINTER.
// Se der tudo certo, retorna ERROR_OK.
ErrorMatrix matrix_setValue(Matrix *pm, int i, int j, int new_value);

// Recebe como entrada ponteiros para 3 matrizes: a, b e c.
// Essa função multiplica a matriz 'a' pela matrix 'b' e 
// coloca o resultado da multiplicação na matriz 'c'.
// Se qualquer um dos ponteiros for nulo, retorna ERROR_NULL_POINTER.
// Se não for possível multiplicar por causa de incompatibilidade 
// nas dimensões das matrizes a, b e c, então a função retorna ERROR_INVALID_ARGUMENT.
// Se der tudo certo na multiplicação, retorna ERROR_OK.
ErrorMatrix matrix_multiply(const Matrix *a, const Matrix *b, Matrix *c);

// Recebe como entrada ponteiros para 3 matrizes: a, b e c.
// Essa função soma a matriz 'a' e a matrix 'b' e 
// coloca o resultado da soma na matriz 'c'.
// A matriz 'c' já foi criada fora da função.
// Se qualquer um dos ponteiros for nulo, retorna ERROR_NULL_POINTER.
// Se não for possível somar por causa de incompatibilidade 
// nas dimensões das matrizes a, b e c, então a função retorna ERROR_INVALID_ARGUMENT.
// Se der tudo certo na soma, retorna ERROR_OK.
ErrorMatrix matrix_sum(const Matrix *a, const Matrix *b, Matrix *c);

#endif