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


float ppi(int n, float A, float B){
    float pi = 0.0;
    float subIntervalo = ((B-A)/n);
    float h = subIntervalo/2;
    float ba = B-A;
    float fa = 4/(1+0); // 4/(1+0̣^2)
    float fb = 4/(1+1); // 4/(1+1^2)
    int i;
    float xk = 0.0;
    // 4/(1+x'2)
    #pragma omp parallel for reduction(+:xk)
        //for(i=1; i<n-1; i+=int(subIntervalo)){
            //xk += (4/1+i);
        //}
        //pi = (ba)*((fa+fb)/(2));
        for(i=1; i<n-1; i++){
            xk += ( 4 / 1 + pow((A + i*subIntervalo),2) );
        }
    //pi = h * ( (fa) + (2*xk) + (fb) );
    pi = subIntervalo * ( ( (fa+fb)/(2) ) + (xk)  );
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