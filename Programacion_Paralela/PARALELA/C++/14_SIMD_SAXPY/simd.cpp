// EJERCICIO 14

// Hecho por: Gustavo Rodriguez Calzada
// El dia: 4 de Mayo del 2021

// Se compila como: g++ -o svvCompilado svv.cpp -fopenmp
// Se ejecuta como: ./svvCompilado 10 uno.txt dos.txt


#include <iostream>
#include <fstream>
#include <stdio.h>
#include <omp.h>
#include "fun_omp.h"
#include <stdlib.h>

using namespace std;

#pragma omp declare simd
    void saxpy(float *X, float *Y, int i, float SA)
        {
            Y[i] = SA+X[i]+Y[i];
        }

float *X, *Y, SA;

int main(int argc, char *argv[]){
    char* nomA1, *nomA2;
    int size = atoi(argv[1]);
    nomA1 = argv[2];
    nomA2 = argv[3];
    float SA = 2.5;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            X = crea_vec(size);
            X = lee_vec(nomA1,size);
        }
        #pragma omp section
        {
            Y = crea_vec(size);
            Y = lee_vec(nomA2,size);
        }
    }
    #pragma omp simd
    for(int i=0; i<size; i++){
        saxpy(X,Y,i,SA);
    }
    muestra_vec(Y,size);
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
