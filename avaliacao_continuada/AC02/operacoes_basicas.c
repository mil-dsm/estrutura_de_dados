/*🧮 Operações Básicas em Vetores (Recursão em C)
Nesta atividade, você vai praticar o uso de recursão em linguagem C para manipular vetores de inteiros. O objetivo é implementar funções que executem operações básicas sobre os elementos do vetor sem utilizar laços de repetição (como for ou while), exceto no momento da leitura dos valores de entrada.

📥 Entrada
Uma sequência de números inteiros (contendo pelo menos um elemento).
Os elementos da sequência são fornecidos em uma única linha, separados por espaço.
📤 Saída
O programa deve imprimir as seguintes informações, cada uma em uma linha:

vet: o vetor original;
rvet: o vetor impresso ao contrário (sem alterá-lo);
sum: a soma de todos os elementos;
mult: o resultado da multiplicação de todos os elementos;
min: o menor elemento do vetor;
inv: o vetor efetivamente invertido, após ser modificado.
Importante: todas as funções devem ser implementadas de forma recursiva.

💡 Exemplo de execução
Entrada:
1 2 3 4

Saída:
vet : [ 1 2 3 4 ]
rvet: [ 4 3 2 1 ]
sum : 10
mult: 24
min : 1
inv : [ 4 3 2 1 ]
📚 Dicas de Implementação
Use uma função recursiva para imprimir o vetor em ordem e outra para imprimir ao contrário.
Crie funções recursivas para somar, multiplicar e encontrar o menor elemento.
Para inverter o vetor (inv), troque os elementos recursivamente (por exemplo, o primeiro com o último, o segundo com o penúltimo, etc.).
🧩 Testes de Exemplo
>>>>>>>> 01
4
========
vet : [ 4 ]
rvet: [ 4 ]
sum : 4
mult: 4
min : 4
inv : [ 4 ]
<<<<<<<<

>>>>>>>> 02
3 4 2
========
vet : [ 3 4 2 ]
rvet: [ 2 4 3 ]
sum : 9
mult: 24
min : 2
inv : [ 2 4 3 ]
<<<<<<<<

>>>>>>>> 03
1 2 3 4 0
========
vet : [ 1 2 3 4 0 ]
rvet: [ 0 4 3 2 1 ]
sum : 10
mult: 0
min : 0
inv : [ 0 4 3 2 1 ]
<<<<<<<<
🧠 Observação
Lembre-se: o uso de laços é permitido somente para a leitura do vetor. Todas as demais operações devem ser realizadas de forma recursiva.*/

/*
RASCUNHO - Função para ler o vetor de inteiros.
// Entrada: vetor 'v' e índice atual 'i'.
// Saída: void (vetor preenchido).
int lerVet(int v[], int i){
    char c;
    scanf("%c", &c);
    if(c == '\n'){
        return i;
    }
    if(c >= '0' && c <= '9'){
        v[i] = c - '0';
        return lerVet(v, i+1);
    }
    else{
        return lerVet(v, i);
    }
}
*/

#include <stdio.h>
#include <string.h>

// Protótipo das funções.
void imprimirVet(int [], int, int);
void vet(int [], int, int);
void rvet(int [], int, int);
int sum(int [], int, int);
int mult(int [], int, int);
int min(int [], int, int, int);
void inv(int [], int, int);

int main() {
    char s[51];
    int v[50], tam = 0, num = 0, flag = 0;
    scanf("%[^\n]", s);
    for(int i=0; s[i]!='\n' && s[i]!='\0'; i++){
        if(s[i] == '-'){
            flag = -1;
        } 
        else if(s[i]>='0' && s[i]<='9'){
            num = num * 10 + (s[i] - '0');
            if(flag == 0){
                flag = 1;
            }
        } 
        else if(s[i] == ' '){
            if(flag != 0){
                v[tam] = num * flag;
                tam++;
                num = 0;
                flag = 0;
            }
        }
    }
    if (flag != 0){
        v[tam] = num * flag;
        tam++;
    }
    printf("vet : ");
    vet(v, tam, 0);
    printf("rvet: ");
    rvet(v, tam, tam-1);
    printf("sum : %d\n", sum(v, tam, 0));
    printf("mult: %d\n", mult(v, tam, 0));
    printf("min : %d\n", min(v, tam, 1, 0));
    printf("inv : ");
    inv(v, 0, tam-1);
    imprimirVet(v, tam, 0);
}

// Função para imprimir o vetor.
// Entrada: vetor 'v', tamanho 'n' do vetor, posição atual 'i'.
// Saída: void (vetor impresso).
// Caso base: se i == n, retornar; se i == 0, começar a impressão.
// Caso geral: imprimir o elemento do vetor na posição atual.
void imprimirVet(int v[], int n, int i){
    if(i == 0){
        printf("[ ");
    }
    printf("%d ", v[i]);
    if(i == n-1){
        printf("]\n");
        return;
    }
    imprimirVet(v, n, i+1);
}

// Função para imprimir o vetor original.
// Entrada: vetor 'v', tamanho 'n' e índice atual 'idx'.
// Saída: void (vetor original).
void vet(int v[], int n, int idx) {
    if(idx == 0) {
        printf("[ ");
    }
    if(idx == n) {
        printf("]\n");
        return;
    }
    printf("%d ", v[idx]);
    vet(v, n, idx + 1);
}

// Função para imprimir o vetor invertido.
// Entrada: vetor 'v', tamanho 'n' e índice do último elemento 'idx'.
// Saída: void (vetor invertido).
void rvet(int v[], int n, int idx) {
    if(idx == n-1){
        printf("[ ");
    }
    printf("%d ", v[idx]);
    if(idx == 0){
        printf("]\n");
        return;
    }
    rvet(v, n, idx-1);
}

// Função da soma de todos os termos do vetor.
// Entrada: vetor 'v', tamanho 'n', índice atual 'idx'.
// Se o tamanho for igual a 0, retorne 0. Caso contrário, retorne a função sum().
int sum(int v[], int n, int idx){
    if(idx == n || n == 0){
        return 0;
    }
    return v[idx] + sum(v, n, idx+1);
}

// Função de multiplicação de todos os termos do vetor.
// Entrada: vetor 'v', tamanho 'n', índice atual 'idx'.
// Se o tamanho for igual a 0, retorne 0. Caso contrário, retorne a função mult().
int mult(int v[], int n, int idx){
    if(n == 0 || idx == n){
        return 1;
    }
    return v[idx] * mult(v, n, idx+1);
}

// Função para encontrar o menor elemento do vetor.
// Entrada: vetor 'v', tamanho 'n', índice atual 'idx' e menor valor atual 'min'.
// Saída: menor elemento do vetor 'v'.
// Se o vetor tiver tamanho igual a 1, retorne o elemento no índice 0.
// Se idx apontar para o índice 0, min é igual a idx.
// Se o vetor tiver tamanho maior que 1, retorne a função min().
int min(int v[], int n, int idx, int idxMin){
    if(n == 0){
        return 0;
    }
    if(idx == n){
        return v[idxMin];
    }
    if(v[idx] < v[idxMin]){
        idxMin = idx;
    }
    return min(v, n, idx+1, idxMin);
}

// Função de inversão do vetor efetivamente invertido, após ser modificado.
// Entrada: vetor 'v', tamanho 'n', índice atual 'idx'.
// Caso geral: se a posição inicial comparada for menor que a posição final, fazer Swap.
void inv(int v[], int ini, int fim){
    if(ini < fim){
        int aux = v[ini];
        v[ini] = v[fim];
        v[fim] = aux;
        inv(v, ini+1, fim-1);
    }
}

// Por Malloc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Protótipo das funções.
void imprimirVet(int [], int, int);
void vet(int [], int, int);
void rvet(int [], int, int);
int sum(int [], int, int);
int mult(int [], int, int);
int min(int [], int, int, int);
void inv(int [], int, int);

int main() {
    char s[1001];
    int *v = NULL;
    int tam = 0, num = 0, flag = 0;
    scanf("%[^\n]", s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '-' || (s[i] >= '0' && s[i] <= '9')) {
            if ((i == 0 || s[i-1] == ' ') && s[i] != ' ') {
                tam++;
            }
        }
    }
    v = malloc(tam * sizeof(int));
    int idx = 0;
    num = 0; flag = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '-') {
            flag = -1;
        } else if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
            if (flag == 0) flag = 1;
        } else if (s[i] == ' ') {
            if (flag != 0) {
                v[idx++] = num * flag;
                num = 0; flag = 0;
            }
        }
    }
    if (flag != 0) v[idx++] = num * flag;
    printf("vet : ");
    vet(v, tam, 0);
    printf("rvet: ");
    rvet(v, tam, tam-1);
    printf("sum : %d\n", sum(v, tam, 0));
    printf("mult: %d\n", mult(v, tam, 0));
    printf("min : %d\n", min(v, tam, 1, 0));
    printf("inv : ");
    inv(v, 0, tam-1);
    imprimirVet(v, tam, 0);
    free(v);
    return 0;
}

// Função para imprimir o vetor.
// Entrada: vetor 'v', tamanho 'n' do vetor, posição atual 'i'.
// Saída: void (vetor impresso).
// Caso base: se i == n, retornar; se i == 0, começar a impressão.
// Caso geral: imprimir o elemento do vetor na posição atual.
void imprimirVet(int v[], int n, int i){
    if(i == 0){
        printf("[ ");
    }
    printf("%d ", v[i]);
    if(i == n-1){
        printf("]\n");
        return;
    }
    imprimirVet(v, n, i+1);
}

// Função para imprimir o vetor original.
// Entrada: vetor 'v', tamanho 'n' e índice atual 'idx'.
// Saída: void (vetor original).
void vet(int v[], int n, int idx) {
    if(idx == 0) {
        printf("[ ");
    }
    if(idx == n) {
        printf("]\n");
        return;
    }
    printf("%d ", v[idx]);
    vet(v, n, idx + 1);
}

// Função para imprimir o vetor invertido.
// Entrada: vetor 'v', tamanho 'n' e índice do último elemento 'idx'.
// Saída: void (vetor invertido).
void rvet(int v[], int n, int idx) {
    if(idx == n-1){
        printf("[ ");
    }
    printf("%d ", v[idx]);
    if(idx == 0){
        printf("]\n");
        return;
    }
    rvet(v, n, idx-1);
}

// Função da soma de todos os termos do vetor.
// Entrada: vetor 'v', tamanho 'n', índice atual 'idx'.
// Se o tamanho for igual a 0, retorne 0. Caso contrário, retorne a função sum().
int sum(int v[], int n, int idx){
    if(idx == n || n == 0){
        return 0;
    }
    return v[idx] + sum(v, n, idx+1);
}

// Função de multiplicação de todos os termos do vetor.
// Entrada: vetor 'v', tamanho 'n', índice atual 'idx'.
// Se o tamanho for igual a 0, retorne 0. Caso contrário, retorne a função mult().
int mult(int v[], int n, int idx){
    if(n == 0 || idx == n){
        return 1;
    }
    return v[idx] * mult(v, n, idx+1);
}

// Função para encontrar o menor elemento do vetor.
// Entrada: vetor 'v', tamanho 'n', índice atual 'idx' e menor valor atual 'min'.
// Saída: menor elemento do vetor 'v'.
// Se o vetor tiver tamanho igual a 1, retorne o elemento no índice 0.
// Se idx apontar para o índice 0, min é igual a idx.
// Se o vetor tiver tamanho maior que 1, retorne a função min().
int min(int v[], int n, int idx, int idxMin){
    if(n == 0){
        return 0;
    }
    if(idx == n){
        return v[idxMin];
    }
    if(v[idx] < v[idxMin]){
        idxMin = idx;
    }
    return min(v, n, idx+1, idxMin);
}

// Função de inversão do vetor efetivamente invertido, após ser modificado.
// Entrada: vetor 'v', tamanho 'n', índice atual 'idx'.
// Caso geral: se a posição inicial comparada for menor que a posição final, fazer Swap.
void inv(int v[], int ini, int fim){
    if(ini < fim){
        int aux = v[ini];
        v[ini] = v[fim];
        v[fim] = aux;
        inv(v, ini+1, fim-1);
    }
}