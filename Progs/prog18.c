#include <stdio.h>

void converte_tempo(int segundos, int *hor, int *min, int *seg){
    *hor = segundos / 3600;
    int r = segundos % 3600;
    *min = r / 60;
    *seg = r % 60;
}

int main(){
   int tempo, h, m, s;
   scanf("%d", &tempo);
   converte_tempo(tempo, &h, &m, &s);
   printf("%d:%d:%d\n", h, m, s);
}