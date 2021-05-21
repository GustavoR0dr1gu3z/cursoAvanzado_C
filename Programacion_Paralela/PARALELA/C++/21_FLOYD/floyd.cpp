/* EJERCICIO 21 -> ALGORITMO DE FLOYD

es un algoritmo de análisis sobre grafos para encontrar el camino mínimo en grafos dirigidos 


Hecho por: Gustavo Rodriguez Calzada
El dia: 17 de Abril del 2021


Se compila como: g++ -o floydCompilado floyd.cpp -fopenmp
Se ejecuta como: ./floydCompilado 10 10
*/

#include <iostream>
#include <omp.h>
#include <stdlib.h>
#include <fstream>
#include "func_omp.h"

using namespace std;

float *X, **AU, **W, **mat1, **sol;
int tam, vertices;

int main(int argc, char* argv[]){
    int i,k,hi;
    char matA[10000] = "matBB.txt";
    tam = atoi(argv[1]);
    vertices = atoi(argv[2]);

// CREACION DE LA MATRIZ
    mat1 = lee_mat(matA,tam,tam);
    sol = floyd_f(mat1,vertices);

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

    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            if(i==j){
                M[i][j] = 0;
            }
        }
    }

    cout<<"Matriz Leida"<<endl;
    muestra_mat(M,m,n);
    cout<<endl;
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


float ** floyd_f(float **M, int m){
    int k,ii,jj;

    #pragma omp parallel for collapse(3)    
        for(k=0; k<m;k++){
            for(ii=0; ii<m; ii++){
                for(jj=0; jj<m; jj++){
                    if( M[ii][k] + M[k][jj] < M[ii][jj] )
                    {
                        M[ii][jj] = M[ii][k] + M[k][jj];
                        //P[ii][jj] = k;
                    }
                }
            }
        }
    

    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i==j){
                M[i][j] = 0;
            }
        }
    }

    cout<<"Matriz RESUELTA"<<endl;
    muestra_mat(M,m,m);
    cout<<endl;
    cout<<endl;

    cout<<"RUTA: "<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<m;j++){
            cout<<"De: "<<i<<" a: "<<j<<" : ";
            cout<<M[i][j] <<endl;
        }
    }

return M;
}
