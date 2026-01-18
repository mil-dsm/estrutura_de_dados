#include <stdio.h>

typedef struct{
    int hora, minuto, segundo;
} Horario;

int main(){
    Horario agora, *depois;
    depois = &agora;
    printf("%0d:%0d:%0d\n", agora.hora, agora.minuto, agora.segundo); // Lixo de memoria
    depois->hora = 20;
    depois->minuto = 80;
    depois->segundo = 20;
    printf("%0d:%0d:%0d\n", depois->hora, depois->minuto, depois->segundo);

    int soma = 100;
    Horario antes;
    printf("%0d:%0d:%0d\n", antes.hora, antes.minuto, antes.segundo); // Lixo de memoria
    antes.hora = soma + depois->segundo;
    antes.minuto = agora.hora + depois->minuto;
    antes.segundo = depois->minuto + depois->segundo;
    printf("%0d:%0d:%0d\n", antes.hora, antes.minuto, antes.segundo);
}