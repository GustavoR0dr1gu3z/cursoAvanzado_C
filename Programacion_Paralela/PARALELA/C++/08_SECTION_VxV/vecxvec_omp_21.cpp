/* EJERCICIO 8 -> VECTOR POR VECTOR CON OPENMP 

Hecho por: Gustavo Rodriguez Calzada
El dia: 20 de Abril del 2021


------------------- PRIMERA FORMA --------------------
El arcivo MAKE se compila: make -f MAKEFILE_VxV
Se ejecuta como: ./vxv_omp 10000 uno.txt dos.txt


------------------- SEGUNDA FORMA ---------------------
Se compila como: g++ -o vecxvec_omp_21Compilado vecxvec_omp_21.cpp func_omp.o -fopenmp
Se ejecuta como: ./vecxvec_omp_21Compilado 10000 uno.txt dos.txt
*/

#include <iostream>
#include <omp.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "func_omp.h"


using namespace std;

float *V, *W, Prod = 0.0;

int main(int argc, char *argv[]){

// DECLARANDO VARIABLES
    int n, i;
    char *nomA1;
    char *nomA2;

// DECLARAR n, QUE ES PARA EL TAMAÑO DE LOS VECTORES
    n = atoi(argv[1]);

// DECLARA nomA1, nomA2 QUE ES PARA ASIGNARLE LOS ARCHIVOS TXT
    nomA1 = argv[2];
    nomA2 = argv[3];



// SECTIONS: LEER Y MOSTRAR VECTOR
    //#pragma omp parallel private(tid)
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            V = crea_vec(n);
            V = lee_vec(nomA1,n);
            //muestra_vec(V,n);
        }
        #pragma omp section 
        {
            W = crea_vec(n);
            W = lee_vec(nomA2,n);
            //muestra_vec(W,n);
        }
    }

// OMP: PRODUCTO
// HACE QUE CADA HILO SE SUME Y EL RESULTADO SE QUEDE EN Prod
    #pragma omp for reduction(+:Prod)
        for (i=0; i<n; i++){
            Prod += V[i]*W[i];
        }
// FIN DEL PROGRAMA
cout<<"\nProducto: "<<Prod<<endl;
return 0;
}

