#include <stdio.h>

// Função fibonacci tem o propósito de retornar o número da posição n
// Caso base: se i for igual a n, retorna o resultado anterior
// Caso geraç: retorna o fibonacci do índice i + 1
// Entrada: posição n, posoção anterior ant, posição posterior pos e índice i
int fibonacci(int n, int ant, int pos, int i){
    if(i == n){
        return ant;
    }
    return fibonacci(n, pos, ant + pos, i+1);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", fibonacci(n, 0, 1, 0));
}