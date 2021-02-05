#include <stdio.h>


int main(){

    float sueldo = 0.0;

    printf("Digite su sueldo: ");
    scanf("%f", &sueldo);

    if (sueldo > 3000){
        printf("Debes abonar impuestos\n");        
    }else{
        printf("No debes abonar xd\n");
    }


    return 0;
}