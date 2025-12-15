#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Matrix.h"

int main() {
    // Teste da função matrix_print()
    Matrix *m = matrix_create(3, 3);
    int num = 0;
    for(size_t i = 0; i < 3; i++) {
        for(size_t j = 0; j < 3; j++) {
            ErrorType err = matrix_set(m, i, j, ++num);
            if(err != ERROR_OK) {
                printf("Erro ao setar (%zu, %zu)\n", i, j);
            }
        }
    }
    matrix_print(m);
}