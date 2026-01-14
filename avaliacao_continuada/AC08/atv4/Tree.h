// NAO MEXA NESSE ARQUIVO, ELE ESTA PRONTO PARA USO
#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct arv_no No;

// Cria uma arvore vazia
No *arv_cria_vazia(void);
// Cria uma arvore a partir de duas sub-arvores distintas
No *arv_cria(int valor, No *sae, No *sad);
// Retorna true se e somente a arvore for vazia
bool arv_vazia(No *r);
// Imprime as chaves de todos os nos da arvore
void arv_imprime(No *r);
// Libera todos os nos da arvore
No* arv_libera(No *r);
// Verifica se um valor esta contido na arvore
bool arv_pertence(No *r, int valor);
// Percurso em pre-ordem
void arv_preordem(No *r);
// Percurso em-ordem
void arv_emordem(No *r);
// Percurso pos-ordem
void arv_posordem(No *r);
// Cria uma string serial da arvore binaria
void arv_serializar(No *r, char *str);
// Cria uma arvore binaria a partir duma string serial valida
No* arv_deserializar(char *str);
// mostra arvore em formato mais amigavel
void arv_mostrar(No *node);


// Função que cria uma cópia (um clone) de uma árvore binária.
No *arv_clone(No *raiz);

// Duas árvores binárias são ditas idênticas quando possuem os 
// mesmos dados e a disposição dos dados também é a mesma.
// Escreva uma função recursiva que recebe duas árvores binárias 
// como entrada e devolve true se elas forem idênticas; e false, caso contrário.
bool arv_identical(No *raiz1, No *raiz2);

#endif