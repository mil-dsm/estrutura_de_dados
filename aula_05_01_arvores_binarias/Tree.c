#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

struct arv_node {
    int key;
    int height;
    struct arv_node *esq;
    struct arv_node *dir;
};

// Cria uma árvore vazia
Node* arv_cria_vazia(void) {
    return NULL;
}

// Cria uma árvore a partir de duas sub-arvores distintas
Node* arv_cria(int valor, Node *sae, Node *sad) {
    Node *r = (Node*)malloc(sizeof(Node));
    if(r == NULL) {
        printf("fail: allocation error\n");
        exit(EXIT_FAILURE);
    }
    r->key = valor;
    r->esq = sae;
    r->dir = sad;
    return r;
}

// Retorna true se e somente se a árvore for vazia
bool arv_vazia(Node *r) {
    return (r == NULL);
}

// Imprime as keys de todos os nós da árvore
void arv_print(Node *r) {
    printf("( ");
    if(arv_vazia(r) == false) {
        printf("%d ", r->key);
        arv_print(r->esq);
        arv_print(r->dir);
    }
    printf(")");
}

// Libera todos os nós das árvores
Node* arv_free(Node *r) {
    if(arv_vazia(r) == false) {
        arv_free(r->esq);
        arv_free(r->dir);
        free(r);
    }
    return NULL;
}

// Verifica se um valor esta contido na árvore
bool arv_is_contained(Node *r, int valor) {
    if(arv_vazia(r) == true) {
        return false;
    }
    else {
        return r->key == valor || arv_is_contained(r->esq, valor) || arv_is_contained(r->dir, valor);
    }
}

// Percurso pré-ordem
void arv_preordem(Node *r) {
    if(arv_vazia(r) == false) {
        printf("%d ", r->key);
        arv_preordem(r->esq);
        arv_preordem(r->dir);        
    }
}

// Percurso pós-ordem
void arv_posordem(Node *r) {
    if(arv_vazia(r) == false) {
        arv_posordem(r->esq);
        arv_posordem(r->dir);
        printf("%d ", r->key);
    }
}

// Percuso ordem simétrica
void arv_ordemsimetrica(Node *r) {
    if(arv_vazia(r) == false) {
        arv_ordemsimetrica(r->esq);
        printf("%d ", r->key);
        arv_ordemsimetrica(r->dir);
    }
}

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