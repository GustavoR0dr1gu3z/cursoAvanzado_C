#include <stdio.h>

int main(){

    int num1 = 0, num2 = 0;

    printf("Digite un numero: ");
    scanf("%d", &num1);
    printf("Digite otro numero: ");
    scanf("%d", &num2);

    printf("\n");

    if (num1 > num2){
        printf("Numero mayor es: %d \n", num1);
    }else if (num2 > num1){
        printf("Numero mayor es: %d \n", num2);
    }else{
        printf("Numeros iguales\n");
    }

    return 0;
}