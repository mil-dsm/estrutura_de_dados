#include "Tree.h"

struct arv_no {
    int chave;
    struct arv_no *esq;
    struct arv_no *dir;
};

// Cria uma arvore vazia
No *arv_cria_vazia(void) {
    return NULL;
}

// Cria uma arvore a partir de duas sub-arvores distintas
No *arv_cria(int valor, No *sae, No *sad) {
    No *raiz = (No*) malloc(sizeof(No));
    raiz->chave = valor;
    raiz->esq = sae;
    raiz->dir = sad;
    return raiz;
}

// Retorna true se e somente a arvore for vazia
bool arv_vazia(No *r) {
    return r == NULL;
}

// Imprime as chaves de todos os nos da arvore
void arv_imprime(No *r) {
    printf("(");
    if(!arv_vazia(r)) {
        printf("%d ", r->chave);
        arv_imprime(r->esq);
        arv_imprime(r->dir);
    }
    printf(")");
}

// Libera todos os nos da arvore
No* arv_libera(No *r) {
    if(!arv_vazia(r)) {
        arv_libera(r->esq);
        arv_libera(r->dir);
        free(r);
    }
    return NULL;
}

// Verifica se um valor esta contido na arvore
bool arv_pertence(No *r, int valor) {
    if(arv_vazia(r))
        return false;
    else 
        return r->chave == valor || 
               arv_pertence(r->esq, valor) || 
               arv_pertence(r->dir, valor);
}

// Percurso em pre-ordem
void arv_preordem(No *r) {
    if(!arv_vazia(r)) {
        printf("%d ", r->chave);
        arv_preordem(r->esq);
        arv_preordem(r->dir);
    }
}

// Percurso em-ordem
void arv_emordem(No *r) {
    if(!arv_vazia(r)) {
        arv_emordem(r->esq);
        printf("%d ", r->chave);
        arv_emordem(r->dir);
    }
}

// Percurso pos-ordem
void arv_posordem(No *r) {
    if(!arv_vazia(r)) {
        arv_posordem(r->esq);
        arv_posordem(r->dir);
        printf("%d ", r->chave);
    }
}

// Cria uma string serial da arvore binaria
void arv_serializar(No *r, char *str) {
    if(arv_vazia(r)) {
        int n = strlen(str);
        str[n] = ' ';
        str[n+1] = '#';
        str[n+2] = '\0';
    } else {
        char numero[25] = " ";
        snprintf(numero + 1, sizeof(numero)-strlen(numero), 
                 "%d", r->chave);
        strcat(str, numero);
        arv_serializar(r->esq, str);
        arv_serializar(r->dir, str);
    }
}

// Cria uma arvore binaria a partir duma string serial valida
No* _deserializar(char *str, int *idx) {
    if(str[*idx] == '#') {
        *idx = *idx + 2;
        return NULL;
    } else {
        char token[50];
        int i = 0;
        while(str[*idx] != ' ' && str[*idx] != '\0') {
            token[i++] = str[(*idx)++];
        }
        *idx = *idx + 1;
        token[i] = '\0';

        No *raiz = (No*) malloc(sizeof(No));
        raiz->chave = (int) atoi(token);
        raiz->esq = _deserializar(str, idx);
        raiz->dir = _deserializar(str, idx);
        return raiz;
    }
}

No* arv_deserializar(char *str) {
    int idx = 0;
    return _deserializar(str, &idx);
}

void _mostrar(No *node, const char *heranca) {
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


void arv_mostrar(No *node) {
    _mostrar(node, "");
}


// função que conta o número de folhas de uma árvore binária.
int arv_conta_folhas(No *raiz) {
    if(raiz == NULL) {
        return 0;
    }
    if(raiz->esq == NULL && raiz->dir == NULL) {
        return 1;
    }
    return arv_conta_folhas(raiz->esq) + arv_conta_folhas(raiz->dir);
}

// função que exclua todas as folhas de uma árvore binária.
No *arv_deleta_folhas(No *raiz) {
    if(raiz == NULL) {
        return NULL;
    }
    if(raiz->esq == NULL && raiz->dir == NULL) {
        free(raiz);
        return NULL;
    }
    raiz->esq = arv_deleta_folhas(raiz->esq);
    raiz->dir = arv_deleta_folhas(raiz->dir);
    return raiz;
}

//função recursiva que apaga todas as folhas de uma árvore que tenham a chave igual a um valor dado.
No* arv_deleta_folhas_com_valor(int chave, No *raiz) {
    if(raiz == NULL) {
        return NULL;
    }
    if(raiz->esq == NULL && raiz->dir == NULL && raiz->chave == chave) {
        free(raiz);
        return NULL;
    }
    raiz->esq = arv_deleta_folhas_com_valor(chave, raiz->esq);
    raiz->dir = arv_deleta_folhas_com_valor(chave, raiz->dir);
    return raiz;
}