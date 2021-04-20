// EJERCICIO 4

// Se compila con: g++ -o vvCompilado vv.cpp -fopenmp

// Se ejecuta con: ./vvCompilado uno.txt dos.txt 10

// El resultado es un escalar

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <omp.h>
#include <math.h>

using namespace std;

float* lee_vec(char*, int);
float* crea_vec(int);
int muestra_vec(float*, int);

int main(int argc, char* argv[]){

// DECLARANDO VARIABLES
    int i,n;
    float prod = 0.0;
    float *v1, *v2;

// OCUPANDO 4 HILOS
    omp_set_num_threads(4);

//DECLARAR n, QUE ES PARA EL TAMAÑO DE LOS VECTORES
    n = atoi(argv[3]);

// ASIGNAR MEMORIA PARA LOS VECTORES
    v1 = new float[n];
    v2 = new float[n];

// ASIGNARLE UN ESPACIO Y LEER ARCHIVO
    v1 = lee_vec(argv[1],n);
    v2 = lee_vec(argv[2],n);

// HACE QUE CADA HILO SE SUME Y EL RESULTADO SE QUEDE EN prod
    #pragma omp parallel for reduction(+:prod)
    
        for (i=0; i<n; i++){
            prod += v1[i]*v2[i];
        }

// VECTOR 1
    muestra_vec(v1,n);       

// VECTOR 2    
    muestra_vec(v2,n);

// SE IMPRIME EL RESULTADO
    cout<<"El producto es igual a: "<<prod<<endl;
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
}