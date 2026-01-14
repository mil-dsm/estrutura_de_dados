#include "ABB.h"

// Cria uma arvore vazia
NoArv* abb_cria_vazia(void) {
    return NULL;
}

// Cria uma arvore a partir de duas sub-arvores distintas
// NoArv* abb_cria(NoArv *sae, NoArv *sad);

// Essa função recebe um ponteiro para um nó e um valor,
// e percorre a árvore enraizada em busca desse valor.
// Se o valor estiver na árvore retorna o nó encontrado.
// Caso contrário retorna nulo.
NoArv* abb_busca(NoArv *node, int valor) {
    if(node == NULL)
        return NULL;
    if(node->chave == valor)
        return node;
    if(node->chave < valor) {
        return abb_busca(node->dir, valor);
    }
    else
        return abb_busca(node->esq, valor);
}

NoArv* abb_busca_iterativa(NoArv *node, int valor) {
    while(node != NULL) {
        if(node->chave == valor)
            break;
        if(node->chave < valor)
            node = node->dir;
        else
            node = node->esq;
    }
    return node;
}

//
NoArv* abb_insere(NoArv *node, int valor) {
    // Caso de parada: node == nulo
    if(node == NULL) {
        node = (NoArv*)malloc(sizeof(NoArv));
        novo->chave = valor;
        novo->esq = novo->dir = NULL;
        return node;
    }
    // Caso geral: ainda não encontrei a posição de inserir
    if(node->valor == valor)
        return node;
    if(node->chave < valor)
        node->dir = abb_insere(node->dir, valor);
    else
        node->esq = abb_insere(node->esq, valor);
    return node;
    
}

// Fazer iteratica (PROVA)
NoArv* abb_insere_iterativa(NoArv *node, int valor) {
    NoArv *node_pai;
    while(node != NULL) {
        if(node )
    }
}

// Retorna true se e somente a arvore for vazia
bool abb_vazia(NoArv *node) {
    return node == NULL;
}

// Imprime as chaves de todos os nos da arvore
void abb_imprime(NoArv *node) {
    if(node == NULL)
        return;
}

// Libera todos os nos da arvore
NoArv* abb_libera(NoArv *node);

// Retorna um ponteiro para o nó com valor mínimo, ou nulo se não existir
NoArv* abb_minimo(NoArv *node) {
    if(node == NULL || node->esq == NULL)
        return node;
    else
        return node = node->esq;
        
}

NoArv* abb_minimo_iterativo(NoArv *node) {
    while(node != NULL && node->esq != NULL)
        node = node->esq;
    return node;
}

// Retorna um ponteiro para o nó com valor máximo, ou nulo se não existir
NoArv* abb_maximo(NoArv *node) {
    if(node == NULL || node->dir == NULL)
        return node;
    else
        return abb_maximo(node->dir);
}

NoArv* abb_maximo_iterativo(NoArv *node) {
    while(node != NULL && node->esq != NULL)
        node = node->esq;
    return node;
}

// Remove o nó com o valor fornecido
// (De acordo com o livro do Paulo)
NoArv* abb_remove(NoArv *node, int valor) {
    if(node == NULL) // Árvore vazia
        return NULL;
    if(valor == node_chave) // Achou o nó a ser removido
        return abb_remove_raiz(node);
    // Ainda não achamos o valor, mas vamos buscá-lo
    if(valor < node->chave)
        node->esq = abb_remove(node->esq, valor)
    else
        node->dir = abb_remove(node->dir, valor);
}

NoArv* abb_remove_raiz(NoArv *node) {
    NoArv *raiz;
    if(node->dir == NULL)
        raiz = node->esq;
    else {
        NoArv *pai = node;
        raiz = node->dir;
        while(raiz->esq != NULL) {
            pai = raiz;
            raiz = raiz->esq;
        }
        if(pai != node) {
            pai->esq = raiz->dir;
            raiz->dir = node->dir;
        }
        raiz->esq = node->esq;
    }
}

// -----------------------------------------------------
// Funcoes ja implementadas
// -----------------------------------------------------

void _mostrar(NoArv *node, const char *heranca) {
    /* se tem filhos, visita primeiro a direita */
    if (node != NULL && (node->esq != NULL || node->dir != NULL)) {
        char next[256];
        snprintf(next, sizeof(next), "%sr", heranca);
        _mostrar(node->dir, next);
    }

    /* imprime os "galhos" */
    int len = strlen(heranca);
    for (int i = 0; i < len - 1; i++) {
        if (heranca[i] != heranca[i + 1])
            printf("│   ");
        else
            printf("    ");
    }

    if (len > 0) {
        if (heranca[len - 1] == 'r')
            printf("┌───");
        else
            printf("└───");
    }

    /* nó nulo */
    if (node == NULL) {
        printf("#\n");
        return;
    }

    printf("%d\n", node->chave);

    /* visita a esquerda */
    if (node->esq != NULL || node->dir != NULL) {
        char next[256];
        snprintf(next, sizeof(next), "%sl", heranca);
        _mostrar(node->esq, next);
    }
}


void abb_mostrar(NoArv *node) {
    _mostrar(node, "");
}