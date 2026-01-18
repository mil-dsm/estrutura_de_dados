#include <stdio.h>

int recorrencia(char S[], int n, char c){
    if(n == 0){
        return 0;
    }
    if(S[n-1] == c){
        return 1 + recorrencia(S, n-1, c);
    }
    return recorrencia(S, n-1, c);
}

int main(){
    int n;
    scanf("%d", &n);
    char S[n+1], c;
    scanf(" %[^\n] %c", S, &c);
    printf("%d\n", recorrencia(S, n, c));
}