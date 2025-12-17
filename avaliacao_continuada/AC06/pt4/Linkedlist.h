// ESTE ARQUIVO JA ESTA PRONTO, NAO MEXA NELE
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node Node;

// Função que cria uma lista vazia
// sem nó sentinela
Node *list_create(void);

// Insere um valor no início da lista
// e retorna a lista modificada.
Node *list_push_front(Node *list, int value);

// Insere um valor ao final da lista
// e retorna a lista modificada.
Node *list_push_back(Node *list, int value);

// Função que recebe um ponteiro para a cabeça da lista e
// imprime o conteúdo dos elementos na tela.
// Formato: [ a1 a2 a3 ... an ]
void list_print(Node *list);

// Função que libera todos os nós 
// alocados dinamicamente
void list_free(Node *list);

// Função que imprime o tamanho da lista (número de nós)
size_t list_size(Node *list);

// Esta função recebe como entrada uma lista simplesmente encadeada e 
// executa uma varredura na lista, comparando nós consecutivos dois-a-dois e movendo o maior 
// elemento que ela encontra para a direita na lista. 
// A função retorna como resultado a lista modificada.
// Por exemplo, se passarmos como entrada a lista [9,8,7,6,5] então a lista resultante deve ser [8,7,6,5,9].
// Veja que a função foi comparando os elementos dois-a-dois da esquerda para a direita, movendo o maior para a 
// direita, nesse caso o número 9 que é o maior de todos na varredura acabou sendo movido para o final da lista.
// Mais um exemplo: se passarmos a lista [6,5,4,3,8,9] como entrada, então a lista resultante deve ser [5,4,3,6,8,9].
Node* list_varredura(Node *p);

// Esta função usa a função list_varredura descrita acima para implementar 
// o algoritmo de ordenação por bolha (bubblesort) numa lista encadeada.
// Complexidade: O(n^2).
// Não é preciso alocar memória nessa função.
Node* list_bubblesort(Node *p);

#endif