#include <iostream>
#include <omp.h>
#include <stdlib.h>
#include "func_omp.h"

using namespace std;

float **A, *B;

int main(int argc, char* argv[]){
    int i,k,hi;
    int ren = atoi(argv[1]);
    int col = atoi(argv[2]);
    char matA[10000] = "matA.txt";
    char *vec  = "vec.txt";

// SECTIONS: LEER Y MOSTRAR MATRIZ
    //#pragma omp parallel private(tid)
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            A = crea_mat(ren, col);
            A = lee_mat(matA, ren, col);
        }
        #pragma omp section 
        {        
            B = crea_vec(ren);
            B = lee_vec(vec, ren);
        }
    }



}
//-----------------------------MATRIZ------------------------

float** crea_mat(int m, int n){
    int j;
    float** M;
    M = new float*[m];

    for(j=0; j<m; j++){
        M[j] = new float[n];
    }
return M;
}

float** lee_mat(char *nom_arch, int m, int n){
    int i, j;
    float **M;
    M = crea_mat(m,n);
    fstream fd1;
    fd1.open(nom_arch, ios::in);
    while(!fd1.eof()){
        int i, j;
        for(i=0;i<m;i++){
            for (j=0;j<n;j++){
                fd1>>M[i][j];
            }
            
        }
    }
    fd1.close();
    cout<<"Matriz Leida"<<endl;
    return M;
}


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

//--------------------------VECTOR----------------------------

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


float* crea_vect(int m){
    float *W;
    W = new float [m];      
    return W;
}

int muestra_vec(float* M ,int n){
    int i;
    for (i=0; i<n; i++){
        cout<<M[i]<<endl;
    }
    return 0;
}