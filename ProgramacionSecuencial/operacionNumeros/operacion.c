#include <stdio.h>


int main(){

    int num1, num2, suma, producto;

    printf("Ingrese un numero entero positivo: ");
    scanf("%i",&num1);

    printf("Ingrese otro numero entero positivo: ");
    scanf("%i",&num2);

    suma = num1 + num2;
    producto = num1 * num2;

    printf("La suma es: %i",suma);
    printf("\nLa multiplicacion es: %i",producto);
    printf("\n");
    
    getchar();
    return 0;
}
