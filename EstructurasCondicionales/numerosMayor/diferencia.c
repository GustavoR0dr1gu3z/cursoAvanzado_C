#include <stdio.h>

int main(){

    int num1=0, num2=0, suma, diferencia, producto;
    float division;

    printf("Digite un numero: ");
    scanf("%d", &num1);
    printf("Digite otro numero: ");
    scanf("%d", &num2);

    if(num1>num2){
        suma = num1+num2;
        diferencia = num1-num2;

        printf("\nLa suma es: %d",suma);
        printf("\nLa resta es: %d\n",diferencia);
    }else if(num1<num2){
        producto = num1*num2;
        division = num1/num2;
        printf("\nEl producto es es: %d",producto);
        printf("\nLa division es: %.2f\n",division);
    }else{
        printf("\nNumeros Iguales\n\n");
    }

    return 0;
}