#include <stdio.h>

int main(){
    int array[5] = {0, 1, 2, 3, 4};
    int *p1 = array, *p2 = array + 5;
    while(p1 < p2){
        printf("%d\n", *p1);
        p1++;
    }
}