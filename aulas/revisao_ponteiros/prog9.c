#include <stdio.h>

int main(){
    int v[5] = {9, 7, 5, 3, 1};
    printf("v[0]: %d\n", v[0]);
    printf("Endereço do vetor: %p\n", &v[0]);
    printf("Vetor decai para um ponteiro con endereço: %p\n", v);
    for(int i=0; i<5; i++){
        printf("%d: %d\n", i, v[i]);
    }
    return 0;
}

int main(){
    int v[5] = {9, 7, 5, 3, 1};
    printf("%d\n", *v); // Fiferenciar um vetor retorna o primeiro elemento
    int *p = v; // Fazendo um ponteiro que aponta pro vetor, p acaba apontando para o primeiro elemento também
    printf("%d\n", *p);
    return 0;
}

int main(){
    int array[] = {1, 1, 2, 3, 5, 8, 13, 21};
}