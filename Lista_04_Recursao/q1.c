#include <stdio.h>

void inverter(int A[], int ini, int fim){
    if(ini >= fim){   // <-- condição corrigida
        return;
    }
    int aux = A[ini];
    A[ini] = A[fim];
    A[fim] = aux;
    inverter(A, ini+1, fim-1);
}

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    inverter(A, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d", A[i]);
        if(i<n-1){
            printf(" ");
        } else {
            printf("\n");
        }
    }
}