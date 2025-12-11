#ifndef VECTOR_H
#define VECTOR_H
#include <stdio.h>
#include <stdbool.h>

// Declaração de um tipo enumerado para tratamento de erros
typedef enum {
    ERROR_OK,               // Indica que nenhum erro ocorreu
    ERROR_OUT_OF_BOUNDS,    // Índice fora do intervalo válido
    ERROR_ALLOCATION,       // Falha na alocação de memória
    ERROR_EMPTY,            // tentou manipular um vetor vazio
    ERROR_NULL_POINTER,     // Erro de ponteiro nulo
    ERROR_INVALID_ARGUMENT  // Erro de argumento inválido
} ErrorType;

// Declaração do tipo opaco Vector
typedef struct vector Vector;

// Aloca memória para um vetor vazio com capacidade para 1 elemento.
// Caso não seja possível alocar, retorna NULL.
Vector* vector_create(void);

// Libera toda a memória que foi alocada dinamicamente:
// Primeiramente, checa se v não é nulo.
// Se v não for nulo, libera a memória do array 'data' 
// e do próprio struct vector.
// Retorna NULL.
Vector* vector_free(Vector *v);

// Ajusta a capacidade do vetor para que seja igual a new_capacity.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Se new_capacity == 0, então ele não faz nada e retorna ERROR_INVALID_ARGUMENT.
// Se não for possível alocar por qualquer outro motivo, deixa o vetor como está e 
// retorna ERROR_ALLOCATION.
// Caso tudo dê certo, retorna ERROR_OK.
// Note que o resize pode tanto diminuir quanto aumentar a capacidade do vector.
ErrorType vector_resize(Vector *v, size_t new_capacity);

// Insere um elemento ao final do vetor.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Antes de inserir, verifica se o vetor está cheio. 
// Se estiver cheio, ele dobra a capacidade do vetor e, 
// então, insere o elemento e retorna ERROR_OK.
ErrorType vector_push_back(Vector *v, int value);

// Remove um elemento do final da lista.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Se a lista estiver vazia, não faz nada e retorna ERROR_EMPTY.
// Se der certo remover, então e retorna ERROR_OK.
ErrorType vector_pop_back(Vector *v);

// Devolve true se e somente se o vetor estiver vazio.
// O ponteiro para o vetor deve ser diferente de NULL;
// caso contrário, o comportamento será indeterminado.
bool vector_empty(const Vector *v);

// Devolve o número de elementos no vetor.
// O ponteiro para o vetor deve ser diferente de NULL; 
// caso contrário, o comportamento será indeterminado.
size_t vector_size(const Vector *v);

// Devolve a capacidade atual do vetor.
// O ponteiro para o vetor deve ser diferente de NULL; 
// caso contrário, o comportamento será indeterminado.
size_t vector_capacity(const Vector *v);

// Recebe como entrada: um ponteiro para um vetor, 
// um índice e um ponteiro para uma variável externa. 
// Se os ponteiros forem nulos, então retorna ERROR_NULL_POINTER.
// Se o índice for inválido, retorna ERROR_OUT_OF_BOUNDS.
// Se tudo der certo, copia o valor do elemento na variável externa e retorna ERROR_OK.
ErrorType vector_get(const Vector *v, size_t index, int *out_value);

// Atualiza o valor do elemento que está no índice informado.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Se o índice for inválido, retorna ERROR_OUT_OF_BOUNDS.
// Se tudo der certo, atualiza o valor do elemento e retorna ERROR_OK.
ErrorType vector_set(Vector *v, size_t index, int value);

// Se o vetor for não vazio, essa função guarda o valor do primeiro elemento do vetor
// na variável apontada por 'out_value' e retorna ERROR_OK.
// Se o vetor estiver vazio, retorna ERROR_EMPTY.
// Se os ponteiros forem nulos, então retorna ERROR_NULL_POINTER.
ErrorType vector_front(const Vector *v, int *out_value);

// Se o vetor for não vazio, essa função guarda o valor do último elemento do vetor
// na variável apontada por 'out_value' e retorna ERROR_OK.
// Se o vetor estiver vazio, retorna ERROR_EMPTY.
// Se os ponteiros forem nulos, então retorna ERROR_NULL_POINTER.
ErrorType vector_back(const Vector *v, int *out_value);

// Essa funcao remove todas as ocorrencias do elemento 'value' do vetor.
// Nao esqueca de decrementar o valor do atributo 'size' sempre que um value for removido da lista.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Se v->size == 0, então retorna ERROR_OK pois não há nada a remover.
// Complexidade: O(n) no pior caso.
ErrorType vector_remove_all(Vector *v, int value);

// Insere um elemento na lista, no índice que foi informado.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Se o índice for inválido, retorna ERROR_OUT_OF_BOUNDS.
// Se tudo der certo, insere o elemento e retorna ERROR_OK.
// Complexidade: O(n) no pior caso.
ErrorType vector_insert(Vector *v, size_t index, int value);

// Remove da lista o elemento que está no índice informado.
// Se o ponteiro for nulo, então retorna ERROR_NULL_POINTER.
// Se o índice for inválido, retorna ERROR_OUT_OF_BOUNDS.
// Se tudo der certo, remove o elemento e retorna ERROR_OK.
// Após remover, se (size < capacity/2) então diminui o tamanho do vetor.
// Complexidade: O(n) no pior caso.
ErrorType vector_erase(Vector *v, size_t index);

// Copia todo o conteúdo do vetor source no vetor destiny.
// Se pelo menos um dos ponteiros for nulo, não faz nada e retorna ERROR_NULL_POINTER.
// Se o vetor destiny for menor que o vetor source, a função deve fazer os ajustes 
// necessários para que a cópia possa ser realizada. 
// Não esqueça de desalocar memória se for necessário. 
// Se houver algum erro de alocação de memória, retornar ERROR_ALLOCATION.
// Se a cópia for bem sucedida, então retornar ERROR_OK.
// Ao final desta função, os dois vetores devem ter o mesmo conteúdo e mesmo tamanho.
ErrorType vector_copy(Vector *source, Vector *destiny);

#endif