#include <stdio.h>
#include "Tree.h"

int main(void) {
    No *a = arv_cria(12, 
        arv_cria(23, 
            arv_cria_vazia(), 
            arv_cria(45, arv_cria_vazia(), arv_cria_vazia())
            ),
            arv_cria(77, 
            arv_cria(99, arv_cria_vazia(), arv_cria_vazia()),
            arv_cria(88, arv_cria_vazia(), arv_cria_vazia())
        
        )
    );
    arv_print(a);
    printf("\n");
    arv_free(a);
    return 0;
}