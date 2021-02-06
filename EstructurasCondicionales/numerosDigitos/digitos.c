#include <stdio.h>

int main(){

    int num=0;

    printf("Digite un Numero: ");
    scanf("%d",&num);

    if(num>=0){
        if(num<=9){
            printf("\n\nEl Numero es de 1 Digito\n");
        }else if(num>9 && num<=99){
            printf("\n\nEl Numero es de 2 Digitos\n");
        }else if(num>99 && num<=999){
            printf("\n\nEl Numero es de 3 Digitos\n");
        }else{
            printf("\n\nEl Numero es de mas de 4 Digitos\n");
        }
    }else{
        printf("\n\nEs numero negativo, favor de digitar uno positivo\n");
    }


    return 0;
}