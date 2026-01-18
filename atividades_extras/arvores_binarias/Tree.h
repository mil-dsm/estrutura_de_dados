/**
 * @file Tree.h
 * @author milenadsmesquita@gmail.com
 * @brief TAD de árvore binária
 * @version 0.1
 * @date 2026-01-14
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef BTREE
#define BTREE

typedef struct arv NoArv;

/* Slides */

// Cria uma árvore vazia
NoArv* arv_cria_vazia(void);

// Cria árvore a partir de duas subárvores
NoArv* arv_cria(int value, NoNoArv* sae, NoNoArv* sad);

// Verifica se a árvore é vazia
bool arv_vazia(NoArv* raiz);

// Imprime valores da árvore
void arv_print(NoArv* raiz);

// Imprime valores da árvore de forma iterativa
void arv_print_iterativa(NoArv* raiz);

// Libera nós da árvore
NoArv* arv_free(NoArv* raiz);

// Verifica a existência de um valor entre os nós da árvore
bool arv_pertence(NoArv* raiz, int value);

// Imprime os valores de uma árvore em percurso de ordem simétrica
void arv_print_os(NoArv* raiz);

// Imprime os valores de uma árvore em percurso de pós-órdem
void arv_print_po(NoArv* raiz);

// Coloca os valores de uma árvore em percurso por largura em uma fila
void arv_largura(NoArv *raiz, Queue *q);

// TODO: REVISAR
// Cria uma string serial da arvore binaria
void arv_serializar(NoArv* r, char *str);

// TODO: REVISAR
// Cria uma arvore binaria a partir duma string serial valida
NoArv* arv_deserializar(char *str, int *idx);

// TODO: REVISAR
// Calula o número de nós de uma árvore
int bt_size(NoArv *raiz);

// TODO: REVISAR
// Calcula a altura da árvore
int bt_height(NoArv* raiz);

// TODO: REVISAR
// Suponha agora que todo nó da árvore tem um campo adicional code, do tipo string, 
// capaz de armazenar uma cadeia de caracteres de tamanho variável.
// Essa função reencha o campo code de cada nó com o código do nó. Se dor para esquerda,
// o código é 0, e se for pra direita, o código é 1.
void bt_code(NoArv *raiz, char *code);

#endif