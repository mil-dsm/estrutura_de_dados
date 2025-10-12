#include <stdio.h>

int verif(int [], int);

int main(){
    int n, i;
    scanf("%d", &n);
    int v[n];
    for(i=0; i<n; i++)
        scanf("%d", &v[i]);
    printf("%d", verif(v, n));
}

int verif(int v[], int n){
    int i, j;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(v[i]>v[j]){
                return 0;
            }
        }
    }
    return 1;
}