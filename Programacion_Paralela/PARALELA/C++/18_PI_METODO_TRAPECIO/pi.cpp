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


float ppi(int lados){
    // RADIO
    float r = 1; 

    // PERIMETROS DE LOS POLIGONOS
    float A;
    float B;

    // CARGA DE LOS PERIMETROS
    A=4*sqrt(2)*r;  
    B=8*r;
    
    // LADOS DEL POLIGONO
    float m=4;     
    float pii;
    #pragma omp parallel
        while (m*2<=lados) {        
            B=2*A*B/(A+B);   
            A=sqrt(A*B);        
            m=m*2;
            pii=(  A/2/r + B/2/r  )/2;
        }        
    return pii;
}

int main(int argc, char*argv[]){
    // LADOS DEL POLIGONO
    int lados;
    lados = atoi(argv[1]);
    
    // SE MANDA A LLAMAR LA FUNCION DE PI
    float cpi =0;
    cpi = ppi(lados);

    // SE MUESTRA EL RESULTADO
    cout<<"PI calculado: "<<cpi<<endl;
return 0;
}