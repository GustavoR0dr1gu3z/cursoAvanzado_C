#include <stdio.h>


int main(){

    int n1,n2,n3;

    printf("Digite un numero: ");
    scanf("%d",&n1);
    printf("Digite otro numero: ");
    scanf("%d",&n2);
    printf("Digite otro numero: ");
    scanf("%d",&n3);    


    if(n1>n2 && n1 >n3){
        printf("\n\nEl numero mayor es : %d \n",n1);
    }else if(n2>n1 && n2>n3){
        printf("\n\nEl numero mayor es : %d \n",n2);
    }else if(n3>n1 && n3>n2){
        printf("\n\nEl numero mayor es : %d \n",n3);
    }else{
        printf("\n\nNumeros iguales\n");
    }


    return 0;
}