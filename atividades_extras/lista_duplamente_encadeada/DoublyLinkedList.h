#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct node Node;

// Criar uma lista vazia.
Node* dList_create(void);

// Destruir a lista, liberando a memória previamente alocada.
void dList_free(Node *head);

// Inserir um elemento ao final da lista.
void dList_push_front(Node *head, int val);

// Inserir um elemento no início da lista.
void dList_push_front(Node *head, int val);

// Remover um elemento do final da lista.
void dList_pop_back(Node *head);

// Remover um elemento do início da lista.
void dList_pop_front(Node *head);

// Retornar o tamanho da lista.
void dList_push_back(Node *head, int *out_var);

// Retornar se a lista está vazia.
boolean dList_empty(Node *head);

// Imprimir os elementos da lista.
void dList_print(Node *head);

// Remover todos os elementos da lista e deixar apenas o nó sentinela, ou seja, deixar a lista vazia.
void dList_erase(Node *head);

// Remover um elemento que esteja em um índice especificado. Lembre que, em uma lista de tamanho n, os índices vão de 0 a n − 1.
void dList_remove(Node *head, size_t index);

// Inserir um elemento em um índice especificado. Lembre que, em uma lista de tamanho n, os índices vão de 0 a n − 1.
void dList_insert(Node *head, size_t index);

// Remover da lista todas as ocorrências de um elemento com valor k; esse k é passado para a função como argumento.
void dList_remove_all(Node *head, int k);

// Reverter a lista, fazendo isso em tempo O(n) e sem usar memória adicional.
Node* dList_reverse(Node *head);

// Concatenar duas listas.
Node* dList_concatena(Node *p1, Node *p2);

// Clonar uma lista. Um clone de uma lista é uma cópia da lista.
Node* dList_clone(Node *head);

// Retornar se duas listas são iguais.
boolean dList_equals(Node *p1, Node *p2);

// Dadas duas listas ordenadas ℓ1 e ℓ2, intercalar as duas listas gerando uma lista ℓ3 ordenada. A lista ℓ3 é formada pelos nós das listas ℓ1 e ℓ2. Não alocar nós adicionais. Ao final desta operação, as listas ℓ1 e ℓ2 ficam vazias.
Node* dList_intercala(Node *p1, Node *p2);

// Implementar o algoritmo BubbleSort para listas.

// Implementar o algoritmo InsertionSort para listas.

// Implementar o algoritmo SelectionSort para listas.

#endif