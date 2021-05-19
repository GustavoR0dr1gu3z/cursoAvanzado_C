/* EJERCICIO 20 -> GAUSS 

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
    X = gauss_f(AU, ren, col);
    cout<<endl<<endl;
    cout<<"El resultado es: "<<endl;
    muestra_vec(X,ren);
    return 0;
}


//--------------------------------------------------------------MATRIZ----------------------------------------------------------------
//----------------------------CREA LA MATRIZ----------
float** crea_mat(int m, int n){
    int j;
    float **M;
    M = new float*[m]; // Arreglo a M de m elementos
    for(j=0; j<m; j++){
        M[j] = new float[n]; // Le asignamos a ese arreglo las columnas
    }
    return M;
}

//-----------------------------LEE LA MATRIZ------------
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
    muestra_mat(M,m,n);
    return M;
}

//--------------------GUARDA LA MATRIZ------------------

int guarda_mat(float** A, int r, int c, char* nom_arch){
    int i, j;
    fstream fd1;
    fd1.open(nom_arch, ios::out);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            fd1<<A[i][j]<<" ";
        }
        cout<<endl;
    }
fd1.close();
cout<<"Matriz Guardada"<<endl;
return 0;
}

//-------------------------MUESTRA LA MATRIZ------------
int muestra_mat(float **M, int m, int n){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//--------------------------------------------------------------VECTOR----------------------------------------------------------------
//-------------------------CREA EL VECTOR---------------

float* crea_vec(int m){
    float *W;
    W = new float [m];    	  
    return W;
}

//-------------------------MUESTRA EL VECTOR-------------
int muestra_vec(float* M ,int n){
    int i;
    for (i=0; i<n; i++){
        cout<<M[i]<<endl;
    }
    return 0;
}

float * gauss_f(float **A, int r, int c){
    int i, j, m, n; // Indices
    float *Y, S = 0; // vector aux
    Y = crea_vec(r);    
    Y[r-1] = A[r-1][c-1] / A[r-1][r-1]; //Ultima variable
    // Ultimo renglon / ultima columna
    m = r-1;
    n = c-1;
    cout<<endl;
    // For de la variable 8 hasta 0, si n = 10
    #pragma omp parallel for reduction(+:S)
        for(i=m-1; i>=0; i--){
            // Acumulamos estos productos
            //S = 0;
            // Columnas j
            for (j=m+1; j>= i+1; j--){
                // Acumulamos el producto de A*Y
                S = S+(A[i][j]*Y[j]); //Ultima, penultima, etc
            }
            // Calcular Y para el anterrenglon renglon
            Y[i] = (A[i][c-1]-S)/A[i][i];
        }


return Y;
}

