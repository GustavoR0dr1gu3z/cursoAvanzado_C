#include <stdio.h>

int main(){

    int num=0;

    printf("Digite un numero positivo de hasta 3 CIFRAS!!!: ");
    scanf("%d",&num);

    if(num>=0 && num<10){
        printf("\nNumero de una cifra\n\n");
    }else if(num>=10 && num<100){
        printf("\nNumero de dos cifras\n\n");
    }else if(num>=100 && num<1000){
        printf("\nNumero de tres cifras\n\n");
    }else if(num>=1000){
        printf("\nNumero de cifras es MAYOR al acordado\n\n");
    }else{
        printf("\nNumero negativo\n\n");
    }

    return 0;
}