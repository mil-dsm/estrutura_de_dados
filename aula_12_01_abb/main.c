#include <stdio.h>
#include <time.h>
#include <stdilib.h>
#include "ABB.h"

int main() {
    srand(time(NULL));

    NoArv* raiz = arv_cria_vazia();

    for(int i = 1; i <= 10; i++) {
        raiz = abb_insere(raiz, rand);
    }

    abb_mostrar(raiz);

    return 0;
}