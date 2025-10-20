/*Atividade: Implemente o MDC de forma recursiva
Objetivo
Escreva uma função que calcule o MDC (Máximo Divisor Comum) de dois números inteiros positivos usando recursão.

O MDC de dois números é o maior número inteiro que divide ambos sem deixar resto.

Algoritmo de Euclides
Se A = 0, então MDC(A, B) = B.
Se B = 0, então MDC(A, B) = A.
Caso contrário, calcule o resto da divisão de A por B: R = A % B.
O MDC de A e B é o mesmo que o MDC de B e R: MDC(A, B) = MDC(B, R).
Repita recursivamente até que um dos números seja zero.
Exemplo com Diagrama Visual da Recursão
Calcular MDC(192, 276):

MDC(192, 276)
MDC(276 % 192 = 84, 192) → MDC(192, 84)
MDC(192 % 84 = 24, 84) → MDC(84, 24)
MDC(84 % 24 = 12, 24) → MDC(24, 12)
MDC(24 % 12 = 0, 12) → 12 ✅
Como podemos ver, a função desce até encontrar o caso base (um número igual a zero) e depois sobe retornando o resultado final.

Exemplos de Entrada e Saída
Entrada	Saída
3, 5	1
6, 9	3
50, 15	5
270, 192	6
192, 276	12
*/

#include <stdio.h>

int mdc(int, int);

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", mdc(a, b));
}

// Função para calcular o MDC de 'a' e 'b'.
// Entrada: dois números inteiros positivos 'a' e 'b'.
// Saída: o MDC de 'a' e 'b'.
// Se 'a' for igual a 0, retorne 'b'.
// Se 'b' for igual a 0, retorne 'a'.
// Caso contrário, retorne a função mdc() com os parâmetros 'b' e 'a%b'.
int mdc(int a, int b){
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }
    return mdc(b, a % b);
}