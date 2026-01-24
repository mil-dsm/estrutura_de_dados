#include <stdio.h>

int main(){
    Vector* vec = vector_create();

    printf("Processando...\n");
    for(int i = 0; i <= 10; i++) {
        vector_push_back(vec, i);
        printf("numero inserido: %d\n", i);
        printf("size: %ld\n", vector_size(vec));
        printf("capacity: %ld\n", vector_capacity(vec));
    }
    vector_shrink_to_fit(vec);
    printf("\n\nEstado atual:\n");
    printf("size: %ld\n", vector_size(vec));
    printf("capacity: %ld\n", vector_capacity(vec));

    printf("\n....................\n\n");

    for(size_t i = 0; i < vector_size(vec); i++) {
        int value;
        vector_get(vec, i, value);
        printf("v[%ld] = %d\n", i, value);
    }

    vec = vector_free(vec);
    return 0;
}