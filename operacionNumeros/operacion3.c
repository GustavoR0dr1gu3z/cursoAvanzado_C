#include <stdio.h>

int main(){

    int num1 = 0, num2 = 0, num3 = 0, num4 = 0, suma = 0;
    float promedio;

    printf("Digite num1: ");
    scanf("%i", &num1);
    printf("Digite num1: ");
    scanf("%i", &num2);
    printf("Digite num1: ");
    scanf("%i", &num3);
    printf("Digite num1: ");
    scanf("%i", &num4);

    suma = num1 + num2 + num3 + num4;
    promedio = (suma)/4;

    printf("\n\nLa suma es: %i", suma);
    printf("\nEl promedio es: %.2f", promedio);
    printf("\n");

    return 0;
}