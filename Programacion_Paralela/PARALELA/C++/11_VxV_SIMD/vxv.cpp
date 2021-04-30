// Se compila como: g++ -o vxvCompilado vxv.cpp -fopenmp 
// Se ejecuta como: ./vxvCompilado 10 uno.txt dos.txt 


#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <omp.h>
#include <fstream>
#include "fun_omp.h"


using namespace std;

int vxv (float *a, float*b, float c, int n){
    int i;
    #pragma omp simd reduction(+:c)
        for(i=0; i<n; i++){
            c += b[i]*a[i];
        }
return c;
}

int main(int argc, char *argv[]){
    float *a, *b, c;
    int n;
    char *nomArc, *nomArc2;
    n= atoi(argv[1]);
    nomArc = argv[2];
    nomArc2 = argv[3];

    #pragma omp sections
    {
        #pragma omp section
        {
            a = crea_vec(n);
            a = lee_vec(nomArc,n);
        }
        #pragma omp section
        {
            b = crea_vec(n);
            b = lee_vec(nomArc,n);
        }
    }
omp_set_num_threads(2);
vxv(a,b,c,n);
cout<<"Resultado: "<<c<<endl;
return 0;
}

float *lee_vec(char* nom_arch, int m){
    int i;
    float *VV;
// SE CREA EL VECTOR CON UN TAMAÑO ASIGNADO
    VV = crea_vec(m);

    fstream fd2;
// ABRE EL ARCHIVO Y SE GUARDA EM VV
    fd2.open(nom_arch, ios::in);
    while(!fd2.eof()){
        int i,j;
        for(i=0; i<m; i++){
            fd2>>VV[i];
        }
    }
    fd2.close();
    cout<<"Vector Leído"<<endl;
    return VV;
}

float* crea_vec(int m){
    float *VV;
    VV = new float[m];
    return VV;
}

int muestra_vec(float* M ,int n){
    int i;
    for (i=0; i<n; i++){
        cout<<M[i]<<endl;
    }
    return 0;
}