#include <stdio.h>

int main(){

    int ladoCuadrado = 0;
    int baseRectangulo = 0;
    int alturaRectangulo = 0;
    int baseTriangulo = 0;
    int alturaTriangulo = 0;
    int areaCuadrado = 0;
    int areaRectangulo = 0;
    float areaTriangulo = 0.0;

    printf("--------AREA DE FIGURAS---------\n\n\n");

    printf("Digite el lado del cuadrado: ");
    scanf("%i",&ladoCuadrado);

    printf("\n\nDigite la base del Rectangulo: ");
    scanf("%i",&baseRectangulo);

    printf("\nDigite la altura del Rectangulo: ");
    scanf("%i",&alturaRectangulo);

    printf("\n\nDigite la base del Triangulo: ");
    scanf("%i",&baseTriangulo);

    printf("\nDigite la altura del Triangulo: ");
    scanf("%i",&alturaTriangulo);


    areaCuadrado = ladoCuadrado*ladoCuadrado;
    areaRectangulo = baseRectangulo*alturaRectangulo;
    areaTriangulo = (baseTriangulo*alturaTriangulo)/2;

    printf("\n\n\n");
    
    printf("El Area del Cuadrado es: %i", areaCuadrado);
    printf("\nEl Area del Rectangulo es: %i", areaRectangulo);
    printf("\nEl Area del Triangulo es: %.2f\n", areaTriangulo);

    getchar();
    return 0;
}