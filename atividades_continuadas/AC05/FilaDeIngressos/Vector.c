#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h> // para SIZE_MAX
#include "Vector.h"

// Definição do struct
struct vector {
    int *data; 
    size_t size;
    size_t capacity;
};

// Definição de uma macro para verificar se 
// o tamanho do array não ultrapassou o máximo permitido.
#define size_check(n,type) ((n) <= (SIZE_MAX / sizeof(type)))

// Aloca memória para um vetor vazio com capacidade para 1 elemento.
// Caso não seja possível alocar, retorna NULL.
Vector* vector_create(void) {
    Vector* ptr = (Vector*) malloc(sizeof(Vector));
    if(ptr == NULL) { // não foi possível alocar o struct vector
        return NULL; 
    }
    ptr->data = (int*) malloc(sizeof(int));
    if(ptr->data == NULL) { // não foi possível alocar o array o int
        free(ptr);
        return NULL;
    }
    ptr->size = 0;
    ptr->capacity = 1;
    return ptr;
}

// Libera toda a memória que foi alocada dinamicamente:
// Primeiramente, checa se v não é nulo.
// Se v não for nulo, libera a memória do array 'data' e do próprio struct vector.
// Retorna NULL.
Vector* vector_free(Vector *v) {
    if(v != NULL) {
        free(v->data);
        free(v);
    }
    return NULL;
}

// Ajusta a capacidade do vetor para que seja igual a new_capacity.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Se new_capacity == 0, então ele não faz nada e retorna ERROR_INVALID_ARGUMENT.
// Se não for possível alocar por qualquer outro motivo, deixa o vetor como está e 
// retorna ERROR_ALLOCATION.
// Caso tudo dê certo, retorna ERROR_OK.
// Note que o resize pode tanto diminuir quanto aumentar a capacidade do vector.
ErrorType vector_resize(Vector *v, size_t new_capacity) {
    if(v == NULL) return ERROR_NULL_POINTER;
    if(new_capacity == 0) return ERROR_INVALID_ARGUMENT;
    if(!size_check(new_capacity,int)) return ERROR_ALLOCATION;
    int *ptr = (int*) realloc(v->data, new_capacity * sizeof(int));
    if(ptr == NULL) {
        return ERROR_ALLOCATION;
    }
    v->data = ptr;
    v->capacity = new_capacity;
    if(v->size > new_capacity) {
        v->size = new_capacity;
    }
    return ERROR_OK;
}

// Insere um elemento ao final do vetor.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Antes de inserir, verifica se o vetor está cheio. 
// Se estiver cheio, ele dobra a capacidade do vetor e, 
// então, insere o elemento e retorna ERROR_OK.
ErrorType vector_push_back(Vector *v, int value) {
    if(v == NULL) return ERROR_NULL_POINTER;
    if(v->size == v->capacity) {
        if(!size_check(2*v->capacity,int)) return ERROR_ALLOCATION;
        ErrorType err = vector_resize(v, 2*v->capacity);
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
ErrorType vector_pop_back(Vector *v) {
    if(v == NULL) return ERROR_NULL_POINTER;
    if(v->size == 0) return ERROR_EMPTY;
    v->size--;
    if(v->size < v->capacity / 2) {
        vector_resize(v, v->capacity/2);
    }
    return ERROR_OK;
}

// Devolve true se e somente se o vetor estiver vazio.
// O ponteiro para o vetor deve ser diferente de NULL;
// caso contrário, o comportamento será indeterminado.
bool vector_empty(const Vector *v) {
    return v->size == 0;
}

// Devolve o número de elementos no vetor.
// O ponteiro para o vetor deve ser diferente de NULL; 
// caso contrário, o comportamento será indeterminado.
size_t vector_size(const Vector *v) {
    return v->size;
}

// Devolve a capacidade atual do vetor.
// O ponteiro para o vetor deve ser diferente de NULL; 
// caso contrário, o comportamento será indeterminado.
size_t vector_capacity(const Vector *v) {
    return v->capacity;
}

// Recebe como entrada: um ponteiro para um vetor, 
// um índice e um ponteiro para uma variável externa. 
// Se os ponteiros forem nulos, então retorna ERROR_NULL_POINTER.
// Se o índice for inválido, retorna ERROR_OUT_OF_BOUNDS.
// Se tudo der certo, copia o valor do elemento na variável externa e retorna ERROR_OK.
ErrorType vector_get(const Vector *v, size_t index, int *out_value) {
    if(v == NULL || out_value == NULL) return ERROR_NULL_POINTER;
    if(index >= v->size) return ERROR_OUT_OF_BOUNDS;
    *out_value = v->data[index];
    return ERROR_OK;
}

// Atualiza o valor do elemento que está no índice informado.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Se o índice for inválido, retorna ERROR_OUT_OF_BOUNDS.
// Se tudo der certo, atualiza o valor do elemento e retorna ERROR_OK.
ErrorType vector_set(Vector *v, size_t index, int value) {
    if(v == NULL) return ERROR_NULL_POINTER;
    if(index >= v->size) return ERROR_OUT_OF_BOUNDS;
    v->data[index] = value;
    return ERROR_OK;
}

// Se o vetor for não vazio, essa função guarda o valor do primeiro elemento do vetor
// na variável apontada por 'out_value' e retorna ERROR_OK.
// Se o vetor estiver vazio, retorna ERROR_EMPTY.
// Se os ponteiros forem nulos, então retorna ERROR_NULL_POINTER.
ErrorType vector_front(const Vector *v, int *out_value) {
    if(v == NULL || out_value == NULL) return ERROR_NULL_POINTER;
    if(v->size == 0) return ERROR_EMPTY;
    *out_value = v->data[0];
    return ERROR_OK;
}

// Se o vetor for não vazio, essa função guarda o valor do último elemento do vetor
// na variável apontada por 'out_value' e retorna ERROR_OK.
// Se o vetor estiver vazio, retorna ERROR_EMPTY.
// Se os ponteiros forem nulos, então retorna ERROR_NULL_POINTER.
ErrorType vector_back(const Vector *v, int *out_value) {
    if(v == NULL || out_value == NULL) return ERROR_NULL_POINTER;
    if(v->size == 0) return ERROR_EMPTY;
    *out_value = v->data[v->size - 1];
    return ERROR_OK;
}

// Essa funcao remove todas as ocorrencias do elemento 'value' do vetor.
// Nao esqueca de decrementar o valor do atributo 'size' sempre que um value for removido da lista.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Se v->size == 0, então retorna ERROR_OK pois não há nada a remover.
// Complexidade: O(n) no pior caso.
ErrorType vector_remove_all(Vector *v, int value) {
    if(v == NULL) return ERROR_NULL_POINTER;
    if(v->size == 0) return ERROR_OK;
    for(size_t i = 0; i < v->size; i++)
        if(v->data[i] == value) {
            vector_erase(v, i);
            i--;
        }
    return ERROR_OK;
}

// Insere um elemento na lista, no índice que foi informado.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Se o índice for inválido, retorna ERROR_OUT_OF_BOUNDS.
// Se tudo der certo, insere o elemento e retorna ERROR_OK.
// Complexidade: O(n) no pior caso.
ErrorType vector_insert(Vector *v, size_t index, int value) {
    if(v == NULL) return ERROR_NULL_POINTER;
    if(index > v->size) return ERROR_OUT_OF_BOUNDS;
    if(v->size == v->capacity) {
        if(size_check(2 * v->capacity, int)) {
            ErrorType err = vector_resize(v, 2 * v->capacity); // Houve um overflow
            if(err != ERROR_OK) return err;
        } else {
            return ERROR_ALLOCATION;
        }
    }
    for(size_t i = v->size; i > index; i--)
        v->data[i] = v->data[i-1];
    v->data[index] = value;
    v->size++;
    return ERROR_OK;
}

// Remove da lista o elemento que está no índice informado.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Se o índice for inválido, retorna ERROR_OUT_OF_BOUNDS.
// Se tudo der certo, remove o elemento e retorna ERROR_OK.
// Após remover, se (size < capacity/2) então diminui o tamanho do vetor.
// Complexidade: O(n) no pior caso.
ErrorType vector_erase(Vector *v, size_t index) {
    if(v == NULL) return ERROR_NULL_POINTER;
    if(index >= v->size) return ERROR_OUT_OF_BOUNDS;
    for(size_t i = index + 1; i < v->size; i++)
        v->data[i-1] = v->data[i];
    v->size--;
    if(v->size < v->capacity / 2) {
        size_t new_capacity = v->capacity / 2;
        if(new_capacity == 0)
            new_capacity = 1;
        vector_resize(v, new_capacity);
    }
    return ERROR_OK;
}

// Copia todo o conteúdo do vetor source no vetor destiny.
// Se pelo menos um dos ponteiros for nulo, não faz nada e retorna ERROR_NULL_POINTER.
// Se o vetor destiny for menor que o vetor source, a função deve fazer os ajustes
// necessários para que a cópia possa ser realizada.
// Não esqueça de desalocar memória se for necessário.
// Se houver algum erro de alocação de memória, retornar ERROR_ALLOCATION.
// Se a cópia for bem sucedida, então retornar ERROR_OK.
// Ao final desta função, os dois vetores devem ter o mesmo conteúdo e mesmo tamanho.
ErrorType vector_copy(Vector *source, Vector *destiny) {
    if(source == NULL || destiny == NULL) return ERROR_NULL_POINTER;
    if(destiny->size < source->size) {
        ErrorType err = vector_resize(destiny, source->size);
        if(err != ERROR_OK) return err;
    }
    for(size_t i = 0; i < source->size; i++)
        destiny->data[i] = source->data[i];
    destiny->size = source->size;
    return ERROR_OK;
}