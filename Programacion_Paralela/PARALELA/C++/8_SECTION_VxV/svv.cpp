#include <iostream>
#include <omp.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "fun_omp.h"

using namespace std;

float *V, *W, Prod = 0.0;

int main(int argc, char *argv[]){

    int n, j;
    char *nomA1;
    char *nomA2;

    n = atoi(agrv[1]);

    nomA1 = argv[2];
    nomA2 = argv[3];

    V = crea_vec(n);
    W = crea_vec(n);

// SECTIONS: LEER Y MOSTRAR VECTOR
    #pragma omp parallel private(tid)
        #pragma omp sections
        {
            #pragma omp section
            {
                V = lee_vec(nomA1,n);
                muestra_vec(V,n);
            }
            #pragma omp section 
            {
                W = lee_vec(nomA2,n);
                muestra_vec(W,n);
            }
        }
// OMP: PRODUCTO
    #pragma omp for reduction(+:Prod)
        for (i=0; i<n; i++){
            Prod += V[i]*W[i];
        }
// FIN DEL PROGRAMA
cout<<"\nProducto: "<<Prod<<endl;
return 0;
}