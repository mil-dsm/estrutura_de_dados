/*Uma rotação desloca os elementos do vetor em uma determinada direção. 
Uma rotação à direita equivale a pegar o último elemento e inserí-lo na primeira posição.

Implemente a operação de rotação. Observe que calculando as posições finais corretamente 
você fará uma única operação de transposição das posições do vetor.

Entrada
Linha 1: tamanho do vetor T e número de elementos rotacionados R
Linha 2: elementos do vetor
Saída
Vetor rotacionado
>>>>>>>>
5 0
1 2 3 4 5
========
[ 1 2 3 4 5 ]
<<<<<<<<

>>>>>>>>
5 1
1 2 3 4 5
========
[ 5 1 2 3 4 ]
<<<<<<<<

>>>>>>>>
5 4
1 2 3 4 5
========
[ 2 3 4 5 1 ]
<<<<<<<<

>>>>>>>>
5 9
1 2 3 4 5
========
[ 2 3 4 5 1 ]
<<<<<<<<*/

/*Funções usadas
Vector* vector_create(void);
ErrorType vector_push_back(Vector *v, int value);
ErrorType vector_resize(Vector *v, size_t new_capacity);
ErrorType vector_back(const Vector *v, int *out_value);
ErrorType vector_erase(Vector *v, size_t index);
ErrorType vector_insert(Vector *v, size_t index, int value);
*/

#include <stdio.h>
#include "Vector.h"

int main() {
    int T, R;
    size_t tam = 0;
    scanf("%d%d", &T, &R);
    // Criacao do vetor dinamico
    Vector *v = vector_create();
    vector_resize(v, T);
    // Laco que ocupa o vetor. Chama a funcao vector_push_back com parametros do Vector criado anteriormente e valor inteiro x inserido pelo usuario no input
    // Verifica se houve algum erro na chamada da funcao vector_push_back.
    for(int i = 0; i < T; i++) {
        int x;
        scanf("%d", &x);
        ErrorType err = vector_push_back(v, x);
        if(err != ERROR_OK) return 0;
    }

    // Laco de rotacao do vetor dinamico. Chama funcao vector_back e guarda o ultimo elemento do vetor e guarda em uma variavel de output x. 
    // Chama a funcao vector_erase e apaga o elemento da ultima posicao, diminuindo o tamanho atual do vetor dinamico.
    // Chama a funcao vector_insert, que dobra a capacidade do vetor dinamico e insere o elemento guardado na variavel de output x na primeira posicao do vetor.
    // A cada chamada de funcao, verifica se houve algum erro.
    for(int i = 0; i < R; i++) {
        int x;
        tam = vector_size(v);
        ErrorType err = vector_back(v, &x);
        if(err != ERROR_OK) return 0;
        err = vector_erase(v, tam-1);
        if(err != ERROR_OK) return 0;
        err = vector_insert(v, 0, x);
        if(err != ERROR_OK) return 0;
    }

    // Chama a funcao vector_get passando o vetor dinamico v e uma variavel de output x.
    // Caso a funcao retorne ERROR_OK, o valor eh enviado ao output do terminal no formato colcado.
    tam = vector_size(v);
    printf("[ ");
    for(size_t i = 0; i < tam; i++) {
        int x;
        ErrorType err = vector_get(v, i, &x);
        if(err != ERROR_OK) return 0;
        printf("%d ", x);
    }
    printf("]\n");
    return 0;
}