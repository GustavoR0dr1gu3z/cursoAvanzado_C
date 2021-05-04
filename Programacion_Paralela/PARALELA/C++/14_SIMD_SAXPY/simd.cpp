#include <iostream>
#include <fstream>
#include <stdio.h>
#include <omp.h>

using namespace std;

#pragma omp declare simd

    void saxpy(float *X, float *Y, int i, float SA)
        {
            Y[i] = SA+X[i]+Y[i];
        }

    float *X, *Y, SA;

int main(int argc, char *argv){



}        