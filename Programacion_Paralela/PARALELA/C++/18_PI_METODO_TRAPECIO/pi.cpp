// EJERCICIO 18

// Hecho por: Gustavo Rodriguez Calzada
// El dia: 4 de Mayo del 2021

// SE EJECUTA COMO: g++ -o piCompilado pi.cpp -fopenmp
// SE COMPILA COMO: ./piCompilado 1000000


#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

using namespace std;

float pi(int lados){
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