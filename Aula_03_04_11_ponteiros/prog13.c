#include <stdio.h>

void modifyArray(int []);

int main(){
    int v[] = {1, 4, 2, 3, 7, 8, 13, 21};
    modifyArray(v);
    int size = sizeof(v) / sizeod(v[0]);
    for(int i=0; i<size; i++){
        printf("v[%d] = %d\n", i, v[i]);
    }
}

// p contem um endereco de memoria passando como parametro
void modifyArray(int p[]){
    *p = 5;
}