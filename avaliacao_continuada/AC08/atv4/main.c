// NAO MEXA NESSE ARQUIVO, ELE ESTA PRONTO PARA USO
#include <stdio.h>
#include <string.h>
#include "Tree.h"

int main()
{
    char line1[2000];
    fgets(line1, 2000, stdin);
    line1[strcspn(line1, "\n")] = '\0';

    char line2[2000];
    fgets(line2, 2000, stdin);
    line2[strcspn(line2, "\n")] = '\0';

    No *raiz1 = arv_deserializar(line1);
    No *raiz2 = arv_deserializar(line2);

    No *raiz3 = arv_clone(raiz1);

    if(arv_identical(raiz1, raiz3)) 
        printf("identica\n");
    else 
        printf("diferente\n");
    
    if(arv_identical(raiz2, raiz3)) 
        printf("identica\n");
    else 
        printf("diferente\n");

    if(arv_identical(raiz1, raiz2)) 
        printf("identica\n");
    else 
        printf("diferente\n");

	return 0;
}