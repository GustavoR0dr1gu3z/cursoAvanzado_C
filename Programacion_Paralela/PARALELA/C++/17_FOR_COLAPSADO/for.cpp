// EJERCICIO 17

// Hecho por: Gustavo Rodriguez Calzada
// El dia: 7 de Mayo del 2021


// SE COMPILA COMO: g++ -o forCompilado for.cpp -fopenmp
// SE EJECUTA COMO: 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <omp.h>
#include "fun_omp.h"

using namespace std;

float **A;

int main(int argc, char* argv[]){
    int i, j, m, n;
    float s;
    s = 2.5;
    m = 2;
    n = 5;
    omp_set_nested(true);
    A = crea_mat(m,n);
    #pragma omp for 
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                A[n*i+j] = i*j+1;
            }
        }

return 0;
}


//CREA ESPACIO PARA LA MATRIZ, EN FORMA VECTORIZADA
float** crea_mat(int m, int n){
    int j;
    float** M;
    M = new float*[m];
    for(j=0; j<m; j++){
        M[j] = new float[n];
    }
return M;
}

// LLENA EL ESPACIO PARA LA MATRIZ
float** lee_mat(char *nom_arch, int m, int n){
    int i, j;
    float **M;
    M = crea_mat(m, n);
    fstream fd1;
    fd1.open(nom_arch, ios::in);
    while(!fd1.eof()){
        int i, j;
        for (i=0; i<m; i++){
            for (j=0; j<n; j++){
                fd1>>M[i][j];
            }
        }
    }
    fd1.close();
    cout<<"Matriz Leida"<<endl;
return M;
}



// MUESTRA LA MATRIZ
int muestra_mat(float** M, int m, int n){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            cout<<M[i][j]<<", ";
        }
        cout<<endl;
    }
return 0;
}

