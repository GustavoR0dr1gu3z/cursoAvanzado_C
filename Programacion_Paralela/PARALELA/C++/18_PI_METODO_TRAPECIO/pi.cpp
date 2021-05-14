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