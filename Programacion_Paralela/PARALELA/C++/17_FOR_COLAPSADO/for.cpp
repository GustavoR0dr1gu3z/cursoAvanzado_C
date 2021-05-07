// EJERCICIO 16

// Hecho por: Gustavo Rodriguez Calzada
// El dia: 4 de Mayo del 2021


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <omp.h>
#include "fun_omp.h"

using namespace std;

float **A;

int main(int argc, char* argv[]){
    int i, j, m, n;
    m = 2;
    n = 5;
    omp_set_nested(True);
    A = crea_mat(m,2);
    #pragma omp for 
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                A[m*i+j]
            }
        }

return 0;
}