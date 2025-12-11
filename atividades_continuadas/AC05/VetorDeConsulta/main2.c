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

void matchingStrings(char [][50], int, char [][50], int, int []);

int main() {
    int nConsultas;
    scanf("%d", &nConsultas);
    // Cria um vetor bidimensional de char: cada linha armazena uma string de até 50 caracteres
    char consultas[nConsultas][50];
    for(int i = 0; i < nConsultas; i++) {
        scanf("%s", consultas[i]);
    }
    int nStrings;
    scanf("%d", &nStrings);
    // Cria um vetor bidimensional de char: cada linha armazena uma string de até 50 caracteres
    char strings[nStrings][50];
    for(int i = 0; i < nStrings; i++) {
        scanf("%s", strings[i]);
    }
    
    // Vetor que armazena os resultados das ocorrencias e comparacoes
    int resultados[nStrings];
    matchingStrings(consultas, nConsultas, strings, nStrings, resultados);
    for(int i = 0; i < nStrings; i++) {
        printf("%d", resultados[i]);
        printf((i < nStrings - 1) ? " " : "\n");
    }
    
    return 0;
}

// Compara cada string de s2 com todas as strings de s1
// s1: vetor com n1 strings
// s2: vetor com n2 strings
// resultados[i]: quantidade de vezes que s2[i] aparece em s1
void matchingStrings(char s1[][50], int n1, char s2[][50], int n2, int resultados[]) {
    for(int i = 0; i < n2; i++) {
        int cont = 0;
        for(int j = 0; j < n1; j++) {
            if(strcmp(s2[i], s1[j]) == 0) {
                cont++;
            }
        }
        resultados[i] = cont;
        
    }
}