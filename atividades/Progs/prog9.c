#include <stdio.h>

void copyString(char *, char *);

int main(){
    char s1[] = "Pao com mortadela";
    char s2[21];
    copyString(s1, s2);
    printf("%s\n", s2);
}

void copyString(char *copiarDaqui, char *colarAqui){
    while(*copiarDaqui != '\0'){
        *colarAqui = *copiarDaqui;
        copiarDaqui++;
        colarAqui++;
    }
    *colarAqui = '\0';
}