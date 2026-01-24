#include <stdio.h>

int main(){
    char op;
    float n1, n2;
    printf("Digite a operacao desejada (+, -, *, /): ");
    scanf(" %c", &op);
    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);
    printf("Digite o segundo numero: ");
    scanf("%f", &n2);
    printf("Resultado: ");
    if(op == '+')
        printf("%.2f\n", n1 + n2);
    else if(op == '-')
        printf("%.2f\n", n1 - n2);
    else if(op == '*')
        printf("%.2f\n", n1 * n2);
    else
        printf("%.2f\n", n1 / n2);
    return 0;
}