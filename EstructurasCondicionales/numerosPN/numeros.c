#include <stdio.h>


int main(){

    int n1;

    printf("Digite un numero: ");
    scanf("%d",&n1);

    if(n1<0){
        printf("\nNumero negativo\n\n");
    }else if(n1>0){
        printf("\nNumero positivo\n\n");
    }else{
        printf("\nNumero nulo\n\n");
    }


    return 0;    
}