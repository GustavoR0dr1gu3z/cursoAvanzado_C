// EJERCICIO 18

// Hecho por: Gustavo Rodriguez Calzada
// El dia: 4 de Mayo del 2021

// SE EJECUTA COMO: g++ -o piCompilado pi.cpp -fopenmp
// SE COMPILA COMO: ./piCompilado 1000000


#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <cmath>

using namespace std;


float ppi(int n, int A, int B){
    float pi = 0.0;
    float subIntervalo = 0.0;
    subIntervalo = ((B-A)/n);
    float h = subIntervalo/2;

    float fa = 4/(1+pow(A,2));
    float fb = 4/(1+pow(B,2));

    float xk = A;
    // 4/(1+x'2)
    #pragma omp parallel for reduction(+:xk)
        for(int i=0; i<n; i+= subIntervalo){
            xk = xk+i;
        }
    pi = h * ( (fa) + (2*xk) + (fb) );
    return pi;
}

int main(int argc, int argv[]){
    // n DEL POLIGONO
    int n;
    // LADOS A Y B
    float A = 0;
    float B = 1;

    // SE ASIGNAN LOS VALORES PARA LA FORMULA
    n = argv[1];

    // SE MANDA A LLAMAR LA FUNCION DE PI
    float cpi =0;
    cpi = ppi(n,A,B);

    // SE MUESTRA EL RESULTADO
    cout<<"PI calculado: "<<cpi<<endl;
return 0;
}