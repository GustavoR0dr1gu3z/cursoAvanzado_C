#include <stdio.h>
#include <ncurses.h>

int main(){

    int lado, perimetro;

    printf("PERIMETRO DE UN CUADRADO\n\n\n");

    printf("Digite un lado de la figura: ");
    scanf("%i",&lado);

    perimetro = lado*4;

    printf("Perimetro de la figura es: %i",perimetro);
    printf("\n\n");
    return 0;
}