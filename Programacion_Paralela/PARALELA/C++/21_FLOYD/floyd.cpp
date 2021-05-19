/* EJERCICIO 21 -> ALGORITMO DE FLOYD

Hecho por: Gustavo Rodriguez Calzada
El dia: 17 de Abril del 2021


Se compila como: g++ -o gaussCompilado gauss.cpp -fopenmp
Se ejecuta como: ./gaussCompilado 30 31
*/

#include <iostream>
#include <omp.h>
#include <stdlib.h>
#include <fstream>
#include "func_omp.h"

using namespace std;

float *X, **AU, **W;
int ren, col, m;

int main(int argc, char* argv[]){
    int i,k,hi;
    char matA[10000] = "matB.txt";
    ren = atoi(argv[1]);
    col = atoi(argv[2]);

// SECTIONS: LEER Y MOSTRAR MATRIZ
    //#pragma omp parallel private(tid)
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            AU = crea_mat(ren,col);
            AU = lee_mat(matA,ren,col);
        }
    }
    //omp_set_num_threads(10);
    //muestra_mat(AU,ren,col);
    //X = gauss_f(AU, ren, col);
    cout<<endl<<endl;
    cout<<"El resultado es: "<<endl;
    muestra_vec(X,ren);
    return 0;
}
