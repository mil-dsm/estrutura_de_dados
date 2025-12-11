// ------------------------------------------------
// ESTE ARQUIVO JA ESTA FINALIZADO, NAO MEXA NELE
// ------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Matrix.h"

#define MAX_CMD 128

void print_matrix(const Matrix *mat) {
    int l, c;
    matrix_rows(mat, &l);
    matrix_columns(mat, &c);

    int val;
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            matrix_getValue(mat, i, j, &val);
            printf("%5d", val);
        }
        printf("\n");
    }
}

int main() {
    Matrix **matrizes = NULL;
    int nmatrizes = 0;

    char line[MAX_CMD];

    while (1) {
        if (!fgets(line, sizeof(line), stdin))
            break;

        line[strcspn(line, "\n")] = '\0'; // remove '\n'

        char comando[32];
        if (sscanf(line, "%31s", comando) != 1)
            continue;

        if (strcmp(comando, "exit") == 0) {
            for (int i = 0; i < nmatrizes; ++i)
                matrix_free(matrizes[i]);
            free(matrizes);
            return 0;
        }

        else if (strcmp(comando, "creatematrix") == 0) {
            int l, c;
            if (sscanf(line, "%*s %d %d", &l, &c) != 2) {
                printf("argumentos invalidos\n");
                continue;
            }

            Matrix *m = matrix_create(l, c);
            if (!m) {
                printf("erro ao criar matriz\n");
                continue;
            }

            // lê cada um dos valores e armazena na matriz
            for (int i = 0; i < l; ++i) {
                for (int j = 0; j < c; ++j) {
                    int val;
                    scanf("%d", &val);
                    matrix_setValue(m, i, j, val);
                }
            }
            getchar(); // consome '\n' pendente

            matrizes = realloc(matrizes, (nmatrizes + 1) * sizeof(Matrix *));
            matrizes[nmatrizes++] = m;
        }

        else if (strcmp(comando, "printmatrix") == 0) {
            int k;
            if (sscanf(line, "%*s %d", &k) != 1 || k < 0 || k >= nmatrizes) {
                printf("indice invalido\n");
                continue;
            }

            print_matrix(matrizes[k]);
            
        }

        else if (strcmp(comando, "nlinhas") == 0) {
            int k;
            if (sscanf(line, "%*s %d", &k) == 1 && k >= 0 && k < nmatrizes) {
                int l;
                matrix_rows(matrizes[k], &l);
                printf("linhas: %d\n", l);
            } else {
                printf("indice invalido\n");
            }
        }

        else if (strcmp(comando, "ncolunas") == 0) {
            int k;
            if (sscanf(line, "%*s %d", &k) == 1 && k >= 0 && k < nmatrizes) {
                int c;
                matrix_columns(matrizes[k], &c);
                printf("colunas: %d\n", c);
            } else {
                printf("indice invalido\n");
            }
        }

        else if (strcmp(comando, "getvalor") == 0) {
            int i, j, k;
            if (sscanf(line, "%*s %d %d %d", &i, &j, &k) == 3 &&
                k >= 0 && k < nmatrizes) {
                int val;
                if (matrix_getValue(matrizes[k], i, j, &val) == ERROR_OK)
                    printf("valor: %d\n", val);
                else
                    printf("indices invalidos\n");
            } else {
                printf("argumentos invalidos\n");
            }
        }

        else if (strcmp(comando, "sum") == 0) {
            int p, q;
            if (sscanf(line, "%*s %d %d", &p, &q) == 2 && p >= 0 && q >= 0 && p < nmatrizes && q < nmatrizes) {
                int linha, coluna;
                matrix_rows(matrizes[p], &linha);
                matrix_columns(matrizes[p], &coluna);
                Matrix *mres = matrix_create(linha, coluna); 
                if(matrix_sum(matrizes[p], matrizes[q], mres) == ERROR_OK)
                    print_matrix(mres);
                else 
                    printf("nao foi possivel somar\n");
                matrix_free(mres);
            } else {
                printf("indices invalidos\n");
            }
        }

        else if (strcmp(comando, "multiply") == 0) {
            int p, q;
            if (sscanf(line, "%*s %d %d", &p, &q) == 2 && p >= 0 && q >= 0 && p < nmatrizes && q < nmatrizes) {
                int linha, coluna;
                matrix_rows(matrizes[p], &linha);
                matrix_columns(matrizes[q], &coluna);
                Matrix *mres = matrix_create(linha, coluna); 
                if(matrix_multiply(matrizes[p], matrizes[q], mres) == ERROR_OK)
                    print_matrix(mres);
                else 
                    printf("nao foi possivel multiplicar\n");
                matrix_free(mres);
            } else {
                printf("indices invalidos\n");
            }
        }

        else {
            printf("comando inexistente\n");
        }
    }

    return 0;
}