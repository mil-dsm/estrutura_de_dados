#include <stdio.h>

int numMin(int A[], int n, int min){
    if(n == 1){
        return min;
    }
    if(A[n-1] <= min){
        min = A[n-1];
    }
    return numMin(A, n-1, min);
}

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    printf("%d\n", numMin(A, n, A[n-1]));
}