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

// Recebe como entrada um nó e devolve o valor dele.
int list_pega_valor(Node *p);

// Esta função troca o conteúdo das duas listas passadas como parâmetro.
void list_troca(Node **p1, Node **p2);

// Essa função recebe como entrada uma lista e 
// coloca os elementos pares no inı́cio, e os elementos ı́mpares no fim da lista.
// Retorna a lista modificada. Não é permitido usar arrays nem vetores dinâmicos.
// Só é permitido usar ponteiro auxiliar (uma quantidade constante deles).
// Deve-se fazer com complexidade linear O(n).
Node* list_separa_pares_impares(Node *p);

// Essa função recebe como entrada uma lista encadeada com um número ímpar de elementos e 
// Encontra o elemento central da lista e retorna um ponteiro para ele.
// Se a lista for vazia, retorna NULL.
// Por exemplo, se tivermos a lista [2,3,4,5,6], a função retorna um ponteiro para o 4.
Node* list_encontra_centro(Node *p);

#endif