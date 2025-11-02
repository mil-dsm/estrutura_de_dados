#include <stdio.h>

void SelectionSort(int A[], int n){
    for(int i=0; i<n-1; i++){
        int indexMin = i;
        for(int j=i+1; j<n; j++){
            if(A[j]<A[indexMin]){
                indexMin = j;
            }
        }
        int aux = A[i];
        A[i] = A[indexMin];
        A[indexMin] = aux;
    }
}

void SelectionSort_recursivo(int A[], int n, int i){
    if(i == n-1){
        return;
    }
    int indexMin = i;
    for(int j=i+1; j<n; j++){
        if(A[j]<A[indexMin]){
            indexMin = j;
        }
    }
    int aux = A[i];
    A[i] = A[indexMin];
    A[indexMin] = aux;
    SelectionSort_recursivo(A, n, i+1);
}

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d", &n);
    }
    SelectionSort(A, n);
    SelectionSort_recursivo(A, n, 0);
    for(int i=0; i<n; i++){
        printf("%d", A[i]);
        if(i == n-1){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
}