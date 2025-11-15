#include <stdio.h>

void mm(int [], int, int *, int *);

int main(){
    int vetor[10] = {42, 7, 13, 29, 5, 88, 16, 3, 50, 21};
    int min, max;
    mm(vetor, 10, &min, &max);
    printf("Minimo: %d\nMax: %d\n", min, max);
}

void mm(int A[], int n, int *min, int *max){
    *min = A[0];
    *max = A[0];
    for(int i = 0; i < n; i++){
        if(A[i] > *max){
            *max = A[i];
        }
        if(A[i] < *min){
            *min = A[i];
        }
    }
}