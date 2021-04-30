#include <iostream>
#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include "func_omp.h"


using namespace std;

int vxv (float *a, float*b, int n){
    int i;
    #pragma omp simd reduction(+:c)
        for(i=0; i<n; i++){
            c = b[i]*a[i];
        }
return c;
}

int main(int argc, char *argv[]){
float *a, *b, *c;


cout<<"Resultado: "<<c<<endl;
return 0;
}