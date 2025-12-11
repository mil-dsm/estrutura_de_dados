#include <stdio.h>

#define CHECK_ZERO(x, y) \
    if ((y) == 0) { \
        printf("*** Attempt to divide by zero on line %d of file %s ***\n", __LINE__, __FILE__); \
    } else { \
        printf("Result: %.2f\n", (x) / (y)); \
    }

int main() {
    // Macros predefinidas
    printf("=== INFORMACOES GERAIS ===\n");
    printf("Linha atual: %d\n", __LINE__);
    printf("Nome do arquivo: %s\n", __FILE__);
    printf("Data: %s\n", __DATE__);
    printf("Horario: %s\n", __TIME__);
    printf("Padrao C (__STDC__): %d\n\n", __STDC__);

    float x, y;
    printf("Digite x/y:\nx = ");
    scanf("%f", &x);
    printf("y = ");
    scanf("%f", &y);

    CHECK_ZERO(x, y);

    return 0;
}
