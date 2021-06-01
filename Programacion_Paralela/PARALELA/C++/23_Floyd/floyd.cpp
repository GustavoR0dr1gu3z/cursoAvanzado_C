/* EJERCICIO 23 -> ALGORITMO DE FLOYD

Es un algoritmo de análisis sobre grafos para encontrar el camino mínimo en grafos dirigidos 


Hecho por: Gustavo Rodriguez Calzada
El dia: 17 de Abril del 2021


Se compila como: g++ -o floydCompilado floyd.cpp -fopenmp
Se ejecuta como: ./floydCompilado 8 mat2.txt
*/



#include <iostream>
#include <fstream>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "func_omp.h"

using namespace std;
// Se define min para conocer el minimo numero
#define min(a,b) ((a<b)?a:b)

// Se crea esta funcion para la matriz con los infinitos
float **lee_mat2(char*, int, int);
float **M, **A;
// Variable para el archivo
char *nomArc;

int main(int argc, char*argv[]){
    int i,j,k,tam;
    float t1, t2, m;
    // Variables para tamaño y nombre del archivo
    tam = atoi(argv[1]);
    nomArc = argv[2];
    // Asignación de 4 hilos
    omp_set_num_threads(4);

    // Conocer el tiempo para la ejecución en paralelo
    t1 = omp_get_wtime();

    // Sections, para crear matrices y leerlas
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            M = crea_mat(tam, tam);
            M = lee_mat(nomArc,tam , tam);
        }
        #pragma omp section
        {
            A = crea_mat(tam, tam);
            A = lee_mat(nomArc,tam , tam); 
        }
    }

    // Se muestra la matriz originla
    muestra_mat(A, tam, tam);    

    // Se hace para los 3 for en paralelo
    #pragma omp parallel for collapse(3)   
        for (k=0; k<tam; k++){
            for(i=0; i<tam; i++){
                for(j=0; j<tam; j++){
                    M[i][j] = min(A[i][j], (A[i][k]+A[k][j]) );
                    A[i][j] = M[i][j];
                }
            }
        }

    t2 = omp_get_wtime();
    cout<<"Tiempo de ejecución en paralelo: "<<t2-t1<<endl<<endl;
    cout<<"\n\nRESULTADO: "<<endl;
    muestra_mat(A, tam, tam);
    return 0;
}

//--------------------------------------------------------------MATRIZ----------------------------------------------------------------

float** lee_mat2(char* nomArc, int m, int n){
    int i, j;
    float **MM, num, M;

    MM = crea_mat(m,n);
    fstream fd1;
    cout.precision(15);
    fd1.open (nomArc, ios::in);
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            fd1>>num;
            if(num==M){
                num=10000;
                MM[i][j] = num;
            }
            else{
                MM[i][j] = num;
            }
        }
    }
    fd1.close();
    cout<<"Matriz Leída"<<endl;
    return MM;
}

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
