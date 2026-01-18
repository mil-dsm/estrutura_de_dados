#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ABB.h"

struct no_arv {
    int chave;
    struct no_arv *esq;
    struct no_arv *dir;
    struct no_arv *pai;
};

NoArv* abb_cria_vazia(void) {
    return NULL;
}

void abb_free(NoArv *node) {
    if(raiz == NULL) {
        return;
    }
    abb_free(raiz->esq);
    abb_free(raiz->dir);
    free(raiz);
    printf("Nó deletado: ", raiz->chave);
}
// Procura o valor passado e, se encontrar, retorna o nó,
// caso contrário, retorna NULL.
NoArv* abb_busca(NoArv *node, int valor) {
    if(raiz == NULL) {
        return;
    }
    if(raiz->chave == valor) {
        return raiz;
    }
    if(raiz->chave > valor) {
        return abb_busca(raiz->esq, valor);
    }
    if(raiz->chave < valor) {
        return abb_busca(raiz->dir, valor);
    }
    return raiz;
}

// Esta funcao insere um novo valor na arvore somente
// se a chave nao for repetida. Ela devolve um ponteiro
// para a raiz da nova arvore.
NoArv* abb_insere(NoArv *node, int valor) {
    if(raiz == NULL) {
        NoArv *novo = (NoArv*)malloc(sizeof(NoArv));
        novo->chave = valor;
        novo->esq = novo->dir = NULL;
    }
    if(raiz->chave == valor) {
        return raiz;
    }
    if(raiz->chave > valor) {
        raiz->esq = abb_inserir(raiz->esq, valor);
    }
    if(raiz->chave < valor) {
        raiz->dir = abb_busca(raiz->dir, valor);
    }
}

// Retorna um ponteiro para o no com valor minimo,
// ou nulo se nao existir (arvore vazia)
NoArv* abb_minimo(NoArv *node) {
    if(node == NULL) {
        return NULL;
    }
    if(node->esq == NULL) {
        return node;
    }
    return abb_minimo(node->esq);
}

// Retorna um ponteiro para o no com valor máximo,
// ou nulo se nao existir (arvore vazia)
NoArv* abb_maximo(NoArv *node) {
    if(node == NULL) {
        return NULL;
    }
    if(node->dir == NULL) {
        return node;
    }
    return abb_maximo(node->dir);
}

// Remove o no com o valor fornecido, se ele existir
NoArv* abb_remove(NoArv *node, int valor) {
    if(node == NULL) {
        return NULL;
    }
    if(node->chave == valor) {
        return abb_remove_raiz(node);
    }
    else if(node->chave > valor) {
        return abb_remove(node->esq, valor);
    }
    else if(node->chave < valor) {
        return abb_remove(node->dir, valor);
    }
    return node;
}

// Recebe um ponteiro para a raiz de uma arvore e
// remove a raiz, rearranjando a arvore de mode que ela
// continue sendo de busca. Devolve a raiz da nova arvore
NoArv* abb_remove_raiz(NoArv *node) {
    NoArv *raiz = node;
    if(node->dir == NULL) {
        raiz = node->esq;
    } else {
        NoArv *pai = node;
        raiz - node->dir;

        while(raiz->esq != NULL) {
        pai = raiz;
        raiz = raiz->esq;
    }
    pai->esq = raiz->dir;
    pai->dir = raiz->dir;
    }
}

// Suponha que todo nó da BST tenha agora um ponteiro para nó pai.
// Reimplemente as operações vistas nessa aula considerando este novo
// ponteiro.

void abb_free(NoArv *node) {
    if(node == NULL) {
        return;
    }
    abb_free(node->esq);
    abb_free(node->dir);
}

// Procura o valor passado e, se encontrar, retorna o nó,
// caso contrário, retorna NULL.
NoArv* abb_busca(NoArv *node, int valor) {
    if(node == NULL) {
        return NULL;
    }
    if(node->chave == valor) {
        return node;
    }
}

// Esta funcao insere um novo valor na arvore somente
// se a chave nao for repetida. Ela devolve um ponteiro
// para a raiz da nova arvore.
NoArv* abb_insere(NoArv *node, int valor);

// Retorna um ponteiro para o no com valor minimo,
// ou nulo se nao existir (arvore vazia)
NoArv* abb_minimo(NoArv *node);

// Retorna um ponteiro para o no com valor máximo,
// ou nulo se nao existir (arvore vazia)
NoArv* abb_maximo(NoArv *node);

/* Lista 06 */

// 1. Escreva uma função que decida se uma dada árvore binária é ou não de busca.
// Verificar, dentro de um intervalo de minimos de mínimos e máximos os valores
// de cada subárvore
bool eh_abb(NoArv *node, int min, int max) {
    if(node == NULL) {
        return true;
    }
    if(node->chave < min || node->chave > max) {
        return false;
    }
    return eh_abb(node->esq, min, node->chave) && eh_abb(node->dir, node->chave, max);
}

// 3. Escreva uma função que transforme um vetor ordenado em ordem crescente em uma
// árvore binária de busca balanceada.
// Método: divisão e conquista
NoArv* abb_constroi(int *v, int inicio, int fim) {
    if(inicio > fim) {
        return NULL;
    }
    int meio = (inicio + fim) / 2;
    NoArv *novo = (NoArv*)malloc(sizeof(NoArv));
    novo->chave = v[meio];
    novo->esq = abb_montar(v, inicio, meio-1);
    novo->dir = abb_montar(v, meio+1, fim);
    return novo;
}

// 4. Escreva uma função que transforme uma árvore de busca em um vetor crescente.
// Usando persurso de órsem simetruc
void abb_desconstroi(NoArv *node, int *v, int *idx) {
    if(node == NULL) {
        return;
    }
    abb_desconstroi(node->esq, v, idx);
    v[*idx] = node->chave;
    (*idx)++;
    abb_desconstroi(node->dir, v, idx);
}

// 8. [Percurso em ordem simétrica] Escreva um algoritmo iterativo que percorre
// todos os nós de uma árvore binária de busca em ordem simétrica (inorder traversal) e
// imprime na tela as chaves dos nós na ordem em que eles são visitados por esta busca.
void abb_print_io(NoArv *raiz) {
    if(raiz == NULL) {
        return;
    }
    Stack *p = stack_create();
    stack_push(p, raiz);
    while(!stack_empty(p)) {
        
    }
}

// 9. [Percurso em pré-ordem] Escreva um algoritmo iterativo que percorre todos os
// nós de uma árvore binária de busca em pré-ordem (preorder traversal) e imprime na
// tela as chaves dos nós na ordem em que eles n visitados por esta busca.