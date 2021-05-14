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


float pi(int lados){
    // RADIO
    float r = 1; 

    // PERIMETROS DE LOS POLIGONOS
    float A;
    float B;

    // CARGA DE LOS PERIMETROS
    A=4*sqrt(2)*r;  
    B=8*r;
    
    float m=4;     // Este es el número de lados de los polígonos con los que estamos trabajando.

    float dpi = 0.0,t;
    #pragma omp parallel for simd private(t) reduction(+:dpi)
        while (m*2<=lados) {  // BUCLE. Si el número de lados del polígono a generar supera el número impuesto por usuario, para.
        
        B=2*A*B/(A+B);      // Calculo de los perímetros con el doble de lados. A cada vuelta los valores de A y B se sobreeescriben.
        A=sqrt(A*B);
        
        m=m*2;              // El número de lados se duplica en cada vuelta.
        
    }
}

int main(int argc, char*argv[]){
    int lados;
    lados = atoi(argv[1]);
    float cpi =0;
    cpi = pi(lados);
    cout<<"PI calculado: "<<cpi<<endl;
return 0;
}