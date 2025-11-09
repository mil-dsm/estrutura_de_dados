#include <stdio.h>

void printSize(int []);

int main(){
    int array[] = {1, 1, 2, 3, 5, 8, 13, 21};
    // Improme sizeof(int) * array size, 32!
    printf("%d\n", sizeof(array));
    printfSize(array); // array decai para um ponteiro
}

void printSize(int array[]){
    // array é tratada como um ponteiro
    printf("%ld\n", sizeof(array));
}