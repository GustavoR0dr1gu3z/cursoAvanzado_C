#include <stdio.h> 

int main(){

    int horasTrabajadas = 0;
    float costoHora = 18.5;
    float sueldo = 0.0;

    printf("Digite las horas trabajadas: ");
    scanf("%d",&horasTrabajadas);
    sueldo = costoHora*horasTrabajadas;
    printf("\n\nSu sueldo es: $%.2f \n",sueldo);
    getchar();
    return 0;
}