#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Tree.h"

struct no_arv {
    int chave;
    struct no_arv *esq;
    struct no_arv *dir;
};

// Cria uma arvore vazia
NoArv *arv_cria_vazia(void) {
    return NULL; // Definição de parvore vazia
}

// Cria uma arvore a partir de duas sub-arvores distintas
NoArv *arv_cria(int valor, NoArv *sae, NoArv *sad) {
    NoArv *root = (NoArv*)malloc(sizeof(NoArv));
    root->chave = valor;
    root->esq = sae;
    root->dir = sad;
    return root;
}

// Retorna true se e somente a arvore for vazia
bool arv_vazia(NoArv *r) {
    return r == NULL;
}

// Imprime as chaves de todos os nos da arvore
void arv_imprime(NoArv *r) {
    if(arv_vazia(r)) { // Caso base
        return;
    } else { // Caso geral
        printf("%d ", r->chave); // Imprime a chave da raiz
        arv_imprime(r->esq);     // Imprimie as chaves da sae
        arv_imprime(r->dir);     // Imprime as chave da sad
    }
}

// Libera todos os nos da arvore.
// Recebe como entrada a raíz de uma árvire e libera todos os nós dela.
// Após liberar todos os nós retorna NULL.
NoArv* arv_libera(NoArv *r) {
    if(arv_vazia(r)) { // Caso base
        return NULL;
    } else { // Caso geral
        r->esq = arv_libera(r->esq); // Libera a subárvore esquerda
        r->dir = arv_libera(r->dir); // Libera a subárvore direita
        printf("Liberou: %d\n", r->chave); // Debug
        free(r); // Libera o nó raiz
        return NULL;
    }
}

// Verifica se um valor esta contido na arvore
// Recebe como entrada a raíz da árvore e o vaor a ser pesquisado
// Retorna true se, somente se, o valor está na árvore
bool arv_pertence(NoArv *r, int valor) {
    if(arv_vazia(r)) { // Caso base
        return false;
    } else { // Caso geral
        return (r->chave == valor || 
            arv_pertence(r->esq, valor) || 
            arv_pertence(r->dir, valor));
    }
}

// Percurso em pre-ordem
void arv_preordem(NoArv *r) {
    if(arv_vazia(r)) { // Caso base
        return;
    } else { // Caso geral
        printf("%d ", r->chave);
        arv_preordem(r->esq);
        arv_preordem(r->dir);
    }
}

// Percurso em-ordem
void arv_emordem(NoArv *r) {
    if(arv_vazia(r)) { // Caso base
        return;
    } else { // Caso geral
        arv_preordem(r->esq);
        printf("%d ", r->chave);
        arv_preordem(r->dir);
    }
}

// Percurso pos-ordem
void arv_posordem(NoArv *r) {
    if(arv_vazia(r)) { // Caso base
        return;
    } else { // Caso geral
        arv_preordem(r->esq);
        arv_preordem(r->dir);
        printf("%d ", r->chave);
    }
}

// // Cria uma string serial da arvore binaria
// void arv_serializar(NoArv *r, char *str);

// // Cria uma arvore binaria a partir duma string serial valida
// NoArv* arv_deserializar(char *str, int *idx);