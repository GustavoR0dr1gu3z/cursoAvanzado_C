// EJERCICIO 19: PROGRAMA CIRCUITO EN C++

// Hecho por: Gustavo Rodriguez Calzada
// El dia: 17 de Mayo del 2021

// SE EJECUTA COMO: g++ -o circuitoCompilado circuito.cpp -fopenmp 
// SE COMPILA COMO: ./circuitoCompilado 1000


#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

using namespace std;

void check_circuit(int);

int main(int argc, char *argv[]){
    int i, id, p, solucion, n_in,n_comb;
    
    // Numero de entradas del circuito
    n_in = atoi(argv[1]);
    n_comb = atoi(argv[2]);

    solucion = 0;
    #pragma omp parallel for reduction(+:solucion)
        for(i=0; i<n_comb; i++){
            check_circuit(i); 
        }
    cout<<"Procesador "
}