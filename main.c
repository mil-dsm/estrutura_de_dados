#include <stdio.h>
#include "Tree.h"

int main() {
    Arv* t = 
        arv_cria(1, arv_cria(2, arv_cria_vazia(), arv_cria(3, arv_cria_vazia(), arv_cria_vazia())
    ), 
        arv_cria(4, 
            arv_cria(5, arv_cria_vazia(), arv_cria_vazia()), 
            arv_cria(6 arv_cria_vazia(), arv_cria_vazia())
        )
    );
}