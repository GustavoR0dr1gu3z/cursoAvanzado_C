// EJERCICIO 5

// Se compila con: g++ -o mxvCompilado mxv.cpp -fopenmp

// Se ejecuta con: ./mxvCompilado mat.txt vec.txt 10 10

#include<omp.h>
#include <fstream>
#include<cstdio>
#include<iostream>
#include <math.h>
#include <cstdlib>


using namespace std;

float* lee_vec(char*, int);;
float* crea_vec(int);
float** lee_mat(char*, int, int);
float** crea_mat(int, int);
int muestra_mat(float**, int, int);
int muestra_vec(float*, int);

float **A, *V, *W, *mat;

int main(int argc,char * argv[])
{   
    float prod = 0.0;
    int ren = atoi(argv[1]);
    int col = atoi(argv[2]);
    char nomMat[9] = "mat.txt";
    char nomVect[9] = "vec.txt";

// OCUPANDO 4 HILOS
    omp_set_num_threads(4);

    //USANDO LAS FUNCIONES, PARA ASIGNAR ESPACIO 
//MATRIZ
    A = crea_mat(ren,col);
    A = lee_mat(nomMat, ren, col);
//VECTOR
    V = crea_vec(col);
    V = lee_vec(nomVect, ren);
    W = crea_vec(col);

//IMPRIMIR MATRIZ Y VECTOR
    cout<<endl;
    cout<<"----------MATRIZ----------"<<endl;
    muestra_mat(A, ren, col);
    cout<<endl;
    cout<<"------VECTOR COLUMNA------"<<endl;
    muestra_vec(V,ren);
    cout<<endl;

    #pragma omp parallel for reduction(+:prod)
        for(int i=0; i<ren; i++){
            //producto[i] += mat[i]*V[i];
            cout<<"Hola";
        }
    
    cout<<"----Resultado----"<<endl;
    muestra_vec(W,ren);
    return 0;
}    

// ------------------------------VECTOR----------------------

// RESERVANDO MEMORIA PARA EL VECTOR
float* crea_vec(int m){
    float* W;
    W = new float[m];
return W;
}

// LEYENDO EL VECTOR
float* lee_vec(char *nom_arch, int m){
    int i;
    float* W;
    cout<<"Leyendo Vector"<<endl;
    W = crea_vec(m);
    fstream fd2;
    fd2.open(nom_arch, ios::in);
    while(!fd2.eof()){
        int i, j;
            for(i=0; i<m; i++){
                fd2>>W[i];
            }
    }
    fd2.close();
    cout<<"Vector Leido"<<endl;
return W;
}

// IMPRIME EL VECTOR
int muestra_vec(float *M, int n){
    int j;
    for(j=0; j<n; j++){
        cout<<M[j]<<"\n";
    }
    cout<<endl;
return 0;
}

// ------------------------------MATRIZ-------------------------

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

