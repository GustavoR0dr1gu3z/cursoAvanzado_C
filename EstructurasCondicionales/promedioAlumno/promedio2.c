#include <stdio.h>

int main(){

    int num1, num2, num3;
    float promedio;

    printf("Digite una nota: ");
    scanf("%d", &num1);
    printf("Digite otra nota: ");
    scanf("%d", &num2);
    printf("Digite otraa nota: ");
    scanf("%d", &num3);

    promedio = ((num1+num2+num3)/3);

    if(promedio >= 7){
        printf("\n\nPromocionado\n");
    }else if(promedio >= 4 && promedio <7){
        printf("\n\nRegular\n");
    }else{
        printf("\n\nReprobado\n");
    }


    return 0;
}