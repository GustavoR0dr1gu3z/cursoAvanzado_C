/*Se debe desarrollar un programa que pida el ingreso del 
precio de un articulo y la cantidad que lleva el cliente. Mostrar lo que 
debe abonar el comprador. 
Definir una variable float para el precio del articulo*/

#include <stdio.h>

int main(){

    int cantidad, pTotal;
    float precio;

    printf("Precio del articulo: ");
    scanf("%f", &precio);

    printf("Cantidad de productos a comprar: ");
    scanf("%i",  &cantidad);

    pTotal = precio * cantidad;

    printf("\n\nEl precio total es: %i \n",pTotal);


    return 0;
}
