// EJERCICIO 18

// Hecho por: Gustavo Rodriguez Calzada
// El dia: 11 de Mayo del 2021

// SE EJECUTA COMO: g++ -o piCompilado pi.cpp -fopenmp 
// SE COMPILA COMO: ./piCompilado 1000


#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <cmath>

using namespace std;


float ppi(int n, float A, float B){
    float pi = 0.0;
    //float subIntervalo = ((B-A)/float(n));
    //float h = subIntervalo/float(2);
    //float ba = B-A;
    //float fa = 4.0/(1.0+0.0); // 4/(1+0̣^2)
    //float fb = 4.0/(1.0+1.0); // 4/(1+1^2)
    int i;
    float xi;
    float sumaR = 0.0; 
    // 4/(1+x'2)
    #pragma omp parallel for reduction(+:sumaR)
        for (i=0; i<n; i++){
            xi = (1.0/n)*(i+0.5);
            sumaR += 4.0 / (1.0+xi*xi);
        }
    pi = sumaR * (1.0 / n);
    return pi;
}

int main(int argc, char *argv[]){
    // n DEL POLIGONO
    int n;
    // LADOS A Y B
    float A = 0.0;
    float B = 1.0;

    // SE ASIGNAN LOS VALORES PARA LA FORMULA
    n = atoi(argv[1]);

    // SE MANDA A LLAMAR LA FUNCION DE PI
    float cpi = 0.0;
    cpi = ppi(n,A,B);

    // SE MUESTRA EL RESULTADO
    cout<<"PI calculado: "<<cpi<<endl;
return 0;
}