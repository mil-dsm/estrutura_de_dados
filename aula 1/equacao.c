#include <stdio.h>
#include <math.h>

int main(){
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double delta = b*b - 4*a*c;
    if(delta < 0)
        printf("A equação não têm raízes reais.\n");
    else if(delta == 0)
        printf("Raiz: %.2f\n", (-1)*b/(2*a));
    else{
        double x1 = ((-1)*b + sqrt(delta)) / (2*a);
        double x2 = ((-1)*b - sqrt(delta)) / (2*a);
        printf("Raizes: %.2f e %.2f\n", x1, x2);
    }
    return 0;
}