#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node Node;

// Códigos de erro retornados pelas funções do TAD DoublyLinkedList.
typedef enum { ERROR_OK, ERROR_NULL_POINTER, ERROR_ALLOCATION } ErrorType;

// Cria uma lista vazia
Node* dList_create(void);

// Destroi uma lista, liberando a memória alocada previamente
void dList_free_all(Node *head);

// Insere um elemento ao final da lista
Node* dList_push_back(Node *head, int val);

// Insere um elemento ao inicio da lista
Node* dList_push_front(Node *head, int val);

// Inserir um elemento em um indice especificado. Lembre que numa lista de tamanhon os indice vao de 0 a n − 1.
Node* dList_insert(Node *head, int val, int idx);

// Remove um elemento do final da lista
Node* dList_pop_back(Node *head);

// Remove um elemento do inicio da lista
Node* dList_pop_front(Node *head);

// Retorna o tamanho da lista
int dList_size(Node *head);

// Retorna se a lista esta vazia
bool dList_is_empty(Node *head);

// Imprime os elementos da lista
void dList_print(Node *head);

// Remove todos os elementos da lista e deixa apenas o no sentinela. Ou seja, deixar a lista vazia
Node* dList_remove_all(Node *head);

// Remove um elemento que esteja num indice especificado. Lembre que numa lista de tamanho n os indices vao de 0 a n −1
Node* dList_remove_idx(Node *head, int idx);

// Removee da lista todas as ocorrencias de elemento com valor k; esse k eh passado para a funcao como argumento
Node* dList_remove_value(Node *head, int k);

// Reverte a lista. Fazer em tempo O(n) e sem usar memoria adicional
Node* dList_reverse(Node *head);

// Concatena duas listas. Se a lista 1 for vazia, retorne a lista 2
Node* dList_concatena(Node *p1, Node *p2);

// Clonar uma lista. Um clone de uma lista eh uma copia da lista
Node* dList_clone(Node *p1);

// Retornar se duas listas sao iguais
bool dList_are_equal(Node *p1, Node *p2);

// Retornar se duas listas sao diferentes
bool dList_are_dif(Node *p1, Node *p2);

// Dadas duas listas ordenadas ℓ1 e ℓ2, intercalar as duas listas gerando uma listaℓ3 ordenada. A lista ℓ3 eh formada
// pelos nos das listas ℓ1 e ℓ2. Nao aloque nos adicionais. Ao final desta operacao, as listas ℓ1 e ℓ2 ficam vazias
Node *dList_intercala(Node *p1, Node *p2);

// Esta função recebe como entrada uma lista simplesmente encadeada e 
// executa uma varredura na lista, comparando nós consecutivos dois-a-dois e movendo o maior 
// elemento que ela encontra para a direita na lista. 
// A função retorna como resultado a lista modificada.
// Por exemplo, se passarmos como entrada a lista [9,8,7,6,5] então a lista resultante deve ser [8,7,6,5,9].
// Veja que a função foi comparando os elementos dois-a-dois da esquerda para a direita, movendo o maior para a 
// direita, nesse caso o número 9 que é o maior de todos na varredura acabou sendo movido para o final da lista.
// Mais um exemplo: se passarmos a lista [6,5,4,3,8,9] como entrada, então a lista resultante deve ser [5,4,3,6,8,9].
Node* dList_varredura(Node *p);

// Esta função usa a função list_varredura descrita acima para implementar 
// o algoritmo de ordenação por bolha (bubblesort) numa lista encadeada.
// Complexidade: O(n^2).
// Não é preciso alocar memória nessa função.
Node* dList_bubblesort(Node *p);

// Implementar o algoritmo InsertionSort para listas
Node *dList_insertionsort(Node *p);

// Implementar o algoritmo SelectionSort para listas
Node *dList_selectionsort(Node *p);

#endif