// NAO MEXA NESSE ARQUIVO, ELE ESTA PRONTO PARA USO
#include <stdio.h>
#include <string.h>
#include "Tree.h"

int main()
{
	char line[2000];
    fgets(line, 2000, stdin);
    line[strcspn(line, "\n")] = '\0';
    No *raiz = arv_deserializar(line);
    printf("%d %d\n", arv_altura(raiz), arv_tamanho(raiz));
    return 0;
}