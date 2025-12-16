#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Vector.h"

int main() {
    Vector *v = vector_create();
    ErrorType err;
    for(int i = 0; i < 10; i++) {
        err = vector_push_back(v, i+1);
        if(err != ERROR_OK) {
            break;
        }
    }
    size_t size = vector_size(v);
    for(size_t i = 0; i < vector_size(v); i++) {
        int x;
        err = vector_get(v, i, &x);
        if(err != ERROR_OK)
            break;
        printf("%d ", x);
    }
}