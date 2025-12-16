#include <stdio.h>

void MAX(int, int [][], int *, int *, int *);

int main(){
    int n, k, l, c;
    scanf("%d", &n);
    int m[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &v[i][j]);
    MAX(n, m, &k, &l, &c);
    printf("O maximo da matriz eh %d na linha %d e coluna %d\n", k, l, c);
}

void MAX(int n, int m[][], int *k, int *l, int *c){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(m[i][j] > *k){
                *k = m[i][j];
                *l = i;
                *c = j;
            }
}