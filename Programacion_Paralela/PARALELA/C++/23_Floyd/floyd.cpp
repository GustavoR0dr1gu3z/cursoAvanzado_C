#include <iostream>
#include <fstream>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "func_omp.h"

using namespace std;

float **lee_mat2(char*, int, int);
float **M, **A;
char *nomArc;

int main(int argc, char*argv[]){
    int i,j,k,tam;
    float t1, t2, m;

    tam = atoi(argv[1]);
    nomArc = argv[2];
    M = crea_mat(tam, tam);
    A = crea_mat(tam, tam);
    A = lee_mat(nomArc,tam , tam);    
    M = A;

    muestra_mat(A, tam, tam);
    omp_set_num_threads(4);

    t1 = omp_get_wtime();


    for (k=0; k<tam; k++){
        for(i=0; i<tam; i++){
            for(j=0; j<tam; j++){
                M[i][j] = min(A[i][j], (A[i][k],A[k][j]) );
                A[i][j] = M[i][j];
            }
        }
    }

    t2 = omp_get_wtime();
    cout<<"Tiempo de ejecución en paralelo: "<<t2-t1<<endl<<endl;

    muestra_mat(A, tam, tam);
    return 0;
}


float** lee_mat2(char* nomArc, int m, int n){
    int i, j;
    float **MM, numm, M;

    MM = crea_mat(m,n);
    fstream fd1;
    cout.precision(15);
    fd1.open (nomArc, ios::in);
    
}