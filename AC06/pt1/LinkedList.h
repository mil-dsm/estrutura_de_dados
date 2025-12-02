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

// Esta função concatena duas listas simplemente encadeadas passadas como parâmetro e 
// retorna a lista resultante já concatenada. 
// Exemplo se p1 = [1,2,3,4] e p2 = [44,66,77], então a lista resultante deve ser [1,2,3,4,44,66,77].
// Se a lista p1 for vazia, deve retornar p2.
Node* list_concatenar(Node *p1, Node *p2);

// Esta função recebe como entrada uma lista e faz uma 
// cópia profunda (deep copy) da lista, i.e., a lista 
// resultante contém os mesmos elementos que a original só que 
// elas não compartilham nós. As duas listas são independentes.
// Ou seja, essa função cria um clone da lista original e retorna o clone.
Node* list_clone(Node *p);


// Esta função remove todas as ocorrencias do valor 'val' da sua lista.
// Por exemplo, se você tiver a lista [4,1,2,4,4,3,4,4] e chamar
// essa função com o valor 4, a lista resultante sera [1,2,3].
// Não esqueça de liberar os nós que forem removidos.
// Antes de liberar o nó você deve imprimir "liberado: %d" e coloca o valor do nó liberado.
// Retorna a lista modificada. 
Node* list_remove_todos(Node *p, int val);


// Esta função retorna true se as duas listas são idênticas; ou 
// retorna false caso contrário. 
// Duas listas são idênticas se elas têm os mesmos elementos na mesma ordem. 
bool list_sao_iguais(Node* p1, Node *p2);


// Esta função retorna true se as duas listas são diferentes; ou 
// retorna false caso contrário. 
// Duas listas são diferentes se elas não são idênticas. 
bool list_sao_diferentes(Node* p1, Node *p2);

#endif