#include <iostream>
#include <omp.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "fun_omp.h"

using namespace std;

float *V, *W, Prod = 0.0;

int main(int argc, char *argv[]){

    int n, j;
    char *nomA1;
    char *nomA2;

    n = atoi(agrv[1]);

    nomA1 = argv[2];
    nomA2 = argv[3];

    V = crea_vec(n);
    W = crea_vec(n);

    

}