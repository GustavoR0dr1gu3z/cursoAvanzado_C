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

    A=4*sqrt(2)*r;  // Cargo los perímetros de un CUADRADO inscrito (A) y circunscrito (B). Estos valores pueden ser fácilmente
    B=8*r;          // obtenidos con el teorema de pitagoras, no pi required.
    
    float m=4;     // Este es el número de lados de los polígonos con los que estamos trabajando.


    float dpi = 0.0,t;
    #pragma omp parallel for simd private(t) reduction(+:dpi)
        for (int i=0; i<lados;i++){
            t = (float)((i+0.5)/lados);
            dpi += 4.0/(1.0+t*t);
        }    
            dpi /= lados;        
        return dpi;
}

int main(int argc, char*argv[]){
    int lados;
    lados = atoi(argv[1]);
    float cpi =0;
    cpi = pi(lados);
    cout<<"PI calculado: "<<cpi<<endl;
return 0;
}