#ifndef BINARY_TREE
#define BINARY_TREE
#include <stdbool.h>

typedef enum { ERROR_OK, ERROR_ALLOCATION, ERROR_NULL_POINTER } ErrorType;

typedef struct arv_node Node;

// Cria uma árvore vazia
Node* arv_cria_vazia(void);

// Cria uma árvore a partir de duas sub-arvores distintas
Node* arv_cria(int valor, Node *sae, Node *sad);

// Retorna true se e somente se a árvore for vazia
bool arv_vazia(Node *r);

// Imprime as keys de todos os nós da árvore
void arv_print(Node *r);

// Libera todos os nós das árvores
Node* arv_free(Node *r);

// Verifica se um valor esta contido na árvore
bool arv_is_contained(Node *r, int valor);

// Percurso pré-ordem
void arv_preordem(Node *r);

// Percurso pós-ordem
void arv_posordem(Node *r);

// Percuso ordem simétrica
void arv_ordemsimetrica(Node *r);

// Cria uma string serial da árvore binária (pré-ordem)
void arv_serializar(Node *r, char *str);

// Cria uma árvore binária a partir de uma string serial válida (pré-ordem)
Node* arv_descerializar(char *str, int *idx);

// Cria uma string serial da árvore binária (pós-ordem)
void arv_serializar_po(Node *r, char *str);

// Cria uma árvore binária a partir de uma string serial válida (pós-ordem)
void arv_descerializar_po(Node *r, char *str);

// Cria uma string serial da árvore binária (ordem simétrica)
void arv_serializar_os(Node *r, char *str);

// Cria uma árvore binária a partir de uma string serial válida (ordem simétrica)
void arv_descerializar_os(Node *r, char *str);

// Percurso em largura
Queue* arv_perc_em_larg(Node *r);

// Número de nós de uma árvove
int bt_size(Node *node);

// Altura de uuma árvore
int bt_height(Node *node);

#endif