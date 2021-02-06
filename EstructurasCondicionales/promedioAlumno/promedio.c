#include <stdio.h>

int main(){

    int num1, num2, num3;
    float promedio = 0.0;

    printf("Digite calificacion 1: ");
    scanf("%d", &num1);
    printf("Digite calificacion 2: ");
    scanf("%d", &num2);
    printf("Digite calificacion 3: ");
    scanf("%d", &num3);

    promedio=((num1+num2+num3)/3);

    if(promedio>=6){
        printf("\nAprobado\n\n");
    }else{
        printf("\nReprobado\n\n");
    }


    return 0;
}