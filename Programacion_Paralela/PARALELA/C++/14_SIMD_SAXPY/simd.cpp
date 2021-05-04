#include <iostream>
#include <fstream>
#include <stdio.h>
#include <omp.h>
#include "fun_omp.h"

using namespace std;

#pragma omp declare simd
    void saxpy(float *X, float *Y, int i, float SA)
        {
            Y[i] = SA+X[i]+Y[i];
        }

    float *X, *Y, SA;

int main(int argc, char *argv){
    char *nomA1, *nomA2;
    int size = atoi(argv[1]);
    nv1 = argv[2];
    nv2 = argv[3];
    float SA = 2.5;




}        