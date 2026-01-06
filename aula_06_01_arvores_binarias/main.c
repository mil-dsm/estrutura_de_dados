#include <stdio.h>
#include "Tree.h"

int main() {
    // Cria uma árvore vazia
    NoArv *tree = arv_cria_vazia();

    // Forma 1 de criar árvore
    NoArv *v3 = arv_cria(3, NULL, NULL);
    NoArv *v7 = arv_cria(7, NULL, NULL);
    NoArv *v8 = arv_cria(8, NULL, NULL);
    NoArv *v5 = arv_cria(5, v7, v8);
    NoArv *v4 = arv_cria(4, v3, v5);

    // Forma 2 de criar árvore
    NoArv *raiz = arv_cria(4, 
        arv_cria(3, NULL, NULL), 
        arv_cria(5, 
            arv_cria(7, NULL, NULL), 
            arv_cria(8, NULL, NULL)));

    arv_imprime(raiz);
    printf("\n");
            
    printf("7 esta contido? %d\n", arv_pertence(raiz, 7));
    printf("33 esta contido? %d\n", arv_pertence(raiz, 33));

    arv_libera(raiz);
    return 0;
}