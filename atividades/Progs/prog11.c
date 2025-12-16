#include <stdio.h>

typedef struct{
    int *pHora, *pMinuto, *pSegundo;
} Horario;

int main(){
    Horario hoje;
    int hora = 200, minuto = 300, segundo = 400;
    hoje.pHora = &hora;
    hoje.pMinuto = &minuto;
    hoje.pSegundo = &segundo;
    printf("%1.d:%1.d:%1.d\n", *hoje.pHora, *hoje.pMinuto, *hoje.pSegundo);
    *hoje.pSegundo = 1000;
    printf("%1.d:%1.d:%1.d\n", *hoje.pHora, *hoje.pMinuto, *hoje.pSegundo);
}