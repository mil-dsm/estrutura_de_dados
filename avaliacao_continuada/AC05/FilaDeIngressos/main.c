/*Com a proximidade da Copa do Mundo, o fluxo de pessoas nas filas para compra de ingressos aumentou consideravelmente. Como as filas estão cada vez maiores, pessoas menos pacientes tendem a desistir da compra de ingressos e acabam deixando as filas, liberando assim vaga para outras pessoas. Quando uma pessoa deixa a fila, todas as pessoas que estavam atrás dela dão um passo a frente, sendo assim nunca existe um espaço vago entre duas pessoas. A fila inicialmente contém N pessoas, cada uma com um identificador diferente.

Joãozinho sabe o estado inicial dela e os identificadores em ordem das pessoas que deixaram a fila. Sabendo que após o estado inicial nenhuma pessoa entrou mais na fila, Joãozinho deseja saber o estado final da fila.

Entrada

A primeira linha contém um inteiro N representando a quantidade de pessoas inicialmente na fila.
A segunda linha contém N inteiros representando os identificadores das pessoas na fila. O primeiro identificador corresponde ao identificador da primeira pessoa na fila. É garantido que duas pessoas diferentes não possuem o mesmo identificador.
A terceira linha contém um inteiro M representando a quantidade de pessoas que deixaram a fila.
A quarta linha contém M inteiros representando os identificadores das pessoas que deixaram a fila, na ordem em que elas saíram. É garantido que um mesmo identificador não aparece duas vezes nessa lista.
Saída

Seu programa deve imprimir uma linha contedo N-M inteiros com os identificadores das pessoas que permaneceram na fila, em ordem de chegada.

Entrada de amostra
>>>>>>>> 01
4
10 9 6 3
1
3
========
10 9 6 
<<<<<<<<

>>>>>>>> 02
8
5 100 9 81 70 33 2 1000
3
9 33 5
========
100 81 70 2 1000 
<<<<<<<<*/

/*Funções usadas
Vector* vector_create(void);
ErrorType vector_resize(Vector *v, size_t new_capacity);
ErrorType vector_push_back(Vector *v, int value);
size_t vector_size(const Vector *v);
ErrorType vector_erase(Vector *v, size_t index);
ErrorType vector_get(const Vector *v, size_t index, int *out_value);
*/

#include <stdio.h>
#include "Vector.h"

int main() {
    size_t N, M;
    scanf("%zu", &N);
    Vector *v1 = vector_create();
    ErrorType err = vector_resize(v1, N);
    if(err != ERROR_OK) return 0;

    // Lê os M valores e insere cada um no final do vetor dinâmico v2.
    // A função vector_push_back insere no próximo índice livre,
    // aumentando o size do vetor a cada inserção.
    for(size_t i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        err = vector_push_back(v1, x);
        if(err != ERROR_OK) return 0;
    }

    scanf("%zu", &M);
    Vector *v2 = vector_create();
    err = vector_resize(v2, M);
    if(err != ERROR_OK) return 0;

    // Lê os M valores e insere cada um no final do vetor dinâmico v2.
    // A função vector_push_back insere no próximo índice livre,
    // aumentando o size do vetor a cada inserção.
    for(size_t i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        err = vector_push_back(v2, x);
        if(err != ERROR_OK) return 0;
    }
    
    // Laco para construir a fila formatada
    // Chama vector_get para o valor no indice atual do vetor de tamanho M e compara com o valor no indice atual
    // do vetor dinamico de tamanho N adquirido com outra chamada da funcao vector_get. Apos isso, os valores sao
    // comparados, e caso sejam iguais, o valor eh removido do vetor dinamico de tamanho N e este diminui seu size
    for(size_t i = 0; i < M; i++) {
        int valueM;
        err = vector_get(v2, i, &valueM);
        if(err != ERROR_OK) return 0;
        for(size_t j = 0; j < vector_size(v1); j++) {
            int valueN;
            err = vector_get(v1, j, &valueN);
            if(err != ERROR_OK) return 0;
            if(valueN == valueM) {
                err = vector_erase(v1, (size_t)j);
                if(err != ERROR_OK) return 0;
                j--;
            }
        }
    }

    // Laco para imprimir os valores da fila formatada
    for(size_t i = 0; i < vector_size(v1); i++) {
        int x;
        err = vector_get(v1, i, &x);
        if(err != ERROR_OK) return 0;
        printf("%d ", x);
    }
    printf("\n");

    return 0;
}