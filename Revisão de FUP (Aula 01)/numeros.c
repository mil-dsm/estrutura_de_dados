/*#include <stdio.h>

int main(){
    int v[10], i = 0, j;
    while(1){
        scanf("%d", &v[i]);
        for(j = 0; j < i; j++) {
            if(v[i] == v[j]){
                printf("Número já digitado, digite outro número.\n");
                break;
            }
        }
        if(j == i)
            i++;
        if(i == 10)
            break;
    }
    printf("[ ");
    for(i = 0; i < 10; i++)
        printf("%d ", v[i]);
    printf("]\n");
    return 0;
}*/

#include <stdio.h>

int verif(int [], int, int);

int main(){
    int v[10], i = 0, j;
    while(1){
        scanf("%d", &v[i]);
        if(verif(v, v[i], i))
            printf("Número já digitado, digite outro número.\n");
        else
            i++;
        if(i == 10)
            break;
    }
    printf("[ ");
    for(i = 0; i < 10; i++)
        printf("%d ", v[i]);
    printf("]\n");
    return 0;
}

int verif(int v[], int n, int i){
    for(int j = 0; j < i; j++)
        if(v[i] == v[j])
            return 1;
    return 0;
}