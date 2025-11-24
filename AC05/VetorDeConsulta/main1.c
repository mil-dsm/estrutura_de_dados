/*Há um vetor de strings de entrada e um vetor de strings de consulta. Para cada sequência de consultas, determine quantas vezes ela ocorre na lista de sequências de entrada.

Por exemplo, dado o vetor entrada = [‘ab’,‘ab’,‘abc’ ] e o vetor consultas = [‘ab’,‘abc’,‘bc’], encontramos duas instâncias de ‘ab’ , uma instância de ‘abc’ e zero instâncias de ‘bc’. Para cada consulta, adicionamos um elemento ao nosso vetor de retorno.

Descrição da função

Implemente a função matchingStrings. A função deve retornar um vetor de números inteiros representando a frequência de ocorrência de cada sequência de consultas.

matchingStrings possui os seguintes parâmetros:

strings - um vetor de strings para pesquisar
consultas - um vetor de cadeias de consulta
Formato de entrada

Linha 1: tamanho do vetor de consultas
Linha 2: vetor de consultas
Linha 3: tamanho do vetor de buscas
Linha 4: vetor de buscas
Formato de saída

Retorne um vetor inteiro dos resultados de todas as consultas em ordem.

Entrada de amostra

>>>>>>>> 01
4 
aba baba aba xzxb 
3
aba xzxb ab
========
2 1 0
<<<<<<<<

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char lista[1000][50];
    int tamanho;
} ListaStrings;

int* matchingStrings(ListaStrings, ListaStrings);

int main() {
    ListaStrings consultas, strings;
    scanf("%d", &consultas.tamanho);
    for(int i = 0; i < consultas.tamanho; i++) {
        scanf("%s", consultas.lista[i]);
    }
    scanf("%d", &strings.tamanho);
    for(int i = 0; i < strings.tamanho; i++) {
        scanf("%s", strings.lista[i]);
    }
    
    // Vetor que armazena os resultados das ocorrencias e comparacoes
    int *resultados = matchingStrings(consultas, strings);

    for(int i = 0; i < strings.tamanho; i++) {
        printf("%d", resultados[i]);
        printf((i < strings.tamanho - 1) ? " " : "\n");
    }

    free(resultados);
    
    return 0;
}

// Compara cada string de s2 com todas as strings de s1
// s1: vetor com n1 strings
// s2: vetor com n2 strings
int* matchingStrings(ListaStrings consultas, ListaStrings strings) {
    int *resultados = malloc(strings.tamanho * sizeof(int));
    for(int i = 0; i < strings.tamanho; i++) {
        resultados[i] = 0;
        for(int j = 0; j < consultas.tamanho; j++) {
            if(strcmp(strings.lista[i], consultas.lista[j]) == 0) {
                resultados[i]++;
            }
        }
    }

    return resultados;
}