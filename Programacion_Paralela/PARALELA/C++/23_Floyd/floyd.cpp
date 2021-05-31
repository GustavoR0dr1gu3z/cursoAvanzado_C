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
    M = crea_mat(tam,tam);
    A = crea_mat(tam,tam);
    A = lee_mat(nomArc,tam,tam);    
    M = A;
}