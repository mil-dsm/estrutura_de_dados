// NAO MEXA NESSE ARQUIVO, ELE ESTA PRONTO PARA USO
#include <stdio.h>
#include <string.h>
#include "Tree.h"

int main()
{
    char line[2000];
    fgets(line, 2000, stdin);
    line[strcspn(line, "\n")] = '\0';

    int value;
    scanf("%d", &value);

    No *raiz = arv_deserializar(line);

    printf("%d\n", arv_conta_folhas(raiz));

    raiz = arv_deleta_folhas(raiz);

    arv_preordem(raiz);
    printf("\n");

    arv_emordem(raiz);
    printf("\n");

    raiz = arv_deleta_folhas_com_valor(value, raiz);
    arv_preordem(raiz);
    printf("\n");
    arv_emordem(raiz);

	return 0;
}