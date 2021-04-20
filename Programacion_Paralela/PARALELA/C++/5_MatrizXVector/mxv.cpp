// EJERCICIO 5

// Se compila con: g++ -o mxvCompilado vv.cpp -fopenmp

// Se ejecuta con: ./mxvCompilado mat.txt vec.txt 10


#include<pthread.h>
#include<omp.h>
#include<cstdio>
#include<iostream>
//g++ MatrizxvectorOmp.cpp -fopenmp
using namespace std;

float* lee_vec(char*, int);;
float* crea_vec(int);
float** lee_mat(char*, int, int);
float** crea_mat(int, int);
int muestra_mat(float**, int, int);
int muestra_vec(float*, int);

float **A, *V;

int main(int argc,char * argv[])
{   
    
    int ren = atoi(argv[1]);
    int col = atoi(argv[2]);
    char nomMat[9] = "mat.txt";
    char nomVect[9] = "vec.txt";

// OCUPANDO 4 HILOS
    omp_set_num_threads(4);

    //USANDO LAS FUNCIONES
//MATRIZ
    A = crea_mat(ren,col);
    A = lee_mat(nomMat, ren, col);
//VECTOR
    V = crea_vec(col);
    V = lee_vec(nomVect, ren);

//IMPRIMIR MATRIZ Y VECTOR
    cout<<endl;
    cout<<"----------MATRIZ----------"<<endl;
    muestra_mat(A, ren, col);
    cout<<endl;
    cout<<"------VECTOR COLUMNA------"<<endl;
    muestra_vec(V,ren);
    cout<<endl;


    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            Matriz2[i]=1;
            Matriz[i][j]=1;
        }
    }
    int b=0;
    int c[100][100];
    #pragma omp parallel for reduction(+:b)
    for(int i = 0 ; i <100; i++)
	    {   
            for(int j=0;j<100;j++){
                c[i][j]=Matriz[i][j]*Matriz2[i];
                b+=c[i][j];
            }                   
        }
    
    cout<<"resultado: "<<b;  
    return 0;
}    


