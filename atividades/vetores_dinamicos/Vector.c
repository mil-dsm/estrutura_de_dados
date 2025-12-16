#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Vector.h"

struct vector {
    int *data;
    size_t capacity;
    size_t size;
};

// Aloca memória para um vetor vazio com capacidade para 1 elemento.
// Caso não seja possível alocar, retorna NULL.
Vector* vector_create(void) {
    Vector *v = (Vector*)malloc(sizeof(Vector));
    if(v == NULL) {
        free(v);
        return NULL;
    }
    int v->data = (int*)malloc(sizeof(int));
    if(v->data == NULL) {
        free(v->data);
        return NULL;
    }
    v->capacity = 1;
    v->size = 0;
    return v;
}

// Libera toda a memória que foi alocada dinamicamente:
// libera a memória do array 'data' e do próprio struct vector.
void vector_free(Vector *v) {
    if(v != NULL) {
        free(v->data);
        free(v);
    }
}

// Ajusta a capacidade do vetor para que seja igual a new_capacity.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Se new_capacity == 0, então ele não faz nada e retorna ERROR_INVALID_ARGUMENT.
// Se não for possível alocar por qualquer outro motivo, deixa o vetor como está e 
// retorna ERROR_ALLOCATION.
// Caso tudo dê certo, retorna ERROR_OK.
ErrorType vector_resize(Vector *v, size_t new_capacity) { // Ajustar
    if(v == NULL) {
        return ERROR_NULL_POINTER;
    }
    if(new_capacity == 0) {
        return ERROR_INVALID_ARGUMENT;
    }
    int *ptr = (int*)realloc(v->data, new_capacity * sizeof(int));
    if(ptr == NULL) {
        return ERROR_ALLOCATION;
    }
    v->data = ptr;
    v->capacity = new_capacity;
    return ERROR_OK;
}

// Devolve true se e somente se o vetor estiver vazio.
// O ponteiro para o vetor deve ser diferente de NULL;
// caso contrário, o comportamento será indeterminado.
bool vector_empty(const Vector *v) {
    if(v == NULL) {
        return ERROR_NULL_POINTER;
    }
    return v->size == 0;
}

// Devolve o número de elementos no vetor.
// O ponteiro para o vetor deve ser diferente de NULL; 
// caso contrário, o comportamento será indeterminado.
size_t vector_size(const Vector *v) {
    if(v != NULL) {
        return v->size;
    }
}

// Devolve a capacidade atual do vetor.
// O ponteiro para o vetor deve ser diferente de NULL; 
// caso contrário, o comportamento será indeterminado.
size_t vector_capacity(const Vector *v) {
    if(v != NULL) {
        return v->capacity;
    }
}

// Insere um elemento ao final do vetor.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Antes de inserir, verifica se o vetor está cheio. 
// Se estiver cheio, ele dobra a capacidade do vetor e, 
// então, insere o elemento e retorna ERROR_OK.
ErrorType vector_push_back(Vector *v, int value) {
    if(v == NULL) {
        return ERROR_NULL_POINTER;
    }
    if(v->size == v->capacity) {
        ErrorType err = vector_resize(v, v->capacity * 2);
        if(err != ERROR_OK) {
            return err;
        }
    }
    v->data[v->size] = value;
    v->size++;
    return ERROR_OK;
}

// Remove um elemento do final da lista.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Se a lista estiver vazia, não faz nada e retorna ERROR_EMPTY.
// Se der certo remover, então e retorna ERROR_OK.
ErrorType vector_pop_back(Vector *v) { // Revisar
    if(v == NULL) {
        return ERROR_NULL_POINTER;
    }
    if(v->size == 0) {
        return ERROR_EMPTY;
    }
    v->size--;
    return ERROR_OK;
}

// Se o vetor for não vazio, essa função guarda o valor do primeiro elemento do vetor
// na variável apontada por 'out_value' e retorna ERROR_OK.
// Se o vetor estiver vazio, retorna ERROR_EMPTY.
// Se os ponteiros forem nulos, então retorna ERROR_NULL_POINTER.
ErrorType vector_front(const Vector *v, int *out_value) {
    if(v == NULL || out_value) {
        return ERROR_NULL_POINTER;
    }
    if(v->size == 0) {
        return ERROR_EMPTY;
    }
    *out_value = v->data[0];
    return ERROR_OK;
}

// Se o vetor for não vazio, essa função guarda o valor do último elemento do vetor
// na variável apontada por 'out_value' e retorna ERROR_OK.
// Se o vetor estiver vazio, retorna ERROR_EMPTY.
// Se os ponteiros forem nulos, então retorna ERROR_NULL_POINTER.
ErrorType vector_back(const Vector *v, int *out_value) {
    if(v == NULL || out_value == NULL) {
        return ERROR_NULL_POINTER;
    }
    if(v->size == 0) {
        return ERROR_EMPTY;
    }
    *out_value = v->data[v->size-1];
    return ERROR_OK;
}

// Libera a memória que foi alocada dinamicamente e reinicializa o vetor
// fazendo ele ter capacity == 1 e size == 0.
// Se vec == NULL, então retorna ERROR_NULL_POINTER.
ErrorType vector_clear(Vector *v) { //Ajustar
    if(v == NULL){
        return ERROR_NULL_POINTER;
    }
    v->capacity = 1;
    v->size = 0;
    return ERROR_OK;
}

// Se new_capacity for maior que a capacidade atual da lista,
// essa função aumenta a capacidade para new_capacity e retorna ERROR_OK.
// Se new_capacity <= capacidade_atual, então não faz nada e retorna ERROR_OK.
// Se vec == NULL, então retorna ERROR_NULL_POINTER.
ErrorType vector_reserve(Vector *v, size_t new_capacity) { // Ajustar
    if(v == NULL) {
        return ERROR_NULL_POINTER;
    }
    ErrorType err;
    if(new_capacity <= v->capacity) {
        return ERROR_OK;
    } else {
        err = vector_resize(v, new_capacity);
    }
    return err;
}

// Recebe como entrada: um ponteiro para um vetor, 
// um índice e um ponteiro para uma variável externa. 
// Se os ponteiros forem nulos, então retorna ERROR_NULL_POINTER.
// Se o índice for inválido, retorna ERROR_OUT_OF_BOUNDS.
// Se tudo der certo, copia o valor do elemento na variável externa e retorna ERROR_OK.
ErrorType vector_get(const Vector *v, size_t index, int *out_value) {
    if(v == NULL || out_value == NULL) {
        return ERROR_NULL_POINTER;
    }
    if(index >= v->size) {
        return ERROR_OUT_OF_BOUNDS;
    }
    *out_value = v->data[index];
    return ERROR_OK;
}

// Atualiza o valor do elemento que está no índice informado.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Se o índice for inválido, retorna ERROR_OUT_OF_BOUNDS.
// Se tudo der certo, atualiza o valor do elemento e retorna ERROR_OK.
ErrorType vector_set(Vector *v, size_t index, int value) {
    if(v == NULL) {
        return ERROR_NULL_POINTER;
    }
    if(index >= v->size) {
        return ERROR_OUT_OF_BOUNDS;
    }
    v->data[index] = value;
    return ERROR_OK;
}

// Recebe como argumento dois vetores e troca o conteúdo deles.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER;
// caso contrário, faz a troca e retorna ERROR_OK.
ErrorType vector_swap(Vector *v1, Vector *v2) { // Revisar
    if(v1 == NULL || v2 == NULL) {
        return ERROR_NULL_POINTER;
    }
    Vector aux = *v1;
    *v1 = *v1;
    *v2 = aux;
    return ERROR_OK;
}

// Insere um elemento na lista, no índice que foi informado.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Se o índice for inválido, retorna ERROR_OUT_OF_BOUNDS.
// Se tudo der certo, insere o elemento e retorna ERROR_OK.
ErrorType vector_insert(Vector *vec, size_t index, int value) {
    if(vec == NULL) {
        return ERROR_NULL_POINTER;
    }
    if(index >= vec->size) {
        return ERROR_OUT_OF_BOUNDS;
    }
    for(size_t i = vec->size - 1; i > index; i--) {
        vec->data[i] = vec->data[i-1];
    }
    vec->data[index] = value;
    vec->size++;
    return ERROR_OK;
}

// Remove da lista o elemento que está no índice informado.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Se o índice for inválido, retorna ERROR_OUT_OF_BOUNDS.
// Se tudo der certo, remove o elemento e retorna ERROR_OK.
// Após remover, se (size < capacity/2) então diminui o tamanho do vetor.
ErrorType vector_erase(Vector *vec, size_t index) { // Revisar
    if(vec == NULL) {
        return ERROR_NULL_POINTER;
    }
    if(index >= vec->size) {
        return ERROR_OUT_OF_BOUNDS;
    }
    for(size_t i = index; i < vec->size; i++) {
        vec->data[i] = vec->data[i+1];
    }
    vec->size--;
    // if(vec->size < vec->capacity/2) {
        
    // }
    return ERROR_OK;
}

// Faz a lista reduzir sua capacidade para que fique igual ao seu tamanho(size).
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Se size == 0, então faz capacity == 1; caso contrário, faz capacity == size.
ErrorType vector_shrink_to_fit(Vector *vec) {
    if(vec == NULL) {
        return ERROR_NULL_POINTER;
    }
    if(vec->size == 0) {
        vec->capacity = 1;
    } else {
        vec->capacity = vec->size;
    }
    return ERROR_OK;
}