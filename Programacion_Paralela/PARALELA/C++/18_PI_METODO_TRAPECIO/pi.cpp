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


float ppi(int max, int A, int B){

}

int main(int argc, int argv[]){
    // max DEL POLIGONO
    int max;
    // LADOS A Y B
    float A;
    float B;

    // SE ASIGNAN LOS VALORES PARA LA FORMULA
    max = argv[1];
    A = argv[2];
    B = argv[3];

    // SE MANDA A LLAMAR LA FUNCION DE PI
    float cpi =0;
    cpi = ppi(max,A,B);

    // SE MUESTRA EL RESULTADO
    cout<<"PI calculado: "<<cpi<<endl;
return 0;
}