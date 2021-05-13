// EJERCICIO 8

// Hecho por: Gustavo Rodriguez Calzada
// El dia: 26 de Abril del 2021

// ------------------- PRIMERA FORMA --------------------
// Se compila como: g++ -o vecxvec_omp_21Compilado vecxvec_omp_21.cpp -fopenmp
// Se ejecuta como: ./vecxvec_omp_21Compilado 10000 uno.txt dos.txt

// ------------------- SEGUNDA FORMA ---------------------
// El arcivo MAKE se compila: make -f MAKEFILE_VxV
// Se ejecuta como: ./vxv_omp 10000 uno.txt dos.txt

#include <iostream>
#include <omp.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "func_omp.h"


using namespace std;

float *V, *W, Prod = 0.0;

int main(int argc, char *argv[]){

    int n, i;
    char *nomA1;
    char *nomA2;

    n = atoi(argv[1]);

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
    #pragma omp for reduction(+:Prod)
        for (i=0; i<n; i++){
            Prod += V[i]*W[i];
        }
// FIN DEL PROGRAMA
cout<<"\nProducto: "<<Prod<<endl;
return 0;
}


float* crea_vec(int m){
    float *W;
    W = new float [m];      
    return W;
}


int muestra_vec(float *M, int m){
    int j;
    for(j=0; j<m; j++){
        cout<<M[j]<<" ";
    }
    cout<<endl;
    return 0;
}

float* lee_vec(char *nom_arch, int m){
    float *W;
    W = new float[m];
    cout<<"Leyendo el vector "<<endl;
    fstream fd;
    fd.open(nom_arch, ios::in);
    
    while(!fd.eof()){
        int i;
        for(i=0; i<m; i++){
            fd>>W[i];
        }            
    }
    fd.close();
    cout<<"Vector Leido "<<endl;
    return W;
}
