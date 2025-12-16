#include <stdio.h>

char *strcpy(char *destino, char *origem){
    int i = 0;
    do{
        *(destino + i) = *(origem + i);
    }while (origem[i++] != '\0');
    return destino;
}

int main(){
    char s1[] = "Bolo de choco";
    char s2[] = "milho";
    strcpy(s1 + 8, s2);
    printf("%s\n", s1);
}