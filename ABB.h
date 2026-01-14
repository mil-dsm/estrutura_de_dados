#ifndef ABB_H
#define ABB_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct no_arv {
    int chave;
    struct no_arv *esq;
    struct no_arv *dir;
};

typedef struct no_arv NoArv;

// Cria uma arvore a partir de duas sub-arvores distintas
NoArv* abb_cria(NoArv *sae, NoArv *sad);

// Essa função recebe um ponteiro para um nó e um valor,
// e percorre a árvore enraizada em busca desse valor.
// Se o valor estiver na árvore retorna o nó encontrado.
// Caso contrário retorna nulo.
NoArv* abb_busca(NoArv *node, int valor);

NoArv* abb_busca_iterativa(NoArv *node, int valor);

//
NoArv* abb_insere(NoArv *node, int valor);

// Fazer iteratica (PROVA)
NoArv* abb_insere_iterativa(NoArv *node, int valor);

// Retorna true se e somente a arvore for vazia
bool abb_vazia(NoArv *node);

// Imprime as chaves de todos os nos da arvore
void abb_imprime(NoArv *node);

// Libera todos os nos da arvore
NoArv* abb_libera(NoArv *node);

// Retorna um ponteiro para o nó com valor mínimo, ou nulo se não existir
NoArv* abb_minimo(NoArv *node);

NoArv* abb_minimo_iterativo(NoArv *node);

// Retorna um ponteiro para o nó com valor máximo, ou nulo se não existir
NoArv* abb_maximo(NoArv *node);

NoArv* abb_maximo_iterativo(NoArv *node);

// Remove o nó com o valor fornecido
NoArv* abb_remove(NoArv *node, int valor);

// mostra a arvore
void abb_mostrar(NoArv *node);

#endif